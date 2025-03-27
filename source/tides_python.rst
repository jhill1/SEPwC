Mini course: Tidal analysis in Python
======================================
.. index:: 
   pair: uptide; python

Tides are a fundamental part of a number of coastal processes. As sea levels rise, tides will change, 
and hence our flood risk, coastal geomorphology and ecological systems will also change as a consequence.

You can run the code below sequentially in Spyder/ipython or create a Jupyter notebook. 
Alternatively, save as a script and run from the command line.

Some modules you will need to install are *uptide* and *wget*

.. code-block:: bash
    :caption: |cli|

    pip install uptide
    pip install wget

.. code-block:: Python
    :caption: |python|

    # import the modules we need
    import pandas as pd
    import matplotlib.pyplot as plt
    import datetime
    import wget
    import os
    import numpy as np
    import uptide
    import pytz
    import math

Now we have out environment set up. We can create a couple of "helper" functions to make life easier later!

.. code-block:: Python
    :caption: |python|

    def read_and_process_data(filename):
        tide_data = pd.read_csv(filename, header=None)
        tide_data['Date'] = pd.to_datetime(dict(year=tide_data[0], month=tide_data[1], day=tide_data[2], hour=tide_data[3]))
        # col 0 is year, col 1 is month, col2 is day, col3 hour
        tide_data = tide_data.drop([0,1,2,3], axis = 1)
        tide_data = tide_data.rename(columns={4: "Tide"})
        tide_data = tide_data.set_index('Date')
        tide_data = tide_data.mask(tide_data['Tide'] < -300)

        return tide_data

    def extract_single_year_remove_mean(year, data):
        year_string_start = str(year)+"0101"
        year_string_end = str(year)+"1231"
        year_data = data.loc[year_string_start:year_string_end, ['Tide']]
        # remove mean to oscillate around zero
        mmm = np.mean(year_data['Tide'])
        year_data['Tide'] -= mmm

        return year_data

We are going to use data from the long term tidal record dataset held by the School of 
Ocean and Earth Science and Technology, University of Hawaii. Some of their tidal records 
go back over 100 years. We're going to download data for three locations in Australia: 
Freemantle, WA; Booby Island, QLD; and Fort Denison, NSW.

.. code-block:: Python
    :caption: |python|

    FortDenison_url = "https://uhslc.soest.hawaii.edu/data/csv/fast/hourly/h333.csv"
    BoobyIsland_url = "https://uhslc.soest.hawaii.edu/data/csv/fast/hourly/h336.csv"
    Freemantle_url = "https://uhslc.soest.hawaii.edu/data/csv/fast/hourly/h175.csv"
    urls = [FortDenison_url, BoobyIsland_url, Freemantle_url]

    # fetch our data and store
    for url in urls:
        file_name = os.path.basename(url) # get the full path to the file
        if os.path.exists(file_name):
            os.remove(file_name) # if exists, remove it directly
        file_name = wget.download(url, out=".")

We now have three csv files which should be stored in your current directory (whever you are
running this code from ).

.. code-block:: Python
    :caption: |python|

    # load and store as a pandas dataframe
    Fort_Denison = read_and_process_data("h333.csv")
    Booby_Island = read_and_process_data("h336.csv")
    Freemantle = read_and_process_data("h175.csv")

Now let's plot these, choosing an arbitrary year to plot (rather than the whole dataset!)

.. code-block:: Python
    :caption: |python|

    # Let's plot 1 years' worth of tidal data
    fig_summary=plt.figure()
    ax=fig_summary.add_subplot(111)
    fd = ax.plot(Fort_Denison['Tide'], color="blue", lw=1, label="Fort Denison")
    bi = ax.plot(Booby_Island['Tide'], color="orange", lw=1, label="Booby_Island")
    f = ax.plot(Freemantle['Tide'], color="red", lw=1, label="Freemantle")
    ax.set_xlabel("Date")
    ax.set_ylabel("Water height (mm)")
    ax.tick_params(axis='x', rotation=45)
    ax.legend()
    ax.set_xlim([datetime.date(2008, 1, 1), datetime.date(2008, 12, 31)])
    fig_summary.tight_layout()
    plt.show()


.. figure:: ../images/Figure_1_tides.png
    :alt: Line graphs of the tidal elevation of the three stations
    
    Plot of three tidal stations over an entire year.

