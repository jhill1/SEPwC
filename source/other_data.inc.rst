Other data formats
-------------------

There are a lot of data formats out there. Rather than cover all of them, here are some common ones that you may come across

NetCDF
~~~~~~

Network Common Data Format. This is a binary file format which store large arrays of data that are linked in 
some ways. Often used for spatial data. Arrays will be latitude, longitude and then values based on 
those arrays, e.g. sea surface temperature. It can handle multiple dimensions, so it is possible to 
store three dimensional field that vary in time (4D!). 

GeoTIFF
~~~~~~~

Raster data (height data on a grid or similar) is often stored in a GeoTIFF file which is based on the common image format. 
TIFF is a lossless image format (unlike JPEG or GIF) and also contains a header. It's this header that is crucial! It can 
contain the location data and projection space.

XML
~~~~

XML (eXtensible Markup Language) is a tree-structed, tag-based format that is human and machine readable but can also 
contain binary data. An example:

.. code-block:: xml
    :caption: |cli|
    
    <employees>
      <employee>
        <firstName>John</firstName> <lastName>Doe</lastName>
      </employee>
      <employee>
        <firstName>Anna</firstName> <lastName>Smith</lastName>
      </employee>
      <employee>
        <firstName>Peter</firstName> <lastName>Jones</lastName>
      </employee>
    </employees>

Both R and Python have XML parsers available.

JSON
~~~~~~~

JSON (JavaScript Object Notation) is another text-based format that is human and machine readable. It is 
similar in structure to a dictionary.

.. code-block:: json
    :caption: |cli|

    {"employees":[
      { "firstName":"John", "lastName":"Doe" },
      { "firstName":"Anna", "lastName":"Smith" },
      { "firstName":"Peter", "lastName":"Jones" }
    ]}

Both R and Python have JSON parsers available.

SQL
~~~~

SQL (Structured Quary Language, pronounced "sequel") is a common database language that contains tables.
Both Python and R can interact with SQL-based databases, like MySQL.


