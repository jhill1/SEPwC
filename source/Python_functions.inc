Python functions 
--------------------

Whenever you write some code you get tempted to cpoy and paste a block, change a variable, and have two nearly
identical blocks of code, bar one variable. Might be OK with a single repeat, but what if you then need to
do that 10 times, or 100 times, or a million times?

This is where functions come in. You can generalise a but of code and package it up so you can call it
repeatedly. That might be within the same script; it might be as part of many scripts.

Using a Python function
~~~~~~~~~~~~~~~~~~~~~~~~

We've used a number of Python functions already. 

.. code-block:: python

   print("Hello")
   range(0,len(my_list),1)

The first thing to note is that a function is called with `()` parenthesies. Sometimes it gives back 
a value (called "returning a value"), sometimes it doesn not. Sometimes there are things inbetween the
parantheses, sometimes not (these are called "arguments").

So using, or calling, a Python function is easy. Give the function name, open the brackets, add any arguments you need (seperated by commas),
close your brackets, if you are expecting a number back, store it:

.. code-block:: python

   return_value = function_name(arg1, arg2, arg3)

As we've seen already you can nest functions within other functions!

.. code-block:: python

   range(0,len(my_list),1)

Here, we're calling the `range` function to go from `0` to the length of my_list (`len(my_list)`) in steps of 1. But `len()` is 
also a function. The return value of `len(my_list)` gets put in place of that bit of code. This is eaxtly equivlant of doing:

.. code-block:: python

   length = len(my_list)
   range(0,length,1)

where we store the length in a variable, then use it.

.. admonition:: Practical exercise

   **Nested functions**

    Write a single line of code to print the length of a list (which has the variable name `my_list`)

.. admonition:: Solution
   :class: toggle

   .. code-block:: python

      print(len(my_list))

   We call the `len()` function inside of the `print()` function.

Writing your own functions
~~~~~~~~~~~~~~~~~~~~~~~~~~

Whilst it's all well and good to use functions, you will need to write them too. Python allows you to create your own functions

They follow this pattern:

.. code-block:: python

   def function_name(arg1, arg2, arg3):

       # do what you need to do

       return 

The key thing are the keyword `def` folloed by the name of your function and the arguments expected, then a a `:`. Next comes your
function body (indented; remember whitespace matters!). At the end of your function, use the `return` keyword (with a value if you want
to return something).

Rather than staying abstract, let's do something more concrete. Let's write a function to convert from Centigrade to Farenheit. 

.. code-block:: python

   def toFarenheit(Centrigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

This function takes a value (Centrigrade) and converts it to Farenheit, returning that number. We would use it something like this:


.. code-block:: python

   def toFarenheit(Centrigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

   water_freezing = toFarenheit(0)
   print("Water freezes at " + str(toFarenheit(0)) + " deg F")



