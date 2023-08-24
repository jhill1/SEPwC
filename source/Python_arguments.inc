Python: command line arguments
-------------------------------

The simplest user-facing scripts/software use the Command Line Interface (CLI) to interact with a user.
The CLI allows the user to pass options to a script as they execute. We have already used these elsewhere
in the course, for example:

.. code:: bash

   ls -l

which is the command to list things, ``ls``, in a Unix shell with the option supplied to make it a table ``-l``.
Similaraly, we've covered:

.. code:: bash

   cp -r dir1 dir2

Here, there are three options. The ``-r`` flag, the directory to copy ``dir1``, and where to copy it to, ``dir2``.

Python has both in-built handling of command line options, but also a number of modules to give us quite
advanced usage options.

Python and the command line
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

When you run a Python script, with some arbitrary text after:

.. code:: bash

   python arg_script.py arg1 arg2 arg3

that text is passed to the ``sys`` module in Python. Let's create this simple script, named ``arg_script.py``

.. code:: bash

   import sys

   print("Argument list", str(sys.argv))
   print("Length: ", len(sys.argv))

Now run that on the command line.

.. code:: bash

   python arg_script.py arg1 arg2 arg3

Your output is:

.. code:: bash

    Length: 4 
    Argument List: ['arg_script.py', 'arg1', 'arg2', 'arg3']

The arguments are stored in ``sys.argv``. The first is always the name of the script. The rest
are what the user has given. These could be files or options of some kind (e.g. keywords).
Within our script we access them as we would any other list:

.. code:: python

   import sys

   copy_from = sys.argv[1]
   copy_to = sys.argv[2]



