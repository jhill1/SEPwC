ggplot2 tutorial
-----------------
.. index::
  single: ggplot2

``ggplot2`` is a popular library for creating pretty graphs and figures in R. It
works in a simialr way to the tidyverse in terms of using dataframes as the basic data
and then adding layers on top to create the final plot. 

This section is based on the tutorial by Cedric Scherer https://www.cedricscherer.com/2019/08/05/a-ggplot2-tutorial-for-beautiful-plotting-in-r/

``ggplot2`` is also used as a basis for other graphing packages, such as ``ggpubr`` which simplifies some
of the syntax here to create publicaiton-level quality graphs. By learning ``ggplot2`` you should find
``ggpubr`` very easy to use and have the knowledge to create more bespoke plots where needed.

The dataset
~~~~~~~~~~~~

We are using data from the National Morbidity and Mortality Air Pollution Study (NMMAPS). 
To make the plots manageable we are limiting the data to Chicago and 1997–2000. For more detail 
on this data set, consult Roger Peng’s book Statistical Methods in Environmental Epidemiology
with R. You can download the data we are using during this tutorial here (but you don’t have to).

We can import the data into our R session for example with read_csv() from the {readr} package.

.. code-block:: R

    chic <- readr::read_csv("https://cedricscherer.com/data/chicago-nmmaps-custom.csv")
    tibble::glimpse(chic)
    head(chic, 10)

Plotting basics
~~~~~~~~~~~~~~~~

A ggplot is built up from a few basic elements:

#. Data: The raw data that you want to plot.
#. Geometries ``geom_``: The geometric shapes that will represent the data.
#. Aesthetics ``aes()``: Aesthetics of the geometric and statistical objects, such as position, color, size, shape, and transparency
#. Scales ``scale_``: Maps between the data and the aesthetic dimensions, such as data range to plot width or factor values to colors.
#. Statistical transformations ``stat_``: Statistical summaries of the data, such as quantiles, fitted curves, and sums.
#. Coordinate system ``coord_``: The transformation used for mapping data coordinates into the plane of the data rectangle.
#. Facets ``facet_``: The arrangement of the data into a grid of plots.
#. Visual themes ``theme()``: The overall visual defaults of a plot, such as background, grids, axes, default typeface, sizes and colors.

You need to specify the ``data``, ``geometry`` and ``aesthetics`` as a minimum. To build up a ggplot we tell 
ggplot the data, e.g. ``ggplot(data = df)``. We then tell it which variables to plot i nthe aesthetics: ``aes(x=var1, y=var2)
and then we need to say what kind of plot via the geometry: ``geom_point()``:

.. code-block:: R

    g <- ggplot(chic, aes(x = date, y = temp))
    g + geom_line()

Note that we've stored the plot into an object, `g`. To display, we simply type `g` to the R console. However, here, 
I've added  line geometry too. You can add other things to `g` on the fly:

.. code-block:: R

    g + geom_point()

(this will display immediately and does not affect the ``g`` object. Try plotting just ``g + geom_line()`` again).

You can maniuplate aspects of the geometry directly in the geometry function:

.. code-block:: R

    g + geom_point(color = "firebrick", shape="diamond", size=2)

Note that ggplot2 understand ``colour``, ``color`` and ``col`` and, of course, you can add more geometries:

.. code-block:: R

    g + geom_point(color = "firebrick", shape = "diamond", size = 2) +
        geom_line(color = "firebrick", linetype = "dotted", lwd = .3)

Themes
~~~~~~

Themes allow the setting up of axes, grids, fonts etc in a consistant way. ``ggplot2`` comes with a 
number of built-in themes.

.. code-block:: R

    theme_set(theme_bw())

    g + geom_point(color = "firebrick")

Using ``theme_set`` alters all plots in your current R session (or script). You can apply a theme to a
particular plot only too. Many aspects of the plot can be altered via the ``theme()`` function.
To see which details of a ggplot theme can be modified have a look here — and take some time; it's a long list.
https://ggplot2.tidyverse.org/reference/theme.html

Axes
~~~~~

The default axes titles use the variable names. Let’s add some well-written labels to the axes. 
For this, we add labs() providing a character string for each label we want to change (here x and y):

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)")

Note, we're not saving the plot object into a variable and are instead instantly plotting it.

``theme()`` is an essential command to modify particular theme elements (texts and titles, 
boxes, symbols, backgrounds, etc). We are going to use them a lot! For now, we are going to modify 
text elements. We can change the properties of all or particular text elements (here axis titles) 
by overwriting the default ``element_text()`` within the ``theme()`` call:

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)") +
           theme(axis.title.x = element_text(vjust = 0, size = 15),
                 axis.title.y = element_text(vjust = 2, size = 15))

We've adjusted the font size and the vertical positioning. Note that the ``vjust`` is the same of the positioning
of the horizontal axis; i.e. along the axis. There are a lot of things you can alter, but font size and positioning are
the crucial ones to know about.

The font axes text can also be altered:

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)") +
           theme(axis.text = element_text(color = "dodgerblue", size = 12),
                 axis.text.x = element_text(face = "italic"))

This includes rotating the labels:


.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)") +
           theme(axis.text.x = element_text(angle = 50, vjust = 1, hjust = 1, size = 12))

