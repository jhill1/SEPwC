R command line arguments 
----------------------------

The simplest user-facing scripts/software use the Command Line Interface (CLI) to interact with a user.
The CLI allows the user to pass options to a script as they execute. We have already used these elsewhere
in the course, for example:

.. code-block:: bash

   ls -l

which is the command to list things, ``ls``, in a Unix shell with the option supplied to make it a table ``-l``.
Similaraly, we've covered:

.. code-block:: bash

   cp -r dir1 dir2

Here, there are three options. The ``-r`` flag, the directory to copy ``dir1``, and where to copy it to, ``dir2``.

R has both in-built handling of command line options, but also a number of modules to give us quite
advanced usage options.

R and the command line
~~~~~~~~~~~~~~~~~~~~~~~

When you run a R script via the Rscript command, with some arbitrary text after:

.. code-block:: bash

   Rscript arg_script.R arg1 arg2 arg3

that text is passed to the `script for you to access. Let's create this simple script, named ``arg_script.R``

.. code-block:: R

    args = commandArgs(trailingOnly=TRUE)
    print(args)
    print(paste0("Length: ", length(args)))

Now run that on the command line.

.. code-block:: bash

   Rscript arg_script.R arg1 arg2 arg3

Your output is:

.. code-block:: bash

    jh1889@thalassa:~/work/teaching/SEPwC/code_examples$ Rscript command_args.R arg1 arg2 arg3
    [1] "arg1" "arg2" "arg3"
    [1] "Length: 3"

The arguments are stored in ``args``. The first is always the name of the script, however, we 
automaticlaly removed that by using the `trainlingOnly=True` argument. Try it without:

.. code-block:: bash

    jh1889@thalassa:~/work/teaching/SEPwC/code_examples$ Rscript command_args.R arg1 arg2 arg3
    [1] "/usr/lib/R/bin/exec/R" "--no-echo"             "--no-restore"         
    [4] "--file=command_args.R" "--args"                "arg1"                 
    [7] "arg2"                  "arg3"                 
    [1] "Length: 8"

Oh! That's not quite what we were expecting. You can see what `Rscript` actually does under the hood; it calls
the R command with `--no-echo`, `--no-restore` and the `--file` arguments, with the further `--args` argument. Only
then do we see our actual arguments. So best to leave `trailingOnly=TRUE`. 

Within our script we access them as we would any other list:

.. code-block:: R

    args = commandArgs(trailingOnly=TRUE)
    copy_from = args[1]
    copy_to = args[2]

.. warning::

   Security bugs in code are often due to user input not being **parsed** correctly. If your application 
   interacts with a database, for example, and the user can input which field to search, it may be possible
   to construct input which can then delete the database. You must always check what the user is giving you before
   using it, especially when it comes to files, databases, or URLs. 

.. admonition:: Practical exercise - simple command line arguments

    Write a simple R script to get all command line arguments given to it
    and print them out on individual lines. Do not include the script name or the other
    R specific things; just the user arguments.

.. admonition:: Solution
   :class: toggle

    .. code-block:: R

        args = commandArgs(trailingOnly=TRUE)
        count = 1
        for (arg in args) {
            print(paste0(count, " " , arg))
            count <- count + 1
        }


R advanced command line interface
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

R has a number of libraries that make command line parsing a lot easier and more functional. The most commonly used is
``argparse``

With ``argparse`` you define the options in your code and then ``argparse`` figures out how to get those from the ``commandArgs``
function. Moreover, the library will help with error messages, etc when the user gives incorrect arguments. 

The core functionality of ``argparse`` is the ``ArgumentParser``

.. code-block:: R

        library("argparse")
           

        parser = ArgumentParser(
                            prog="Name",
                            description="Brief one line of what the program does",
                            epilog="Any text at the bottom of help, e.g. copyright"
                            )

Once an OptionParser is set-up you can then add optional and positional arguments to that.

.. code-block:: R

    parser$add_option("filename"
                      help="the file to read the data from") # a positional argument
    parser$add_option('-c', '--count'
                      help="How many times to copy")         # option that takes a value
    parser$add_option('-v', '--verbose',
                      action='store_true',
                      help="Print progress")                 # on/off flag


You can also specify which variable the argument is parsered into, the type, if an argument is required, if it should be a list
and a lot more too.

You then parse the argument and put them in variables as you see fit

.. code-block:: R

    args = parser$parse_args()
    boundary_file = args$filename
    polygon_file = args$polygon
    default_PhysID = args$default_PhysID


.. admonition:: Practical exercise - more complex arguments

    Write a simple R script that returns the square of a given number, 
    e.g. if the users give 2, the program returns 4 to screen. 
    It must have the following arguments using `argparse`. 

     - an optional ``verbose`` flag, which can take an `int` value of 0, 1 or 2.
       This increases the verbosity of the output from just the number (`verbosity==0`)
       to a full sentence (`verbosity==2`), with default of 0.
     - restrict the input number to an integer only
     - add a check for negative numbers as input
     - optional output to a file

.. admonition:: Solution
   :class: toggle

    .. code-block:: R

        library(argparse)

        parser <- argparse.ArgumentParser()
        parser$add_argument("square", type=int,
                            help="display a square of a given number")
        parser$add_argument("-v", "--verbosity", type=int, choices=[0, 1, 2],
                            help="increase output verbosity", default=0)
        parse$add_argument("--output_file")
        args <- parser$parse_args()
        square <- args.square
        output_file <- args.output_file

        if (square <= 0) {
            print("Please provide a positive integer")
            exit()
        }
        answer <- square**2
        if (args$verbosity == 2) {
            print(paste0("The square of ",square, "equals ", answer))
        } else if (args.verbosity == 1) {
            print(paste0(square,"^2 == ",answer))
        } else {
            print(answer)
        }

        #if (output_file != NA) {
        #    with open(output_file, "w") as f: 
        #        f.write(f"The square of {square} equals {answer}\n")
        #}



Getting input from a user in R
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you want to ask the user something, e.g. a file name
or if they wish to continue, you can use the ``readLines`` function.
However, this is a bit hacky; it wasn't really design for this, so 
it works well enough, but for running within an ``Rscript`` *and* in the console
it needs some work. We point it at a "stdin" file (i.e. the keyboard) and
ask for a single line.

If you search online for how to read user input from keyboard in R you will find
reference to the ``scan``, ``readline`` and ``readlines`` functions. They all work 
well in an interactive environment, but not when running as a batch script via ``Rscript``.

.. code-block:: R

    answer <- readLines(file("stdin"),1)
    if (answer == "Y") {
        # do something
    } else if (answer == "N") {
        # do something else
    } else {
        print(paste0("I didn't understand ", answer))
    }

Note that the input is returned as a string, so you may need to convert 
to a floating point number or integer, etc. As with command line
arguments, be careful with any user input and check it carefully
before using it.

