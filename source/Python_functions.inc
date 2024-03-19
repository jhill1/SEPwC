Python functions 
--------------------
.. index::
  single: Functions; Python

Whenever you write some code you get tempted to copy and paste a block, change a variable, and have two nearly
identical blocks of code, bar one variable. Might be OK with a single repeat, but what if you then need to
do that 10 times, or 100 times, or a million times?

This is where functions come in. You can generalise a bit of code and package it up so you can call it
repeatedly. That might be within the same script; it might be part of many scripts.

Using a Python function
~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: len(); Python

We've used a number of Python functions already. 

.. code-block:: python

   print("Hello")
   range(0,len(my_list),1)

The first thing to note is that a function is called with `()` parentheses. Sometimes it gives back 
a value (called "returning a value"), sometimes it does not. Sometimes there are things in between the
parentheses, sometimes not (these are called "arguments").

So using, or calling, a Python function is easy. Give the function name, open the brackets, add any arguments you need (separated by commas),
close your brackets, if you are expecting a number back, store it:

.. code-block:: python

   return_value = function_name(arg1, arg2, arg3)

As we've seen already you can nest functions within other functions!

.. code-block:: python

   range(0,len(my_list),1)

.. index::
  single: range(); Python

Here, we're calling the `range` function to go from `0` to the length of my_list (`len(my_list)`) in steps of 1. But `len()` is 
also a function. The return value of `len(my_list)` gets put in place of that bit of code. This is exactly equivalent of doing:

.. code-block:: python

   length = len(my_list)
   range(0,length,1)

where we store the length in a variable, then use it.

.. index::
   single: Nested functions; Python

.. admonition:: Practical exercise

   **Nested functions**

    Write a single line of code to print the length of a list (which has the variable name `my_list`)

.. admonition:: Solution
   :class: toggle

   .. code-block:: python

      print(len(my_list))

   We call the `len()` function inside of the `print()` function.

.. youtube:: jA5KYi6fjdg
    :align: center
    

Writing your own Python functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Whilst it's all well and good to use functions, you will need to write them too. Python allows you to create your own functions

They follow this pattern:

.. code-block:: python

   def function_name(arg1, arg2, arg3):

       # do what you need to do

       return 

The key thing are the keyword `def` followed by the name of your function and the arguments expected, then a a `:`. Next comes your
function body (indented; remember whitespace matters!). At the end of your function, use the `return` keyword (with a value if you want
to return something).

Rather than staying abstract, let's do something more concrete. Let's write a function to convert from Centigrade to Fahrenheit. 

.. code-block:: python

   def toFahrenheit(Centigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

This function takes a value (Centigrade) and converts it to Fahrenheit, returning that number. We would use it something like this:


.. code-block:: python

   def toFahrenheit(Centigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

   water_freezing = toFahrenheit(0)
   print("Water freezes at " + str(toFahrenheit(0)) + " deg F")



Function arguments in Python
.............................
.. index::
  single: Function Arguments; Python

A function can take any number of inputs via arguments. You can even specify an unknown number of arguments. This are either keyword arguments (kwargs) or generic arguments (args).

Above we used a keyword argument, which gave us the variable name inside the function. Here is an example where the function takes
two keyword arguments:

.. code-block:: python

   def print_greeting(greeting, name):

       print(greeting+", "+name+"!")

       return

   print_greeting("Hello", "Bryan")

You can see that by specifying two arguments in the function declaration we have access to those values inside the function.
What happens if the user supplies only a single argument, not two as we've asked? Try the code below:


.. code-block:: python

   def print_greeting(greeting, name):

       print(greeting+", "+name+"!")

       return

   print_greeting("Hello")

What error message did you get?

.. admonition:: Check your answer
   :class: toggle


   .. code-block:: python
     
      TypeError     Traceback (most recent call last)
      Cell In [1], line 7
            3     print(greeting+", "+name+"!")
            5     return
      ----> 7 print_greeting("Hello")

      TypeError: print_greeting() missing 1 required positional argument: 'name'
      

We can also write functions that have default values.

.. index::
   single: Default Value Functions; Python

.. code-block:: python

   def print_greeting(name, greeting="Hello"):

       print(greeting+", "+name+"!")

       return

   print_greeting("Bryan")

When running this, we can give the ``name`` argument and we get a default ``greeting``. We could also set the ``greeting`` ourselves:

.. code-block:: python

   def print_greeting(name, greeting="Hello"):

       print(greeting+", "+name+"!")

       return

   print_greeting("Bryan", "Ey-up")

However, you may note I've switched the order of the arguments around. What happens if we didn't?

.. code-block:: python

   def print_greeting(greeting="Hello", name):

       print(greeting+", "+name+"!")

       return

   print_greeting("Bryan")

.. admonition:: Check your answer
   :class: toggle


   .. code-block:: python
     
      Cell In [5], line 1
        def print_greeting(greeting="Hello", name):
                       ^
      SyntaxError: non-default argument follows default argument

Python tells us that we have a syntax error and to swap the arguments around.

I mentioned earlier that you could pass an arbitrary number of arguments into a python function. This isn't used very often, but you will see it
in a few places when using Python. Let's think about a function to add some numbers together:

.. code-block:: python

   def sum_numbers(x,y,z):
      print("sum:",x+y+z)

   sum_numbers(1,2,3)

This prints:

.. code-block:: bash

   sum: 6

What if we wanted to add 9 numbers together? Or 1 million? This is where ``*args`` comes in. ``*args`` gives us an argument list of any length:

.. code-block:: python

   def sum_numbers(*numbers):
      
      sum = 0
      for n in numbers:
         sum = sum + n

      print("sum:", sum)

   sum_numbers(1,2,3)

This gives us the same result as last time, but we can also do:

.. code-block:: python

   def sum_numbers(*numbers):
      
      sum = 0
      for n in numbers:
         sum = sum + n

      print("sum:", sum)

   sum_numbers(1,2,3)
   sum_numbers(1,2,3,4,5,6,7,8,9,1000)
   sum_numbers(5,7)

Inside the function, the argument is represented by a tuple. We can therefore iterate over this and write code accordingly. We can also force
keyword arguments using a similar approach called ``**kwargs``.

.. code-block:: python

    def intro(**data):
        print("\nData type of argument:",type(data))

        for key, value in data.items():
            print("{} is {}".format(key,value))

    intro(Firstname="Sita", Lastname="Sharma", Age=22, Phone=1234567890)
    intro(Firstname="John", Lastname="Wood", Email="johnwood@nomail.com", Country="Wakanda", Age=25, Phone=9876543210)

Note that the ``**kwargs`` requires a keyword (which can be anything) and a value (which can be anything). Inside the function this is presented as a dictionary.


