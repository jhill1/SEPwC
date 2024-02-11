R files
----------------------------

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
(Comma Seperated Values) or tables (the same as CSV, but seperated by
something other than a comma!). The syntax for these function is very similar.

.. code-block:: R

    data<-read.table("data.txt",sep=",",header = TRUE)
    data<-read.csv("data.txt",header = TRUE)

Those two lines of code produce identical results. The `read.csv` has
the seperator (`sep=`) set to `,` by default. In `read.table` we specify
it. In other words `read.table` is more flexible in reading in data as it
can read in data seperated by spaces, semi-colons, pipes, etc. Both
functions return a data frame object (we'll learn more on this later), 
with the columns labelled by the headers. 
    
