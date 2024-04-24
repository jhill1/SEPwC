Solving issues and debugging
=============================

When writing code you will inevitably get it wrong occasionally. You will therefore always hit some 
issues when writing any code. Some issues are easy to fix (you've typo'd a library or module), whilst some are 
extremely difficult to fix (a bug deep in a library that is used by a library you use). Here, we're going to concentrate on what kind of issues
you might come across and how you might go about understanding them.

The same kind of issues will crop up for both Python and R. I will give examples of both as we go through.

Types of issues
----------------

There are several types of issues you will come across:

 - warnings: These are not errors. They could be anything from "this code will go out of date in 10 years time" 
   to "you haven't set something you should have. This may not work". Read it carefully and decide if you need to care or not.
 - errors: These are errors and you need to fix them. R and Python will tell you where the error is and often how to fix it. 
   These are your problem to deal with.
 - bugs: These are also errors and you also need to fix them. However, you may get no warnings, or message, just output you 
   didn't expect! A bug is simply unexpected behaviour. It is usually your problem to deal with, however, it is possible 
   the bug is in a library you're using. We will learn how to report these kind of issues if we need to.
 - seg faults: This is a major error in the code. A segmentation fault (or seg fault) is usually caused by accessing memory 
   you shouldn't have access to. In Python and R these are very rare as memory allocation is handled for us, rather than by 
   us. However, libraries like numpy use C and hence we could experience one of these.

Simple issues
--------------

The majority of issues encountered when writing code are really straight forward. You have messed up the syntax, or typo'd a library name, etc. 
This happens a lot. As someone who has used dozens of programming languages over the years I often mix them up and type some weird hybrid
of R, Python, Perl, PHP and/or Matlab. Possibly with a bit of Fortran and C in there too. Each language has it's own idiosyncrasies which you 
will get used to. In addition, it's very easy to type a ``[`` instead of a ``{``. 

What makes these errors simple though is that you are told about them when you run the code!
Sometimes a bit obscurely, but once you can decipher the error message they are easy to fix.

.. include:: R_syntax_errors.inc
.. include:: python_syntax_errors.inc


Warning examples
~~~~~~~~~~~~~~~~

