Using Excel
------------
.. index:: 
   single: data; excel

Excel is one of the most ubiquitous pieces of software in the world today. It's spawned many copies
including Google Sheets, Libreoffice Sheets, etc and itself is based on previous spreadsheet packages
(VisiCalc, Lotus 1-2-3, etc).

Spreadsheets offer a tabular view of data. They consist of cells, arranged in rows and columns. Columns are
often labelled using the alphabet (A, B, C, etc) and rows via a number. Each cell can therefore be located using a letter
and number combination, e.g. A3. A user can input data into each cell or use formulas, e.g. ``=5*3``, showing ``15`` in the cell.

Like computer programs, spreadsheets can create formulaalues using formulas that take values from variables. Unlike
a computer program the variable is another cell (rather than a named thing). For example, ``=5*C3`` would make that
cell the value sof C3 multiplied by 5. These formulas can be chained together and hence produce quite complex spreadsheets,
even to run simple algorithms, without resorting to computer code at all. Couple that to nice visual formatting
and you can see why spreadsheets are ubiquitous office software!

What a spreadsheet is not, is a database. A database is many tables of data that are related to each other (this is a
**relational database**). A spreadsheet can contain many tables, but lacks the relational aspect to the data. It is
however very common to call a spreadsheet or group of spreadsheets a database. It is therefore very common
to have data in the form of a spreadsheet that we then want to load into our script or software. 

Pre-processing data
~~~~~~~~~~~~~~~~~~~~~

Given that data often arrives in the form of a spreadsheet and that we sometimes need to clean the data as 
detailed above. If you are doing this manually, Excel or similar are excellent tools for doing so. Remeber to document
the changes you made.

Priliminary visualisation
~~~~~~~~~~~~~~~~~~~~~~~~~

As Excel etc are widely used they are very well tested! It can often save a lot of time graphing data
in Excel to check you have loaded your data into your script correctly. The advnatage of any script is that it
can process vasts amount of data, whereas Excel is limited. If you need to create a small subset of data
using Excel or similar and from that you can check your script is running correctly. 

.. warning::

    However useful Excel and similar tools are though, they should be avoided for storing your final data in. 
    They often have inbuilt algorithms to change data based on it's format, e.g. SEPT2 (a gene name) can be 
    translated into a date by Excel. If that change is then saved the data integrity is lost. `This occurs
    in the scientific literature. <https://genomebiology.biomedcentral.com/articles/10.1186/s13059-016-1044-7>`_
