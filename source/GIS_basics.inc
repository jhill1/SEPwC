GIS
-----

This is a brief introduction to geospatial data which applied to both Python
and R. Geospatial data is information that also has a geographical component. 
Example include house proces, coupled to locations; roads and road types or hazard
assessment.

There are three things we need to learn about first:

 - vector data
 - raster data
 - projection spaces or coordinate spaces

Vector data
~~~~~~~~~~~~

Vector data represent geometries via mathematicla objects. You can zoom
into a vector infinitely at it will remain infintely small! There are
three types of vector data:

 - points
 - lines
 - polygons

Vectors are most commonly stored as shapefiles: ``*.shp`` files. We call then shapefiles 
put they actually consist of a number of files. So a file called ``landslides.shp`` also
will have ``landslides.prj``, ``landslides.dbf`` and ``landslides.shx`` and a few more beside.
All files are required to fully define the shapefile.

Shapefiles often contain data alongside the vector representation. So for example, the shape
of buildings might be contained in the shapefile, but the polygons with the outline of the building
footprint might also contains the address, the price, the date built, etc.

Raster data
~~~~~~~~~~~~~

Raster data are a grid of pixels of a resolution. Each pixel has a value, such as height
temperature, land use category, etc. The data are stored in *bands*, so a raster can contain
multiple datasets within the same structure and file. It's common for colour
images, such as satellite images, to be stored in a R(ed), G(reeen), and B(lue) bands.

Coredinate References System (CRS)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GIS is a 2D system. But the Earth is 3D; almost a sphere in fact. To display the 
3D surface to a 2D screen you need to project into a 2D space; the CRS. Any 
CRS required trade offs. You can preserve area or shape or distance, but not all three!

In R and Python if you are doing operations on geospatial data they **must** be in the 
same project space. Your operation may work, but you won't get the result you want!

Common projection spaces are "mercator" and "Universal Tranverse Mercator (UTM)". For
"regional" studies UTM is best. It's in metres (not degrees!) and covers a reasonably 
large area with little deformation. 

