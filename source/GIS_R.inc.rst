GIS - R
--------
.. index:: 
   single: GIS; R

R has a number of packages that can help with GIS analysis. We're going to focus on 
two: ``terra`` and ``sf``. For most tasks ``terra`` might be enough as it can handle
vector and raster data. ``sf`` focusses on vector data only. 

You should download this `zip file <https://github.com/jhill1/SEPwC/raw/master/code_examples/gis_data.zip>`_ 
which contains the data required. Make sure you
change your working directory to match where you've downloaded the data. 

The ``terra`` library
~~~~~~~~~~~~~~~~~~~~~
.. index:: 
   single: GIS; terra
   single: R; terra

The ``terra`` library is based around two key classes: ``SpatRatser`` and ``SpatVector``. 
Let's look at rasters first.

.. code-block:: R
    :caption: |R|

    my_raster <- rast("tidal_range.tif")
    my_raster

R will print out some basic info on the raster. This includes the extent, the projection 
space and min and max values.

You can summarise the raster too:

.. code-block:: R
    :caption: |R|

    summary(my_raster)

For this raster dataset, there is a single band. Rasters can store multiple
bands in a single file. It's common, for example, to store the R, G and B 
colours separately. You can check this using the ``nlyr`` function:

.. code-block:: R
    :caption: |R|

    nlyr(my_raster)

Raster data can contain missing data, held in the ``NoDataValue`` property of 
the raster. This value tells any reader to ignore this cell. When loading in R,
these values will be assigned as ``NA`` in the variable where you load the raster.
The actual value could be anything, but common values include ``-9999`` and ``-3.4e+38``.
When plotting in R, those ``NA`` will be transparent, but you can choose another
colour.

The data in the raster contains the Coordinate Reference System (CRS) otherwise
known as the projection space. This tells you where that raster is located
and what the coordinates mean (metres, degrees, etc). You can also change that
projection space using the ``project()`` function. When you project onto another
CRS you will change your data. By default the projection will use
bilinear interpolation to generate the data at the new coordinates. You can
change this to cubic, or cubicspline or use another algorithm. Stick with
bilinear unless you have a reason to change this.

.. admonition:: Thought exercise

    Have a search using a popular search engine to see if you can figure out
    why bilinear interpolation is default.


..  admonition:: Solution
    :class: toggle

    Bilinear interpolation will not add any new values to the new data. The
    new data maximum value will be equal to, or slightly less, than the old data; 
    and likewise, the minimum will be the same or slightly greater. Cubic or cubicspline
    can *overshoot* the limits of the old data, but can also produce smoother data, 
    without abrupt changes. Whenever you project onto a new coordinate system you 
    are altering the data.

.. code-block:: R
    :caption: |R|

    raster_in_latlon <- project(my_raster, "+init=EPSG:4326")
    crs(raster_in_latlon)
    ext(raster_in_latlon)
    crs(my_raster)
    ext(my_raster)

The raster is transformed from the original project space (UTM 31N) to a lat/lon 
projection space: WGS84. I've also thrown in the ``ext()`` function which gives
you the extent of the raster in the coordinate space.

When dealing with raster data you often need the rasters to be identical; 
same resolution, same extents, same projection space. Once identical, then
simple calculations (and indeed more complex ones!) can be carried out.

To write any raster to file, use the ``writeRaster`` function:

.. code-block:: R
    :caption: |R|

    writeRaster(raster_in_latlon, "UK_tidal_range.tiff",
                filetype = "GTiff",
                overwrite = TRUE,
                NAflag = -9999)

Hopefully, the options used here are obvious! Use the overwrite option with caution!
``terra`` comes with a number of useful functions, including those to calculate
slope, proximity distance, extract data from rasters, create a stack of rasters,
and to *rasterise* a vector (i.e. convert from vector to
raster). The ``terra`` library can also load vector data:

.. code-block:: R
    :caption: |R|

    tidal_gauges <- vect("tide_gauges.shp")

The same functions as above (``crs()``, ``ext()``, ``project()``) work as expected on
vector data. Let's look at some of the other functions in detail.

