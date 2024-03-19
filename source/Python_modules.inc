Python modules
---------------
..index::
  single: Modules; Python

When writing code we want to package up functionality/code into descrete bundles. In Python these are called modules or packages. 
You can then put this module on the internet such that other can download, install it and use it. You can also save your own code 
this way and use it in other code you write. 

We're not going to get into creating your own Python package/module here, but we will use Python modules a lot, so we will focus on using
modules, ratehr than creating them.

Import statement
~~~~~~~~~~~~~~~~~
..index::
  single: Importing; Python

To use an existing module or package in your code you must ``import`` it. 

Let's create a small script and save the file:


.. code-block:: python

    # Fibonacci numbers module

    def write_fibonacci(n):    # write Fibonacci series up to n
        a, b = 0, 1
        while a < n:
            print(a, end=' ')
            a, b = b, a+b
        print()

    def return_fibonacci(n):   # return Fibonacci series up to n
        result = []
        a, b = 0, 1
        while a < n:
            result.append(a)
            a, b = b, a+b
        return result

Write the above into a file called ``fibo.py`` and save it. In that same directory, open your interpreter and do:

.. code-block:: python

   import fibo

   fibo.write_fibonacci(1000)

   series = fibo.return_fibonacci(100)
   print(series)


You can see we import the code we have already written. We can then call the functions we added from that module. Note the ``.`` notation. 
A function is referred to via the original module ``.`` function name. This separates your current namespace from the module's.
You can assign this to a local variable is you wish:

.. code-block:: python

   import fibo

   fb = fibo.write_fibonacci

   fb(1000)

You can also import single functions or items from a module, rather than the whole module:

.. code-block:: python

   from fibo import write_fibonacci

   write_fibonacci(1000)

Note that I no longer need to use the ``.`` format to access that function. The function is imported into my current namespace. You can import the whole module into your namespace too:

.. code-block:: python

   from fibo import *

   write_fibonacci(1000)

This is generally not advised as it pollutes your namespace, but you will see this a lot!

We can also rename the module as we ``import`` it. This is very common for a number of popular modules:


.. code-block:: python

   import fibo as fib

   fib.write_fibonacci(1000)

You will often see:

.. code-block:: python

   import numpy as np

for example.

.. youtube:: 9mb4Xpau30o
   :align: center 

Executing modules as scripts
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
..index::
  pair: Modules as scripts; modules; Python

Python is a versatile language, so modules can also be scripts! Python has a special variable called ``__name__`` which is set to a value of ``__main__`` is a file is called as a script.

Running something like this in the command line:

.. code-block:: bash

   python fibo.py

will set this ``__name__`` variable to `__main__``.

Exercise: try this

We can make use of this to write a script within our module. Add the following code to the bottom of ``fibo.py``

.. code-block:: python

   if __name__ == "__main__":
      import sys
      write_fibonacci(int(sys.argv[1]))

The call the script directly via the command line:

.. code-block:: bash

   python fibo.py 10

You can, of course, still import the module as before and that code will not be run. This is really useful for running a test suite for example or
creating a structure of common functions across a number of projects/scripts.

Module search path
~~~~~~~~~~~~~~~~~~
..index::
  pair: Module Search Path; modules; Python

Where does Python look for modules? Python will look for modules in the following order:

  * The directory containing the input script (or current directory where no script is specified)
  * using the PYTHONPATH environment variable
  * The system default path

However, you can modify this as a programmer too. We can use the ``sys.path`` variable:

.. code-block:: python

   import sys
   sys.path.append("/home/jhill1/python/")

will add the directory to the end of that list above.


Seeing what is in a module
~~~~~~~~~~~~~~~~~~~~~~~~~~
..index::
  pair: Inside a Module; modules; Python

The built-in function ``dir()`` is used to find out which names a module defines. It returns a sorted list of strings:

.. code-block:: python
    
    import fibo, sys
    dir(fibo)
    ['__name__', 'return_fibonacci', 'write_fibonacci']
    dir(sys)  
    ['__breakpointhook__', '__displayhook__', '__doc__', '__excepthook__',
     '__interactivehook__', '__loader__', '__name__', '__package__', '__spec__',
     '__stderr__', '__stdin__', '__stdout__', '__unraisablehook__',
     '_clear_type_cache', '_current_frames', '_debugmallocstats', '_framework',
     '_getframe', '_git', '_home', '_xoptions', 'abiflags', 'addaudithook',
     'api_version', 'argv', 'audit', 'base_exec_prefix', 'base_prefix',
     'breakpointhook', 'builtin_module_names', 'byteorder', 'call_tracing',
     'callstats', 'copyright', 'displayhook', 'dont_write_bytecode', 'exc_info',
     'excepthook', 'exec_prefix', 'executable', 'exit', 'flags', 'float_info',
     'float_repr_style', 'get_asyncgen_hooks', 'get_coroutine_origin_tracking_depth',
     'getallocatedblocks', 'getdefaultencoding', 'getdlopenflags',
     'getfilesystemencodeerrors', 'getfilesystemencoding', 'getprofile',
     'getrecursionlimit', 'getrefcount', 'getsizeof', 'getswitchinterval',
     'gettrace', 'hash_info', 'hexversion', 'implementation', 'int_info',
     'intern', 'is_finalizing', 'last_traceback', 'last_type', 'last_value',
     'maxsize', 'maxunicode', 'meta_path', 'modules', 'path', 'path_hooks',
     'path_importer_cache', 'platform', 'prefix', 'ps1', 'ps2', 'pycache_prefix',
     'set_asyncgen_hooks', 'set_coroutine_origin_tracking_depth', 'setdlopenflags',
     'setprofile', 'setrecursionlimit', 'setswitchinterval', 'settrace', 'stderr',
     'stdin', 'stdout', 'thread_info', 'unraisablehook', 'version', 'version_info',
     'warnoptions']


