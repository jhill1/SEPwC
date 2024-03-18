R: files
----------------------------
.. index:: 
   single: files; r

Writing software for scientific/research purposes often invovles reading in 
data from files. R file handling is very powerful, but surprisingly
easy to use and manage, but there are a lot of overlapping functions
that do very similar things.


Files in computing have a very long history and there's a lot of baggage
carried over from this history. Some of this creeps into the jargon
we end up using. First, there's the two main types of files
we will come across: text and binary. R handles these two 
types of file differently. When it comes to text files there are special
characters at the end of each line for a EOL or End of Line. 

From these two file types, all the other files you may come across then 
come into being. We'll learn a lot more in the data section.

Read and write tables/csv files
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Most of the time when using R you end up reading data from CSV
(Comma Separated Values) or tables (the same as CSV, but separated by
something other than a comma!). The syntax for these function is very similar.

.. code-block:: R

    data<-read.table("data.txt",sep=",",header = TRUE)
    data<-read.csv("data.txt",header = TRUE)

Those two lines of code produce identical results. The `read.csv` has
the separator (`sep=`) set to `,` by default. In `read.table` we specify
it. In other words `read.table` is more flexible in reading in data as it
can read in data separated by spaces, semi-colons, pipes, etc. Both
functions return a data frame object (we'll learn more on this later), 
with the columns labelled by the headers. 

Similarly if we have data in a variable, we can get R to write this out
in a CSV or table, easily:

.. code-block:: R

    write.csv(df,file='new_file.csv')

Here, ``df`` is your data frame which contains the data, with the filename
given by the ``file`` argument. 

There are a number of arguments you can give to the function to get the 
data file to look as you wish. This includes appending to an existing file, 
the type of quotes to use, the separator and whether to use row and column names.

It's worth finding the R manuals online to see these and experiment a little.

.. admonition:: Practical exercise

    Write your `capitals` dictionary into a file, separated by commas, so country in 
    column 1 and the city in column 2. Each country is then on a new line.
    This creates a CSV file, which you can load into Excel, etc.

..  admonition:: Solution
    :class: toggle
 
    .. code-block:: R

        capitals = {
            "Germany": "Berlin",
            "UK": "London",
            "USA": "Washington DC",
            "France": "Paris",
            "Burkina Faso": "Ouagadougou"
        }
        write.table(capitals,"capitals.csv",sep=",",col.names=F)

    The file then contains:

    .. code-block:: bash

        jh1889@thalassa:~/work/teaching/SEPwC$ more captials.csv 
        "Germany","Berlin"
        "UK","London"
        "USA","Washington DC"
        "France","Paris"
        "Burkina Faso","Ouagadougou"
    
    Why did I use the `write.table` function? What happens if `write.csv` is used? 