The plot, though busy, already shows some interesting features. Booby Island has the highest tidal 
range and shows a clear annual signal. Freemantle has the smallest tidal range and seems fairly constant.

Tide gauges often record the water level so can pick up storms and are affected by even small winds 
blowing onshore for example. This means the data you see might not be "just tides", but also some 
aspect of weather, depending on how the data are processed. In addition, for long term records, 
the tide gauges will also record sea level rise. All heights are measured above a datum so you 
also have to be careful comparing raw data from one tide gauge to another.

Let's now look at one month in detail:

.. code-block:: Python
    :caption: |python|

    fig_june=plt.figure()
    ax=fig_june.add_subplot(111)
    fd = ax.plot(Fort_Denison['Tide'], color="blue", lw=1, label="Fort Denison")
    bi = ax.plot(Booby_Island['Tide'], color="orange", lw=1, label="Booby_Island")
    f = ax.plot(Freemantle['Tide'], color="red", lw=1, label="Freemantle")
    ax.set_xlabel("Date")
    ax.set_ylabel("Water height (mm)")
    ax.tick_params(axis='x', rotation=45)
    ax.legend()
    ax.set_xlim([datetime.date(2008, 6, 1), datetime.date(2008, 7, 1)])
    fig_june.tight_layout()
    plt.show()

.. figure:: ../images/Figure_2_tides.png
    :alt: Line graphs of the tidal elevation of the three stations for June
    
    Plot of three tidal stations over June.

We can now see more of the tidal signals. You may notice Freemantle shows fewer wiggles 
than the other two locations; this is because it is a diurnal tide: one tide per day. 
Fort Denison has a clear two tides per day; semi-diurnal. Booby Island normally has two 
tides per days, but some days, those two tides effectively blend into one (see around the 
17th June). This is a mixed diurnal-semi diurnal system.

All tidal signals are essentially a mix of multiple sine curves. We know what the frequency of
the external forcing is for tides (the rotation of the earth, the movement of the moon around
the earth, etc), which allows us to break up the signal into constituent parts: the tidal
constituents. These are often given labels such as M2, S2, K1, O1, etc. Each one has a 
particular frequency as given in the table below.

.. list-table:: Tidal periods
   :header-rows: 1

   * - Decription
     - Darwin symbol
     - Period (h)
     - Speed (°/h)
   * - Principal lunar semidiurnal
     - M2
     - 12.4206012
     - 28.9841042
   * - Principal solar semidiurnal
     - S2
     - 12
     - 30
   * - Lunar diurnal
     - K1
     - 23.9344721
     - 15.0410686
   * - Lunar diurnal
     - O1
     - 25.8193387
     - 13.9430356
   * - Lunisolar semidiurnal
     - K2
     - 11.96723606
     - 30.0821373
   * - Larger lunar elliptic semidiurnal
     - N2
     - 12.6583475
     - 28.4397295

There are over 400 different contiuents, but 60-ish is considered enough for accurate 
tidal predictions, but fewer still can be used for useful tidal predictions. The tidal 
signal can then be reconstructed by summing sine curves of the correct frequency and 
amplitude (and phase) to recreate and then predict the tides. At each location the amplitude 
and phase will be different.

Let's add up some sine curves to make something like the tide signals above.

Sine Curves
------------

Sine cuves can be generalised to the formula:

.. math::

    y = Asin(Bx + C) + D

:math:`A` is the amplitude, :math:`2 pi / B` is the period, :math:`C` is the phase shift and :math:`D` is the 
vertical shift. We know the period (from the table above) for each constiuent and :math:`D` is not releant here, 
so we have two parameters to find: :math:`A` and :math:`C`. 

.. code-block:: Python
    :caption: |python|

    A_m2 = 0.53
    B_m2 = 12.4206012 # hours
    C_m2 = 0

    times = np.arange(0,24*14,0.5) # 14 days in hours
    sin_curve = A_m2*np.sin(2*math.pi/B_m2*times + C_m2)

    plt.plot(times,sin_curve)
    plt.xlabel("Hours")
    plt.ylabel("Water height (m)")
    plt.show()

.. figure:: ../images/Figure_3_tides.png
    :alt: Line graph of a single sine curve

    Plot of a single sine curve


That's the M2 curve; let's now add S2:

