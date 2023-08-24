Data Management
---------------

Given data is a key part of most research codes, it is really important data is properly managed. Like your code, 
different versions need to be tracked and labelled to make sure any processing is clear.

Data formats
~~~~~~~~~~~~~

Data comes in many formats. We need to think about what this is and how to read it.

Human readable data is any data that can be opened in a text editor and a human can decipher it. This means
the data is text based (even if it's numbers), not binary (zeros and ones). Common human readable data
are CSV (comma seperated values) or XML (eXtensible Markup Language).

Machine readable is data that can easily be read by a computer program. This means it needs to be 
well structured, labelled and with clear definiaitons of what things are. It can be in binary format
which is impossible (I assume!) for humans to read. 

What we would like as programmers is human readable data that is also machine readable. Human readable 
data is much easier to debug (as we can read it!), but it also needs to be machine readable
to make our code easier to write!

Common formats you might come across are:

* CSV (human and machine readable)
* XML(human and machine readable)
* Excel sheets (machine only)
* NetCDF (machine only)
* TIF (machine only)

The processing pipeline
~~~~~~~~~~~~~~~~~~~~~~~~

Regardless of data source, most data needs some form of pre-processing to be ready for analysis or use in any script
we write. Sometimes the data pre-processing is very simple and we can write it within our script itself. Sometimes
we may write a seperate script. Occasionaly we may have to do it by hand. So whilst all data will go through
the pipeline below, it may be within our script.

.. image:: ../images/data_processing_pipeline.png
  :alt: The data processing pipeline going from raw data, cleaned data, machine read data to published data.

Raw data
'''''''''

This should always be saved as you downloaded it, was sent it, or how it came from the instrument or device. Store
and label as such.

Cleaned data
''''''''''''

This should be the raw data as you'd wish it had been given to you but is **non-destructive**. For example, 
save in a decent format (CSV, XML, GeoTIFF etc), replace column names with meaningful names (e.g. name1 -> surname), 
replace any missing data with a standard value (e.g. NA, NaN, -9999 are all common). 

At this point we may need to think about how we're going to store the data. Revision control systems are an excellent way 
of tracking data processing. They interact best with text-based formats (CSV, XML). This means we have a single file 
(ratehr than multiple versions) but the RCS can keep track of the versions for us. However, large data in binary format
is very difficult to track in RCS. It effectively creates a brand new copy each time (as it can't detect the changes 
properly). Here, it might be better to keep this disk based with clear filenames or directories. 

You should also make the filename useful (the date, the site, etc) and create a README or similar to label and describe
the data.

Analysis friendly data
'''''''''''''''''''''''

The above two steps will always need to be done in some way. This step heavily depends on what your script is going to do and may be able 
to be done programmitically in your script. Examples of this step are to make each column a variable, so for example if your data records
``female_treated``, ``female_untreated``, ``male_treated``, ``male_untrested``, split this into ``sex` and ``treated``. This 
will enable easier analysis later. 

It is also advised to remove any units frm the data and either add it to the column header/label or as a seperate column (the latter is
important if the units change, for example a mix of mm and m). It may be easier to translate all values to the same units rather than having 
a seperate unit column.

It may also be easier to seperate your data into multiple files that are linked using some consistant ID. Here, we are moving towards
more of a relational database structure, but it means we can manipulate data more easily any script we write. Again, this may be done
within the script rather than explicitly with the data. 

The final processing step may be to convert from ``wide`` format to ``long`` format. Both R and Python can do this automatically
and we'll cover this later.


Create a DOI
'''''''''''''

If your dataset is part of the research (e.g. collected by you) it might be a good idea to deposit the data in 
a respoitory and obtain a DOI (Digital Object Identifier) to that others can use the data and cite you. Common 
repositories for this are FigShare, Dryad, and Zenodo. 

All the processing above can be largely automated. Any processing software should be treated like any other software and
stored in revision control, preferably alongside your data. It then details your processing pipeline. Otherwsie, document
the processing done in a README or similar. 


