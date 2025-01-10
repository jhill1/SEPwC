R examples
~~~~~~~~~~
.. index:: 
   pair: syntax; R

If we make an error in our R code we will receive a message like:

.. code-block:: R
    :caption: |R|

    libary(ggplot2)
    
gives

.. code-block:: bash
    :caption: |R|

    Error in libary(ggplot2) : could not find function "libary"

Note R doesn't tell us what the mistake is, just that it couldn't find a function called ``libary`` which is a 
typo (and should be ``library``). We'll get similar messages if we typo a variable name (``object not found``).
This can be frustrating, especially if the typo is not easy to spot! It's also frustrating that R does not often 
tell you the line number or give you an indication of where the error is.

Some common messages you will see and their meaning:

 * **Object not found**: a variable name is mistyped - remember they are case-sensitive
 * **Cannot open the connection**: a filename or path is not correct
 * **subscript out of bounds**: You tried to access a vector or data.frame with a subscript that doesn't exist
 * **non-numeric argument to a binary operator**: R is expecting a number. You've given it something else (a vector, a string?)
 * **unexpected symbol**: You've forgotten a ``(`` or a ``,`` or similar.

So if R is a bit annoying and doesn't tell you where the error is precisely, can you do anything about that? Yes!
R does contain a function called ``traceback`` that goes back up your code to the error.

.. code-block:: R
    :caption: |R|

    f <- function(x) x + 1
    g <- function(x) f(x)
    g("a")

Will give a "non-numeric" error. Try typing ``traceback()``

.. code-block:: R
    :caption: |R|

    traceback()

to give:

.. code-block:: bash
    :caption: |cli| |R|

    2: f(x) at #1
    1: g("a")

So we now know it was the g("a") causing the issue and the error occurred in the f function
