R libraries
------------

When writing code we want to package up functionality/code into discrete bundles. In R these are called libraries or packages. 
You can then put this library on the internet such that other can download, install it and use it. You can also save your own code 
this way and use it in other code you write. 

We're not going to get into creating your own R package/module here, but we will use R libraries a lot, so we will focus on using
libraries, rather than creating them.

Loading libraries
~~~~~~~~~~~~~~~~~~

Libraries are loaded via either the ``library`` or ``require`` functions.

.. code-block:: R

    library(ggplot2)

will load the ggplot2 library and namespace into your current code. It will also load any other libraries that are required. If the library cannot be found, the code will stop executing.

R then allows you to call any functions within that library. Technically R does a search for functions so you may have two functions of the same name (e.g. ``sum()``) so R has syntax to make sure it uses the correct one; the ``::`` notation. For example both ``dplyr`` and ``base`` contain a function ``intersect()``. To make sure you call the correct one:

.. code-block:: R

    library(dplyr)

    dplyr::intersect()

This can be good practice throughout your code, but requires some care and attention.


Sourcing other code
~~~~~~~~~~~~~~~~~~~~


You can also include the contents of another script directly into your own using the ``source`` function.

.. code-block:: R

   source("common_funcs.R")

would load the contents of a files "common_funcs.R" into the current environment. R assumes this script is in the current directory. 

This can allow you to build a library of common functions, but not make them into a full package. Unlike the ``library()`` function this does not allow you to use namespaces to separate out functions or variables.