And removing ticks and text (not advised!):

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)") +
           theme(axis.ticks.y = element_blank(),
                 axis.text.y = element_blank())

The ``element_blonk()`` functions allows to remove any aspect of the theme, e.g. axes labels, if you wish.

Axes limits and scales
.......................

A key part of producing attractive plots is the scale and limits of the axes. Using these you can ensure the
data are plotted correctly, e.g. on log-log axes or the key part of the data can be shown. You can, of course,
subset your data to do this, but you can also 

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp)) +
           geom_point(color = "firebrick") +
           labs(x = "Year", y = "Temperature (°F)") +
           ylim(c(0, 50))

There are other ways of limiting the plot using ``scale_y_continuous(limits = c(0,50))`` or
``core_cartesian(ylim = c(0,50))``. These give similar results, but are, in fact, slightly different.
Try them both instead of the ``ylim()``.

IMAGE

Note the lack of buffer on the ``coord_cartesian()`` plot, compared to the ``scale_y_continuous()`` plot?
This is the difference between subsetting (``scale_y_continuous`` and ``ylim()``) and clipping (``coord_cartesian()``).
This is even more pronounced on a box-whisker plot:

IMAGE

.. caution::

    Notice the median lines are different here! If you scale or impose ``ylim`` it is worth checking your data without
    limits first! In other word, build up your plot carefully and also run the stats within R, not just rely on reading
    the graphs...

You can force R to plot starting from some coordinates, e.g. the (0,0) origin:

.. code-block::

chic_high <- dplyr::filter(chic, temp > 25, o3 > 20)

    ggplot(chic_high, aes(x = temp, y = o3)) +
           geom_point(color = "darkcyan") +
           labs(x = "Temperature higher than 25°F",
                y = "Ozone higher than 20 ppb") +
           expand_limits(x = 0, y = 0)

But we can also force it to literally start at the origin!

.. code-block::

    ggplot(chic_high, aes(x = temp, y = o3)) +
           geom_point(color = "darkcyan") +
           labs(x = "Temperature higher than 25°F",
                y = "Ozone higher than 20 ppb") +
           expand_limits(x = 0, y = 0) +
           coord_cartesian(expand = FALSE, clip = "off")

.. note::

    The argument clip = "off" in any coordinate system (``coord_*``), allows to draw outside of the panel area.

Scaling is an important part of plotting. If you are expecting a 1:1 ratio between your variables, creating
a plot with the axes scaled to that helps visualisation. For demonstrating purposes, let’s plot temperature 
against temperature with some random noise. The coord_equal() is a coordinate system with a specified ratio
representing the number of units on the y-axis equivalent to one unit on the x-axis. The default, ratio = 1,
ensures that one unit on the x-axis is the same length as one unit on the y-axis:

.. code-block:: R

    ggplot(chic, aes(x = temp, y = temp + rnorm(nrow(chic), sd = 20))) +
           geom_point(color = "sienna") +
           labs(x = "Temperature (°F)", y = "Temperature (°F) + random noise") +
           xlim(c(0, 100)) + ylim(c(0, 150)) +
           coord_fixed()

Ratios larger than 1 make the units on the y-axis long thatn those on the x, and
vice-versa:

.. code-block::

    ggplot(chic, aes(x = temp, y = temp + rnorm(nrow(chic), sd = 20))) +
           geom_point(color = "sienna") +
           labs(x = "Temperature (°F)", y = "Temperature (°F) + random noise") +
           xlim(c(0, 100)) + ylim(c(0, 150)) +
           coord_fixed(ratio = 1/5)

Plot legends
~~~~~~~~~~~~

We often colour code parts of our graphs, and then add a legend to show how the data are separated.
We will ``color`` code the plot based on season. Or to phrase it in a more ``ggplot``’ish way: we map the 
variable season to the aesthetic ``color``. One nice thing about ``ggplot2`` is that it adds a legend by
default when mapping a variable to an aesthetic. You can see that by default the legend title is 
what we specified in the ``color`` argument:

.. code-block:: R

    ggplot(chic,
           aes(x = date, y = temp, color = season)) +
    geom_point() +
    labs(x = "Year", y = "Temperature (°F)")

How can you remove the legend if it's added by default?

.. code-block:: R

    ggplot(chic,
           aes(x = date, y = temp, color = season)) +
    geom_point() +
    labs(x = "Year", y = "Temperature (°F)") +
    theme(legend.position = "none")

You can also use ``guides(color = "none")`` or ``scale_color_discrete(guide = "none")`` depending on 
the specific case. While the change of the theme element removes all legends at once, 
you can remove particular legends with the latter options while keeping some others:

.. code-block:: R
    
    ggplot(chic,
           aes(x = date, y = temp,
           color = season, shape = season)) +
    geom_point() +
    labs(x = "Year", y = "Temperature (°F)") +
    guides(color = "none")

Here, we've kept the legend for the shape, but not colour. Note that the aesthetics is where
we map shape and colour. If we do it outside the aesthetic we don't get a legend for that property.

We can remove titles for legend using the ``element_blank()``:

.. code-block:: R

    ggplot(chic, aes(x = date, y = temp, color = season)) +
           geom_point() +
    labs(x = "Year", y = "Temperature (°F)") +
    theme(legend.title = element_blank())


