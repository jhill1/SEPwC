Python: command line arguments
-------------------------------

.. index::
   pair: command line arguments; python

The simplest user-facing scripts/software use the Command Line Interface (CLI) to interact with a user.
The CLI allows the user to pass options to a script as they execute. We have already used these elsewhere
in the course, for example:

.. code-block:: bash
   :caption: |cli|

   ls -l

which is the command to list things, ``ls``, in a Unix shell with the option supplied to make it a table ``-l``.
Similarly, we've covered:

.. code-block:: bash
   :caption: |cli|
   
   cp -r dir1 dir2

Here, there are three options. The ``-r`` flag, the directory to copy ``dir1``, and where to copy it to, ``dir2``.

Python has both in-built handling of command line options, but also a number of modules to give us quite
advanced usage options.

Python and the command line
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
   pair: command line; python


When you run a Python script, with some arbitrary text after:

.. code-block:: bash
   :caption: |cli|

   python arg_script.py arg1 arg2 arg3

that text is passed to the ``sys`` module in Python. Let's create this simple script, named ``arg_script.py``

.. code-block:: python
   :caption: |python|

   import sys

   print("Argument list", str(sys.argv))
   print("Length: ", len(sys.argv))

Now run that on the command line.

.. code-block:: bash
   :caption: |cli|

   python arg_script.py arg1 arg2 arg3

Your output is:

.. code-block:: bash
    :caption: |cli|

    Length: 4 
    Argument List: ['arg_script.py', 'arg1', 'arg2', 'arg3']

The arguments are stored in ``sys.argv``. The first is always the name of the script. The rest
are what the user has given. These could be files or options of some kind (e.g. keywords).
Within our script we access them as we would any other list:

.. code-block:: python
   :caption: |python|

   import sys

   copy_from = sys.argv[1]
   copy_to = sys.argv[2]

.. warning::

   Security bugs in code are often due to user input not being **parsed** correctly. If your application 
   interacts with a database, for example, and the user can input which field to search, it may be possible
   to construct input which can then delete the database. You must always check what the user is giving you before
   using it, especially when it comes to files, databases, or URLs. 

.. admonition:: Practical exercise - simple command line arguments

    Write a simple python script to get all command line arguments given to it
    and print them out on individual lines. Do not include the script name.

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        import sys

        count = 1
        # note the 1:, I'm skipping the 0-th element!
        for arg in sys.argv[1:]:
            print(str(count) + " " + arg)
            count =+ 1


Python advanced command line interface
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: argarse; python

Python has a number of modules that make command line parsing a lot easier and more functional. The most commonly used is
``argparse``

With ``argparse`` you define the options in your code and then ``argparse`` figures out how to get those from the ``sys.argv``. Moreover,
the module will help with error messages, etc when the user gives incorrect arguments. 

The core functionality of ``argparse`` is the ``ArgumentParser``

.. code-block:: python
   :caption: |python|

   import argparse

   parser = argparse.ArgumentParser(
                        prog="Name",
                        description="Brief one line of what the program does",
                        epilog="Any text at the bottom of help, e.g. copyright"
                        )

Once an ``ArgumentParser`` is set-up you can then add optional and positional arguments to that.

.. code-block:: python
    :caption: |python|

    parser.add_argument("filename"
                        help="the file to read the data from") # a positional argument
    parser.add_argument('-c', '--count'
                        help="How many times to copy")         # option that takes a value
    parser.add_argument('-v', '--verbose',
                        action='store_true',
                        help="Print progress")                 # on/off flag


You can also specify which variable the argument is parsed into, the type, if an argument is required, if it should be a list
and a lot more too.

You then parse the argument and put them in variables as you see fit

.. code-block:: python
    :caption: |python|

    args = parser.parse_args()
    boundary_file = args.filename
    polygon_file = args.polygon
    default_PhysID = args.default_PhysID


.. admonition:: Practical exercise - more complex arguments

    Write a simple python script that returns the square of a given number, 
    e.g. if the users give 2, the program returns 4 to screen. 
    It must have the following arguments using ``argparse``. 

     - an optional ``verbose`` flag, which can take an ``int`` value of 0, 1 or 2.
       This increases the verbosity of the output from just the number (`verbosity==0`)
       to a full sentence (`verbosity==2`), with default of 0.
     - restrict the input number to an integer only
     - add a check for negative numbers as input
     - optional output to a file

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        import argparse
        import sys

        parser = argparse.ArgumentParser()
        parser.add_argument("square", type=int,
                            help="display a square of a given number")
        parser.add_argument("-v", "--verbosity", type=int, choices=[0, 1, 2],
                            help="increase output verbosity", default=0)
        parse.add_argument("--output_file")
        args = parser.parse_args()
        square = args.square
        output_file = args.output_file

        if square <= 0:
            print("Please provide a positive integer")
            sys.exit(-1)
        answer = square**2
        if args.verbosity == 2:
            print(f"the square of {square} equals {answer}")
        elif args.verbosity == 1:
            print(f"{square}^2 == {answer}")
        else:
            print(answer)

        if output_file != None:
            with open(output_file, "w") as f: 
                f.write(f"The square of {square} equals {answer}\n")



Getting input from a user in Python
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: input; python

If you want to ask the user something, e.g. a file name
or if they wish to continue, you can use the ``input`` function.

.. code-block:: python
    :caption: |python|

    answer = input("Do you wish to continue (Y/N)?")
    if answer == "Y":
        # do something
    elif answer == "N":
        # do something else
    else:
        print("I didn't understand " + answer)

Note that the input is returned as a string, so you may need to convert 
to a floating point number or integer, etc. As with command line
arguments, be careful with any user input and check it carefully
before using it.