.. code-block:: Python
    :caption: |python|

    A_s2 = 0.23
    B_s2 = 12
    C_s2 = math.pi/2

    sin_curve = A_m2*np.sin(2*math.pi/B_m2*times + C_m2) + \
                A_s2*np.sin(2*math.pi/B_s2*times + C_s2)
    plt.plot(times,sin_curve)
    plt.xlabel("Hours")
    plt.ylabel("Water height (m)")
    plt.show()

.. figure:: ../images/Figure_4_tides.png
    :alt: Line graph of two combined sine curves

    Plot of two combined sine curves to make spring-neap cycle

The above shows what in effect is spring and neap tide using just two components, with different 
amplitudes and phases (and frequencies/periods).

We can extract constituents from a tidal signal like those plotted above using least squares 
regression analysis to work out what the tidal constiuents are. Let's do that now to pull 
out the common consituents from our tidal data.

.. code-block:: Python
    :caption: |python|

    # let's first pull out a single year's worth of data
    # and remove the mean value so the tides oscillate across zero
    FD_2008 = extract_single_year_remove_mean(2008, Fort_Denison)
    BI_2008 = extract_single_year_remove_mean(2008, Booby_Island)
    F_2008 = extract_single_year_remove_mean(2008, Freemantle)

    # We can use the module uptide to work out the tidal constiuents
    # More on uptide: https://github.com/stephankramer/uptide
    import uptide
    
    # we create a Tides object with a list of the consituents we want.
    tide = uptide.Tides(['M2'])

    # We then set out start time. All data must then be in second since this time
    tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
    
    # so let's swap our dates for seconds since midnight 1/1/2008.
    # Note the 1e9 (the int64 seconds epoch in numpy is multiplied by this for some reason)
    seconds_since = (FD_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0).timestamp()
    
    # We then send the elevation data (our tides) and time in seconds to uptide
    # and do the harmonic analysis
    amp,pha = uptide.harmonic_analysis(tide, FD_2008['Tide'].to_numpy()/1000, seconds_since)

    # uptide returns the amplitudes as a list (in the order of the constiuents listed above) and the phases (in radians)
    print(amp, pha)

The above numbers are the tidal amplitude for the M2 constiuent at Fort Denison (0.5013 m) and the phase (5.366 radians).
We can look up what the actual numbers are for Fort Denison (exercise for the reader!). 
However, we've forgotten something: *timezones*!

We also need to account for the timezone of the data. The phase is measured relative to 
UTC/GMT. We therefore need to tell the analysis the time data is in the Sydney timezone.

