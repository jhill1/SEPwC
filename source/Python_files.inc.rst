Python: Files
----------------------
.. index::
  single: Files; Python

Writing software for scientific/research purposes often involves reading in 
data from files. Python file handling is very powerful, but surprisingly
easy to use and manage.

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
.. index::
  single: Opening and Closing Files; Python

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
a file as often the data is "buffered" by the system and only gets written once 
the file handle is lost (i.e. `.close()` is called or the variable goes out of scope). 

.. code-block:: python

    with open("my_file.txt", "r") as file:
        # do things
        file.close()

The `file.close()` is now redundant, but can still be used in the code to make it clear if needed. What the
``with`` block does is call ``__enter__`` and ``__exit__`` functions, so files are automatically
closed etc. 

Reading files
~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Reading Files; Python

We can now open and close files, how do we get information from them? We'll focus on text files for now. Most
binary files have a Python module to read them, so are more specialist in nature.

We can read text files line-by-line or in one go. To read line-by-line:

.. code-block:: python

    file = open('my_file.txt', 'r')
     
    # This will print every line one by one in the file
    for line in file:
        print(line)


The ``file`` operator is also an iterable object, so a loop over each element in the ``file`` allows us
to read the text line-by-line.

If we want to read in all the text at once:

.. code-block:: python

    file = open('my_file.txt', 'r')
     
    print(file.read())

The ``file.read()`` function grabs all the text from the file into memory (and here prints immediately, but can also
be stored in a variable). The ``read()`` function can also take an argument for the number of characters to read, 
for example this reads the first 5 characters:

.. code-block:: python

    file = open('my_file.txt', 'r')
     
    print(file.read(5))

My preferred way of reading text files is by line and performing any operations on a line-by-line basis. This
works for most files as data in text files tends to be organised that way. I use the ``readline()`` function
to make this very clear. For example:

.. code-block:: python

    with open("datafile.txt", "r") as file:
        data = file.readlines()
        for line in data:
            words = line.split()
            print(words)

.. index::
  single: Split function; Python

The ``split()`` function is an example of the type of processing; here splitting the line of text
into words (separated by spaces) and creating a list of those.


.. admonition:: Practical exercise

    Download `this text file <https://raw.githubusercontent.com/jhill1/SEPwC/master/code_examples/depth_data.csv>`_ .
    Write code to open the file
    and read all the contents in one go and save into a variable.
    Print that variable to screen.

    Then write a version that reads in the file line by, splitting
    the lines by commas and printing to screen each line.

..  admonition:: Solution
    :class: toggle

    This is my code, wrapping both parts into one code.
    
    .. code-block:: python

        with open("depth_data.csv","r") as f:
            all_file = f.read()
            print(all_file)

        # the file will be closed above as the "with"
        # block has ended.
        with open("depth_data.csv","r") as f:
            for line in f:
                print(line.split(","))
    
    which produces:
    
    .. code-block:: bash

        File,Top,Bottom
        core_13.xlsx,22.75,30
        core_16.xlsx,27,33
        core_17.xlsx,27.75,43

        ['File', 'Top', 'Bottom\n']
        ['core_13.xlsx', '22.75', '30\n']
        ['core_16.xlsx', '27', '33\n']
        ['core_17.xlsx', '27.75', '43\n']
        

    Note how the second method has produced lists (due to the `split()` function) which
    we could iterate over and do something sensible with, e.g. opening the file in the first
    element, perhaps.


Writing files
~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Writing Files; Python

Writing files is a bit different to reading files. You are in charge of putting the line breaks in!

.. code-block:: python

    with open("file.txt", "w") as f: 
        f.write("Hello World!!!")
        f.write("No, really, hello!")

The above opens a text file for writing (note the ``'w'``) and writes a single line of text. Try it.

To get multiple lines we either need to create a string with those newline characters in it *or* use
the ``writelines()`` function with a list of strings. As with a lot of things in Python there are a number of ways 
of doing this!

Let's add some newlines to the example above first.

.. code-block:: python

    with open("file.txt", "w") as f: 
        f.write("Hello World!!!\n")
        f.write("No, really, hello!\n")

Notice the ``\n`` character - this is a newline character. So you will now have a file that contains:

.. code-block:: bash

   Hellow World!!!
   No, really, hello!

We could achieve the same thing using ``writelines()`` but we are still responsible for adding the newlines:

.. code-block:: python

    contents = ["Hello World!!!\n", "No, really, hello!\n"]
    with open("file.txt", "w") as f: 
        f.writelines(contents)

Produces the same output as above. If your list of strings doesn't have newline characters, then something like
this works well:


.. code-block:: python

    contents = ["Hello World!!!\n", "No, really, hello!\n"]
    with open("file.txt", "w") as f: 
        f.write('\n'.join(contents))

Here, we join each element of contents with a newline character. We could also do:

.. code-block:: python

    contents = ["Hello World!!!\n", "No, really, hello!\n"]
    with open("file.txt", "w") as f: 
        f.writelines("%s\n" % l for l in contents)

Here, we are using generator expressions (the ``l for l in contents``) and formatting expressions to stick a string a newline
together.

All of the above are correct and will work fine. Some may argue for one way being more 'Pythonic' than
others, but your job is to write clear code so use whichever is clearest for you.

.. admonition:: Practical exercise

    Write your `capitals` dictionary into a file, separated by commas, so country in 
    column 1 and the city in column 2. Each country is then on a new line.
    This creates a CSV file, which you can load into Excel, etc.

..  admonition:: Solution
    :class: toggle

    .. code-block:: python

        capitals = {
            "Germany": "Berlin",
            "UK": "London",
            "USA": "Washington DC",
            "France": "Paris",
            "Burkina Faso": "Ouagadougou"
        }
        with open("capitals.csv", "w") as f: 
            for country in capitals:
                f.write(country + "," + capitals[country] + "\n")

    The file then contains:

    .. code-block:: bash

        jh1889@mirovia:~/work/teaching/SEPwC/source$ more capitals.csv 
        Germany,Berlin
        UK,London
        USA,Washington DC
        France,Paris
        Burkina Faso,Ouagadougou
    