Warnings are noncritical messages, normally issued by a library or module you're using. However, most of the time
they are an error (as in you're getting the wrong answer) but the code can still continue. You should therefore
pay attention and decide if you do need to care.

R warning examples
''''''''''''''''''

.. code-block:: R
    :caption: |R|

    cor( c( 1 , 1 ), c( 2 , 3 ) )
    [1] NA
    Warning message:
    In cor(c(1, 1), c(2, 3)) : the standard deviation is zero

Here, the user has tried to perform a correlation with 2 points. The warning shows this isn't a good idea, 
but the ``cor`` function could produce an answer (albeit ``NA``).

Python warning example
'''''''''''''''''''''''

In this example I divide by zero; mathmatically producing infinity.

.. code-block:: Python
    :caption: |python|

    import numpy as np
    np.array([1])/0
    <ipython-input-2-f6baf8772c4a>:1: RuntimeWarning: divide by zero encountered in divide
       np.array([1])/0
    Out[2]: array([inf])

Note I get a ``RuntimeWarning`` which gives a message and the line of code. I still get an answer, 
here, ``inf``.

It's unlikely I actually wanted that, but I would need to work out a way of dealing with this if the
numbers were supplied by a user or in the data. The warnings can therefore be very useful!

.. admonition:: Practical exercise

    Try the following codes and check you understand the warning or error.

    .. code-block:: Python
        :caption: |python|

        list_of_URLs = (
         'https://example.com/1',
         'https://example.com/2",
         'https://example.com/3
         )
        print(list_of_URLs)

    .. code-block:: R
        :caption: |R|

        list_of_URLs = c(
         'https://example.com/1',
         'https://example.com/2",
         'https://example.com/3
         )
        print(list_of_URLs)

    .. code-block:: Python
       :caption: |python|

        user = 'username1'
        pass = 'password1'

    .. code-block:: R
        :caption: |R|

        first = 'Mercedes'
        next = 'Aston Martin'

    .. code-block:: Python
        :caption: |python|

        print(100 is 100)

    .. code-block:: R
        :caption: |R|

        x <- 1:10000
        x      

..  admonition:: Solution
    :class: toggle

    The first example (R and Python) contains two errors. 'https://example.com/2" uses different
    quote marks to start and end. If you fixed that, there then a missing ' at the 
    end of the third URL. 

    The second set of examples (R and Python) both use *reserved words*. You cannot use those
    for variable names.

    The final two examples issue warnings. The Python example checks you meant `is` not `==`.
    The R example prints a wanring about max.print (i.e. you've printed too much!). We can 
    alter that.


..  youtube:: QsEjIjzkpGM
    :align: center


Bugs
------

Bugs are errors in the code that result in incorrect output or the program to fail. In other words
they are unintentional behaviours of the code. With ever more complex software being developed which uses
a stack of other libraries to create the functionality making sure your code is bug free is getting harder
but yet more important. It's also important to note that bugs are always introduced by programmers; they 
don't manifest themselves!

There are a number of different categories of bugs:

 * Arithmetic: dividing by zero, creating a number larger than the computer can handle, loss of precision etc
   can all introduce bugs
 * Control flow: your logic may not be correct, so the program goes into a branch not expected.
 * Interfacing: If you use other libraries (which you will!) you can pass incorrect data to them. This 
   is particularly challenging when a library updates on a system and the interface (called the 
   Application Programming Interface or API) changes. 
 * Concurrency: when using more than one core or using threads you can end up deadlocking (nothing runs) or 
   a race condition (wrong order) etc. Parallel programming is very hard because of this.
 * Resource bugs: Using an initialised variable or a null pointer. This are actually quite hard to generate in 
   interpreted languages like Python and R. 
 * Syntax: Using ``x==5`` rather than ``x=5`` can be valid syntax but not what you expected. Again, in 
   interpreted languages this is hard to do as you get an error or warning.
 * Human: When working in teams it is really important to communicate and use tests. It is very easy to 
   add bugs by not updating comments, not documenting code correctly and duplicating code.

Of special note are security bugs. These will not be of major concern to us, but if you develop something 
that interacts with both a computer and the internet this can cause severe damage. They generally come
about by not checking user input fully. So rather than running a query on a databse the user supplied
code deletes the entire database.

Reporting a bug
~~~~~~~~~~~~~~~~

One of the best ways of giving back to the open souce community is to report bugs when you
come across them. As a beginner programmer it's more likely that the error is in your code
rather than a well used library like ``matplotlib`` or ``ggplot2``. However, you may well 
find the odd bug as you go.

When reporting a bug you need to give enough information for the developer to recreate the problem.
The most useful thing to provide is an example code which is as small as possible; a
minimum reproducible example or MRE. You would take your failing code and strip away anything
that is not associated with the bug. You should then describe the error/issue, and give details
of your set-up, including Python or R version, your operating system and what you expected to happen.

What are come examples of bugs? They are actually quite easy to find as most of R and Python modules
and libraries are open source and hence issues/bugs are reported.

Here is an example of a bug in matplotlib:

.. image:: ../images/example_bug.png
   :alt: Screenshot of an example bug on github.

It always worth searching the Open and Closed bugs to see if your issue is there first.

.. admonition:: Practical exercise

    **Reproducing a bug**

    Find a bug on github for an R or Python package/library which has an MRE.

    Can you replicate the bug and the error message?

    `Here's an example for R using tsibble. <https://github.com/tidyverts/tsibble/issues/300>`_

    `Here's an example for Python. <https://github.com/numpy/numpy/issues/24593>`_


.. youtube:: QQpnNc5OrAk
    :align: center

.. youtube:: NotnvtJUDCI
    :align: center


Fixing Errors
-------------

We have discussed how to get an error, warning or bug, but so far we can't fix them!

The first thing it to read it carefully, using the stack trace or traceback and try to 
understand it yourself. If you can't figure it out, then you can try searching for the 
error message on the internet. Copy and paste the error removing any filepaths.

Try the following:

.. code-block:: Python
    :caption: |cli| |python|

    import pandas as pd
    df = pd.DataFrame({'x':['1.0692e+06']})
    df['x'].astype('int')

    ValueError: invalid literal for int() with base 10: '1.0692e+06'

The error is much longer than I gave here, but try copying and pasting the lower part into a search 
engine and you will hopefully find a page with some answers on what the error is and even how to fix it.
Note that I have not copied any of the specific parts of the error in a search, e.g.:

.. code-block:: python
    :caption: |cli| |python|

    File ~/.local/lib/python3.8/site-packages/pandas/core/dtypes/cast.py:1154, in astype_nansafe(arr, dtype, copy, skipna)
       1150 elif is_object_dtype(arr.dtype):
       1151 
       1152     # work around NumPy brokenness, #1987
       1153     if np.issubdtype(dtype.type, np.integer):
    -> 1154         return lib.astype_intsafe(arr, dtype)
       1156     # if we have a datetime/timedelta array of objects
       1157     # then coerce to a proper dtype and recall astype_nansafe
       1159     elif is_datetime64_dtype(dtype):

    File ~/.local/lib/python3.8/site-packages/pandas/_libs/lib.pyx:668, in pandas._libs.lib.astype_intsafe()

You'll note that they are specific to the version of Python I'm using and to where pandas is installed, and even the
OS I'm using. Anyone using Windows, Python 3.11 and a version of pandas installed via Anaconda will have very
different paths to mine! Search engines aren't that good...

The above example is also a good example of the fact this is *your* error. It is not a bug in the pandas library.
The code creates a number as a string that cannot be converted into an int (as it's a floating point number). 

Let's do an example in R now.

.. code-block:: R
    :caption: |cli| |R|

    df <- data.frame(Date=as.Date(character()),
                 country=factor(), 
                 total=numeric(), 
                 stringsAsFactors=FALSE) 

    df$total <- 7

    Error in `$<-.data.frame`(`*tmp*`, total, value = 7) : 
        replacement has 1 row, data has 0

I would copy and paste the error, replacing some terms, something like 
``Error in `$<-.data.frame`(`*tmp*`, total, replacement has 1 row, data has 0``
a number of website come up which help understand the error message a bit more. 

.. include:: debugging.inc

