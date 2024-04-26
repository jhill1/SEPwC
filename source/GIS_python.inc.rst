GIS - Python
--------------

Python has a number of packages that can help with GIS analysis. We're going to focus on 
three: `rasterio`, `geopandas` and `shapely`. 

You should download this `zip file <https://github.com/jhill1/SEPwC/raw/master/code_examples/gis_data.zip>`_ 
which contains the data required. Make sure you
change your working directory to match where you've downloaded the data. 

The `rasterio` library
~~~~~~~~~~~~~~~~~~~~~~~

The `rasterio` library is used to load, manipulate and plot raster
data. 

.. code-block:: Python
    :caption: |python|

    import rasterio

    my_raster = rasterio.open("gis_data/tidal_range.tif")
    my_raster

Python will print out some basic info on the raster. This includes the filename
and the read/write status. `rasterio` uses a number of attributes to contain information
about the raster:

.. code-block:: python
    :caption: |python|

    my_raster.width
    my_raster.height
    my_raster.nodata

For this raster dataset, there is a single band. Rasters can store multiple
bands in a single file. It's common, for example, to store the R, G and B 
colours separately. You can check this using the `count` attribute:

.. code-block:: python
    :caption: |python|

    my_raster.count

Raster data can contain missing data, held in the `nodata` property of 
the raster. This value tells any reader to ignore this cell. When loading in Python,
these values will be assigned as `nan` in the variable where you load the raster.
The actual value could be anything, but common values include `-9999` and `-3.4e+38`.
When plotting in Python, those `nan` will be transparent, but you can choose another
colour.

The data in the raster contains the Coordinate Reference System (CRS) otherwise
known as the projection space. This tells you where that raster is located
and what the coordinates mean (metres, degrees, etc). You can also change that
projection space using the `reproject()` function from `rasterio.warp'. When you project onto another
CRS you will change your data. By default the projection will use
nearest neighbour interpolation to generate the data at the new coordinates. You can
change this to bilinear, cubic, or cubicspline or use another algorithm. Use
bilinear unless you have a reason not to. The algorithms are in 
`rasterio.warp.Resampling`.

.. admonition:: Thought exercise

    Have a search using a popular search engine to see if you can figure out
    why bilinear interpolation is default.


..  admonition:: Solution
    :class: toggle

    Bilinear interpolation will not add any new values to the new data. The
    new data maximum value will be equal to, or slightly less, than the old data; 
    and likewise, the minimum will be the same or slightly greater. Cubic or cubicspline
    can *overshoot* the limits of the old data, but can also produce smoother data, 
    without abrupt changes. Whenever you project onto a new coordinate syste, you 
    are altering the data.

.. code-block:: Python
    :caption: |python|

    from rasterio.warp import calculate_default_transform, reproject, Resampling

    dstCrs = {'init': 'EPSG:4326'}
    # we need to work out the new shape and size of rthe destination
    transform, width, height = calculate_default_transform(
        my_raster.crs, dstCrs, my_raster.width, my_raster.height, *my_raster.bounds)
    # we need to setup the meta data for the new raster
    kwargs = my_raster.meta.copy()
    kwargs.update({
        'crs': dstCrs,
        'transform': transform,
        'width': width,
        'height': height
    })
    # open a file for writing
    dstRst = rasterio.open('Reprojected.tif', 'w', **kwargs)
    # reproject
    reproject(
        source=rasterio.band(my_raster, 1),
        destination=rasterio.band(dstRst, 1),
        src_crs=my_raster.crs,
        dst_crs=dstCrs,
        resampling=Resampling.bilinear)
    # close the file
    dstRst.close()

The raster is transformed from the original project space (UTM 31N) to a lat/lon 
projection space: WGS84. This is quite complex bit of code. You first define the 
new CRS. You then calculate the transform needed (.e.g how big the new raster needs to
be). You then set-up a new file to put the transformed raster in. `rasterio` just 
deals with raster on disk, not memory so everything needs to be saved to a file somewhere.
Finally, the data are reprojected, and then the file closed to save the data.

When dealing with raster data you often need the rasters to be identical; 
same resolution, same extents, same projection space. Once identical, then
simple calculations (and indeed more complex ones!) can be carried out.


The `geopandas` library
~~~~~~~~~~~~~~~~~~~~~~~~~~

`geopandas` is the geographical equivalent to `pandas`. It deals with dataframes
but those dataframes have a `geometry` component. It therefore maps onto GIS Vector
data very well.

.. code-block:: python
    :caption: |python|

    import geopandas

    tide_gauges = geopandas.read_file("gis_data/tide_gauges.shp")
    tide_gauges

Vector data can be points, lines or polygons. The `geomoetry` column tells us this and is,
in fact, a `shapely` object. `geopandas` can carry out a number of geometric calculations, e.g.
distances:

.. code-block:: python
    :caption: |python|

    whitby = tide_gauges["geometry"].iloc[40]
    tide_gauges["distance"] = tide_gauges.distance(whitby)
    tide_gauges["distance"]
    

The `geopandas` library has a number of functions, such as
sampling within a polygon, geometry calculations (differences, unions, intersections),
and geometric calculations (area, distances, lengths). 

The `shapely` library
~~~~~~~~~~~~~~~~~~~~~~

`shapely` is a library designed to do geometry calculations. It uses GIS Vector data
which can be loaded into a `Geometry`. You can also create geometries very easily in
`shapely`. However, you often don't need to use the main functions in `shapely` itself
as `geopandas` is built on top of `shapely`. It's often needed for creating new
vector data though.

.. code-block:: python
    :caption: |python|

    from shapely.geometry import box

    my_box = box(*my_raster.bounds)

This creates a polygon using the extent (bounds) of the raster object we loaded earlier.

You can similar create points, lines, etc. Most of the geometric operations in `geopandas`
come from `shapely`, including things like `within`, `intersects`, etc.

