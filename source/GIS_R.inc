GIS - R
--------

R has a number of packages that can help with GIS analysis. We're going to focus on 
two: `terra` and `sf`. For most tasks `terra` might be enough as it can handle
vector and raster data. `sf` focusses on vector data only. 

You should download this `zip file <  >`_ which contains the data required. Make sure you
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
The actual value could be anything, but common values include `-9999` and `-3.4e+38`


