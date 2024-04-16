GIS - R
--------

R has a number of packages that can help with GIS analysis. We're going to focus on 
two: `terra` and `sf`. For most tasks `terra` might be enough as it can handle
vector and raster data. `sf` focusses on vector data only. 

You should download this `zip file <https://github.com/jhill1/SEPwC/raw/master/code_examples/gis_data.zip>`_ 
which contains the data required. Make sure you
change your working directory to match where you've downloaded the data. 

The `terra` library
~~~~~~~~~~~~~~~~~~~~

The `terra` library is based around two key classes: `SpatRatser` and `SpatVector`. 
Let's look at rasters first.

.. code-block:: R

    my_raster <- raster("gis_data/tidal_range.tif")
    my_raster

R will print out some basic info on the raster. This incluudes the extent, the projection 
space and min and max values.

You can summerise the raster too:

.. code-block:: R

    summary(my_raster)

For this raster dataset, there is a single band. Rasters can store multiple
bands in a single file. It's common, for example, to store the R, G and B 
colours seperately. You can check this using the `nlyr` function:

.. code-block:: R

    nlyr(my_raster)

Raster data can contain missing data, held in the `NoDataValue` property of 
the raster. This value tells any reader to ignore this cell. When loading in R,
these values will be assigned as `NA` in the variable where you load the raster.
The actual value could be anything, but common values include `-9999` and `-3.4e+38`.
When plotting in R, those `NA` will be transparent, but you can choose another
colour.

The data in the raster contains the Coordinate Reference System (CRS) otherwise
known as the projection space. This tells you where that raster is located
and what the coordinates mean (metres, degrees, etc). You can also change that
projection space using the `project()` function. When you project onto another
CRS you will change your data. By default the projection will use
bilinear interpolation to generate the data at the new coordinates. You can
chnage this to cubic, or cubicspline or use another algorithm. Stick with
bilinear unless you have a reason to change this.

.. admonition:: Thought exercise

    Have a search using a popular search engine to see if you can figure out
    why biliner interpolation is default.


..  admonition:: Solution
    :class: toggle

    Bilinear interpolation will not add any new values to the new data. The
    new data maximum value will be equal to, or slightly less, than the old data; 
    and likewise, the minimum will be the same or slightly greater. Cubic or cubicspline
    can *overshoot* the limits of the old data, but can also produce smoother data, 
    without abrupt changes. Whenever you project onto a new coordinate syste, you 
    are altering the data.

.. code-block:: R

    raster_in_latlon <- project(my_raster, "+init=EPSG:4326")
    crs(raster_in_latlon)
    ext(raster_in_latlon)
    crs(my_raster)
    ext(my_raster)

The raster is transformed from the original project space (UTM 31N) to a lat/lon 
projection space: WGS84. I've also thrown in the `ext()` function which gives
you the extent of the raster in the corrdinate space.

When dealing with raster data you often need the rasters to be identical; 
same resolution, same extents, same projection space. Once identical, then
simple calculations (and indeed more complex ones!) can be carried out.

To write any raster to file, use the `writeRaster` function:

.. code-block:: R

    writeRaster(raster_in_latlon, "UK_tidal_range.tiff",
                filetype = "GTiff",
                overwrite = TRUE,
                NAflag = -9999)

Hopefully, the options used here are obvious! Use the overwrite option with caution!
`terra` comes with a number of useful functions, including those to calculate
slope, proximity distance, extract data from rasters, create a stack of rasters,
and to *rasterise* a vector (i.e. convert from vector to
raster). 

The `terra` library can also load vector data:

.. code-block:: R

    tidal_gauges <- vect("gis_data/tide_gauges.shp")

The same functions as above (`crs()`, `ext()`, `project()`) work as expected on
vector data.

The `sf` library
~~~~~~~~~~~~~~~~~

R also have another popular library fpr dealing with shapefiles/vector data; `sf`. 
This library has more features than `terra` so is worth learning. 

.. code-block:: R

    library(sf)
    tide_gauges <- st_read("gis_data/tide_gauges.shp")

Vector data can be points, lines or polygons. We can find out which using:

.. code-block:: R

    st_geomoetry_type(tide_gauges)

We can then find out the CRS and extennt:

.. code-block:: R

    st_crs(tide_gauges)
    st_bbox(tide_gauges)

We can also use `sf` to create a shapefil on the fly:

.. code-block:: R

    aoi <- as.polygons(terra::ext(my_raster), crs=terra::crs(my_raster))

Here, I've created a polygon with the extent from a raster (loaded via `terra`)
and the same CRS as that raster. I've explicitly flagged the use of `terra` functions
here to make it clear where my extents came from.

The `sf` library has a number of functions not available in `terra`, such as
sampling within a polygon, geometry calculations (differences, unions, intersections),
and geometric calculations (area, distances, lengths). 

Switching between the two
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Using two different libraries for shapefiles can be a pain, but it is fairly
easy to switch a vector dataset between the two.

.. code-block:: R

    sf::st_as_sf(terra::vect("gis_data/tide_gauges.shp"))
    
Will convert a `terra` vector to the `sf` format. Normall, `terra` can deal with 
`sf` objects, but you sometimes need to wrap the `sf` object in the `st_zm` function:

.. code-block:: R

    points_as_raster <- rasterize(st_zm(tide_gauges), my_raster, field=1)

The `st_zm` function removes all `z` and `m` data which makes the object
compatible with `terra`.