Rasterising a shapefile
~~~~~~~~~~~~~~~~~~~~~~~
.. index:: 
   single: GIS; rasterise
   single: R; rasterize

Often, you will need to convert vector data (like our tide gauges) into a grid format to perform 
pixel-by-pixel calculations with other raster data. In ``terra``, this is done using the ``rasterize()`` function.

To rasterise a vector, you always need a *template* raster. This template defines the physical grid: 
the extent, resolution, and CRS of the output. We can use our existing ``my_raster`` as the template.

.. code-block:: R
    :caption: |R|

    # First, ensure our vector data is loaded as a terra SpatVector
    tide_gauges_vect <- vect("tide_gauges.shp")

    # Rasterise the points, burning a specific column (e.g., "ID") into the pixels
    # Any pixel that doesn't overlap a point will automatically become NA
    gauges_raster <- rasterize(tide_gauges_vect, my_raster, field="ID")
    
    # Let's see what it looks like
    plot(gauges_raster)


Calculating proximity
~~~~~~~~~~~~~~~~~~~~~
.. index:: 
   single: GIS; proximity
   single: R; distance

A very common spatial operation is finding the distance from every pixel in a landscape to a specific feature of
interest—like a road, river, or in our case, a tide gauge. The ``terra`` package handles this elegantly with the ``distance()`` function.

If you pass a raster containing ``NA`` and non-``NA`` values to ``distance()``, it calculates the distance
from all the ``NA`` cells to the nearest non-``NA`` cell. We can use the rasterised gauges we just created to build a proximity map.

.. code-block:: R
    :caption: |R|

    # Calculate distance from all empty pixels to the nearest tide gauge
    proximity_raster <- distance(gauges_raster)
    
    # Plot the result to see the distance gradients
    plot(proximity_raster)

This generates a continuous surface where the value of every pixel represents the distance to the nearest 
gauge.

.. note::

   The distance is calculated in the units of your Coordinate Reference System. If your CRS is in metres (like UTM), 
   the output values are in metres. If it's in degrees (like WGS84), the output is in degrees
   which is often less useful for distance analysis!


.. youtube:: bzD-DGFcxUw
   :align: center


The ``sf`` library
~~~~~~~~~~~~~~~~~~
.. index:: 
   single: GIS; sf
   single: R; sf

R also have another popular library for dealing with shapefiles/vector data; ``sf``. 
This library has more features than ``terra`` so is worth learning. 

.. code-block:: R
    :caption: |R|

    library(sf)
    tide_gauges <- st_read("tide_gauges.shp")

Vector data can be points, lines or polygons. We can find out which using:

.. code-block:: R
    :caption: |R|

    st_geometry_type(tide_gauges)

We can then find out the CRS and extennt:

.. code-block:: R
    :caption: |R|

    st_crs(tide_gauges)
    st_bbox(tide_gauges)

We can also use ``sf`` to create a shapefile on the fly:

.. code-block:: R
    :caption: |R|

    aoi <- as.polygons(terra::ext(my_raster), crs=terra::crs(my_raster))

Here, I've created a polygon with the extent from a raster (loaded via ``terra``)
and the same CRS as that raster. I've explicitly flagged the use of ``terra`` functions
here to make it clear where my extents came from.

The ``sf`` library has a number of functions not available in ``terra``, such as
sampling within a polygon, geometry calculations (differences, unions, intersections),
and geometric calculations (area, distances, lengths). 

Switching between the two
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Using two different libraries for shapefiles can be a pain, but it is fairly
easy to switch a vector dataset between the two.

.. code-block:: R
    :caption: |R|

    sf::st_as_sf(terra::vect("tide_gauges.shp"))
    
Will convert a ``terra`` vector to the ``sf`` format. Normally, ``terra`` can deal with 
``sf`` objects, but you sometimes need to wrap the ``sf`` object in the ``st_zm`` function:

.. code-block:: R
    :caption: |R|

    points_as_raster <- rasterize(st_zm(tide_gauges), my_raster, field=1)

The ``st_zm`` function removes all ``z`` and ``m`` data which makes the object
compatible with ``terra``.

