Python: Datetimes
----------------------

Dates and time are a common aspect of environmental data. We often need to 
crop date/times to a specific range and compare or take samples from our
data every *N* minutes, for example. Python comes with a datetime module
that helps us deal with these issues. It provides a variety of functions
to work out durations, samples and deal with leap years and timezones.

.. code-block:: Python

    import datetime

    now = dateime.datetime.now()

    print(now)

This prints the current date and time based on your computers clock:

.. code-block:: bash

    2024-02-15 09:07:34.636548

However, this has hidden a few things. Instead of placing the ``now()`` output
into a variable, print it directly using the console Python

.. code-block:: python

    In [1]: import datetime

    In [2]: datetime.datetime.now()
    Out[2]: datetime.datetime(2024, 2, 15, 9, 7, 26, 165519)

What ``now()`` gives us is a datetime object, which contains the year, month, day, 
hour, minutes, seconds, and part-seconds. We can access these directly if we need to. 
The ``print`` function actually creates a prettified string for the user.