.. code-block:: Python
    :caption: |python|

    tz = pytz.timezone("Australia/Sydney")
    tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
    seconds_since = (FD_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()

    amp,pha = uptide.harmonic_analysis(tide, FD_2008['Tide'].to_numpy()/1000, seconds_since)
    print(amp,pha)

.. admonition:: Practical exercise

   **Extract the M2 component from Booby Island and Freemantle**

    Write code to extract the M2 amplitude and phase for the Freementle
    and Booby Island tidal data. Hint; remember the timezones!

.. admonition:: Solution
   :class: toggle

   .. code-block:: Python
      :caption: |python|

      tz = pytz.timezone("Australia/Lindeman")
      tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
      seconds_since = (BI_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()

      amp,pha = uptide.harmonic_analysis(tide, BI_2008['Tide'].to_numpy()/1000, seconds_since)
      print(amp,pha)

      tz = pytz.timezone("Australia/Perth")
      tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
      seconds_since = (F_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()

      amp,pha = uptide.harmonic_analysis(tide, F_2008['Tide'].to_numpy()/1000, seconds_since)
      print(amp,pha)

What happens when we want multiple constiuents? The first thing we need to consider is how long our 
data record is. Consituents that have a period/frequency that is close together need a longer 
dataset to be able to seperate them out. We can use something called the Rayleigh Critereon 
to work out how long a record we need.

.. code-block:: Python
    :caption: |python|

    constituents  = ['M2', 'S2', 'N2', 'K2', 'O1', 'P1', 'Q1', 'M4']
    print(uptide.select_constituents(constituents,15*24*60*60)) # This is 15 days in seconds

What we get back is that we can't resolve the N2, K2 and Q1 from the list with 15 days worth of data.
What if we had 30 days?

.. code-block:: Python
    :caption: |python|

    constituents  = ['M2', 'S2', 'N2', 'K2', 'O1', 'P1', 'Q1', 'M4']
    print(uptide.select_constituents(constituents,30*24*60*60))

Nope! K2 is still not able to be resolved from 30 days worth of data. How many days would we need?

.. code-block:: Python
    :caption: |python|

    tide = uptide.Tides(constituents)
    print(tide.get_minimum_Rayleigh_period()/86400.)

82.6 days worth of data to be able to work out the constituents listed above. So with our year of data we should be fine!

.. code-block:: Python
    :caption: |python|

    tz = pytz.timezone("Australia/Sydney")
    tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
    seconds_since = (FD_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()

    amp,pha = uptide.harmonic_analysis(tide, FD_2008['Tide'].to_numpy()/1000, seconds_since)
    print(amp, pha)

At Fort Denison our amplitudes and phases are:

 - M2: 0.503 m and 4.182 radians
 - S2: 0.125 m and 4.599 radians
 - N2: 0.115 m and 3.93 radians
 - K2: 0.036 m and 4.27 radians
 - O1: 0.097 m and 1.42 radians
 - P1: 0.043 m and 1.99 radians
 - Q1: 0.020 m and 1.016 radians
 - M4: 0.003 m and 2.09 radians

We could plot those using sine curves. However, ``uptide`` also has functionality to 
give us a total tidal signal from the amplitudes and phases.

.. code-block:: Python
    :caption: |python|

    t = np.arange(0, 365*24*3600, 1800) # 1 year in 1800 second intervals
    eta = tide.from_amplitude_phase(amp, pha, t)
    fig_summary=plt.figure()
    ax=fig_summary.add_subplot(111)
    # note we use seconds since as t (for the theoretical plot) is also in seconds
    fd = ax.plot(seconds_since/86400, FD_2008['Tide']/1000, color="blue", lw=1, label="Fort Denison")
    theoretical = ax.plot(t/86400, eta, color="orange", lw=1, label="Theoretical")
    ax.set_xlabel("Days")
    ax.set_ylabel("Water height (m)")
    ax.tick_params(axis='x', rotation=45)
    # uncomment line below and rerun to see a zoom in
    #ax.set_xlim([14, 44]) # only plot 30 days worth
    ax.legend()
    fig_summary.tight_layout()
    plt.show()

.. admonition:: Practical exercise

   **Extract all components and plot for Booby Island and Freemantle**

   Do the same for Booby Island and Freemantle.

.. admonition:: Solution
   :class: toggle

   .. code-block:: Python
     :caption: |python|

     tz = pytz.timezone("Australia/Lindeman")
     tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
     seconds_since = (BI_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()
     amp_bi,pha_bi = uptide.harmonic_analysis(tide, BI_2008['Tide'].to_numpy()/1000, seconds_since)
     tz = pytz.timezone("Australia/Perth")
     tide.set_initial_time(datetime.datetime(2008,1,1,0,0,0))
     seconds_since = (F_2008.index.astype('int64').to_numpy()/1e9) - datetime.datetime(2008,1,1,0,0,0,tzinfo=tz).timestamp()
     amp_f,pha_f = uptide.harmonic_analysis(tide, F_2008['Tide'].to_numpy()/1000, seconds_since)
     t = np.arange(0, 365*24*3600, 1800) # 1 year in 1800 second intervals
     
     eta_bi = tide.from_amplitude_phase(amp_bi, pha_bi, t)
     eta_f = tide.from_amplitude_phase(amp_f, pha_f, t)

     fig_summary=plt.figure()
     ax=fig_summary.add_subplot(111)
     # note we use seconds since as t (for the theoretical plot) is also in seconds
     bi = ax.plot(seconds_since/86400, BI_2008['Tide']/1000, color="orange", lw=1, label="Bobby Island")
     theoretical_bi = ax.plot(t/86400, eta_bi, color="orange", lw=1, linestyle="dasjed", label="BI Theoretical")
     f = ax.plot(seconds_since/86400, F_2008['Tide']/1000, color="blue", lw=1, label="Freemantle")
     theoretical_f = ax.plot(t/86400, eta_f, color="blue", lw=1, linestyle="dashed", label="F Theoretical")

     ax.set_xlabel("Days")
     ax.set_ylabel("Water height (m)")
     ax.tick_params(axis='x', rotation=45)
     # uncomment line below and rerun to see a zoom in
     #ax.set_xlim([14, 44]) # only plot 30 days worth
     ax.legend()
     fig_summary.tight_layout()
     plt.show()





