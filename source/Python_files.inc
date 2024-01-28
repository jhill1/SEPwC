Python: Files
----------------------

Writing software for scientific/research purposes often invovles reading in 
data from files. Python file handling is very powerful, but surprisingly
easy to use and manage.

First, a diversion...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Files in computing have a very long history and there's a lot of baggage
carried over from this history. Some of this creeps into the jargon
we end up using. First, there's the two main types of files
we will come across: text and binary. Python handles these two 
types of file differently. When it comes to text files there are special
characters at the end of each line for a EOL or End of Line. 

From these two file types, all the other files you may come across then 
come into being. We'll learn a lot more in the data section.

Opening and closing files
~~~~~~~~~~~~~~~~~~~~~~~~~~

Before reading or writing data to a file we must first open that
file and specify if we are going to read from it, or write to it. 

.. code-block:: python

    file = open('my_file.txt', 'r')

The above opens the file with name `my_file.txt` (in the current directory) in `read` mode. 
The variable `file` is the file handle. It's the variable by which you can access the file
on disk.

The various modes are:

 * `r`: open an existing file for a read operation.
 * `w`: open an existing file for a write operation. If the file already contains some data, then it will be overridden but if the file is not present then it creates the file as well.
 * `a`: open an existing file for append operation. It won’t override existing data.
 * `r+`: To read and write data into the file. The previous data in the file will be overridden.
 * `w+`: To write and read data. It will override existing data.
 * `a+`: To append and read data from the file. It won’t override existing data.
    
 A file, once finished with, needs closing too.

 .. code-block:: python

    file = open('my_file.txt', 'r')
    # do things
    file.close()

It's useful to get into the habit of closing files or using the Python `with` statement
to prevent files being left open. This is especially important when writing to 
a file as often the data is "bufferred" by the system and only gets written once 
the file handle is lost (i.e. `.close()` is called or the variable goes out of scope). 

.. code-block:: python

    with open("my_file.txt", "r") as file:
        # do things
        file.close()

The `file.close()` is now redundant, but can still be put in the code. All variables create in the `with`
block then disappear afterwards (this has caused me a few bugs in the past). 
