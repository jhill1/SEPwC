CSV files
------------

CSV files are text files. They contain data in text format, with columns seperated by a delimiter
and rows seperated by a new line.

The delimaiter is often a comma `,`, hence CSV (Comma Seperated Values). Other common delimiters
are whitespace, :kbd:`Tab`, or pipe symbols :kbd:`|`. Data that contains the delimiter can be quoted
using `"`. 

CSV is obviously a spreadsheet-based data storage format. Data will be in the form of a table with columns
and rows. The first row may be a header contining the information about each column or that may be
in a seperate file (e.g. a text file).

.. warning::
  
    There is no well-defined standard format for CSV files. They can therefore be difficult to process
    when gathered from different sources.

Both R and Python can read in CSV files. R can do this without any additional libraries. Python has a few
options.

Reading CSV in R
~~~~~~~~~~~~~~~~~~

CSV files are handled in R without an additional libraries. `The full documentation can be found online 
<https://stat.ethz.ch/R-manual/R-devel/library/utils/html/read.table.html>`_ but some brief examples:

.. code-block:: R


    # Read CSV into DataFrame
    read_csv = read.csv('/Users/admin/file.csv')

    # Read with custom delimiter
    read_csv = read.csv('/Users/admin/file.csv',sep=',')

    # Read without header
    read_csv = read.csv('/Users/admin/file_noheader.csv',header=FALSE)

    # Replaces all -1 and empty string as <NA>
    read_csv = read.csv('/Users/admin/file.csv',na.strings=c(-1,''))

    # Keep String as Character.
    read_csv = read.csv('/Users/admin/file_noheader.csv', stringsAsFactors='FALSE')

The `Tidyverse <https://www.tidyverse.org/>`_ collection of packages has some additional
function to read in CSV data.. 

Reading CSV in Python
~~~~~~~~~~~~~~~~~~~~~~

Python contains a useful ``csv`` library to help us here. It can handle different delimiters, 
quotes and headers making it much easier than trying to parse data ourselves. You can find
the `full documentation for the CSV module online <https://docs.python.org/3/library/csv.html>`_
but briefly we can load data in using code like this:

.. code-block:: python

    import csv
    
    with open('eggs.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        print(', '.join(row))

The above reads the CSV file by row and prints out the content. The ``row`` variable is a list
with each item containing the column data from that row.


Alternatively, you can read the data as a dictionary. Here we assume the CSV has a header:


.. code-block:: python

    import csv

    with open('names.csv', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            print(row['first_name'], row['last_name'])

The ``row`` variable is now a dictionary, with the items labelled by whatever was in the first row (the header). 
As a programmer you would need to know that information beforehand to use them correctly. 

Pandas, covered earlier, can also read in CSV files.

