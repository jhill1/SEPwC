R functions 
---------------

Functions are blocks of code that can be called frequently. Rather than copy and paste the same block of 
code which is identical apart from a single variable you can instead create a function.

You pass data to a function in the form of parameters and it returns a result or performs a task successfully.


Using a R function
~~~~~~~~~~~~~~~~~~~~~~~~

We've used a number of R functions already. 

.. code-block:: R

   print("Hello")
   print(paste(time, vert_position))

The first thing to note is that a function is called with `()` parentheses. Sometimes it gives back 
a value (called "returning a value"), sometimes it does not. Sometimes there are things in between the
parentheses, sometimes not (these things are called "arguments").

So using, or calling, a R function is easy. Give the function name, open the brackets, add any arguments you need (separated by commas),
close your brackets, if you are expecting a number back, store it:

.. code-block:: R

   return_value = function_name(arg1, arg2, arg3)

As we've seen already you can nest functions within other functions!

.. code-block:: R

   print(paste("hola",length(my_list),"long")

Here, we're calling the `print` function to print out the result of the ``paste`` function, which pastes together a string, the ``length`` of a list
and another string. Three functions nested within each ohter. This is equivalent of:

.. code-block:: R

   len <- length(my_list)
   message <- paste("hola",len,"long")
   print(message)

.. admonition:: Practical exercise

   **Nested functions**

    Write a single line of code to print the ``log10`` of a 1000

.. admonition:: Solution
   :class: toggle

   .. code-block:: R

      print(log10(1000))

   We call the `log10()` function inside of the `print()` function.

Writing your own R functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Whilst it's all well and good to use functions, you will need to write them too. R allows you to create your own functions

They follow this pattern:

.. code-block:: R

   print_hello <- function() {
      print("Hello!")
   }

The name of of the function above is ``print_hello``. The function keyword tells R this is a function and the content between the ``{   }`` is the function body.

We can then call this function in out main code:

.. code-block:: R

    my_function <- function() {
        print("Hello World!")
    }

    my_function() # call the function named my_function

We type the name of the function, followed by parentheses. 

Functions are useful when we can pass data into them. We do this via arguments:

.. code-block:: R

    greetings <- function(fname) {
        paste0("Hello ",fname,"!")
    }

    greetings("Hughie")
    greetings("Louie")
    greetings("Dewie")


Rather than staying abstract, let's do something more concrete. Let's write a function to convert from Centigrade to Farenheit. 

.. code-block:: R

   toFahrenheit <- (Centigrade) {

       F = 9.0/5.0*Centigrade + 32.0

       return(F)
   }

This function takes a value (Centigrade) and converts it to Fahrenheit, returning that number. We would use it something like this:


.. code-block:: R

   toFahrenheit <- function(Centigrade) {

       F = 9.0/5.0*Centigrade + 32.0

       return(F)
   }

   # store the number
   water_freezing = toFahrenheit(0)
   
   # nested functions to print it
   print(paste("Water freezes at ",toFahrenheit(0)," deg F")


Function arguments in R
..........................

A function can take any number of inputs via arguments. You can even specify an unknown number of arguments

Above we used a keyword argument, which gave us the variable name inside the function. Here is an example where the function takes
two keyword arguments:

.. code-block:: R

   print_greeting <- function(greeting, name) {

       print(paste(greeting,", ",name,"!"))

       return
    }

   print_greeting("Hello", "Bryan")

You can see that by specifying two arguments in the function declaration we have access to those values inside the function.
What happens if the user supplies only a single argument, not two as we've asked? Try the code below:


.. code-block:: R

   print_greeting <- function(greeting, name) {

       print(paste(greeting,", ",name,"!"))

    }

   print_greeting("Hello")


What error message did you get?

.. admonition:: Solution
   :class: toggle

   .. code-block:: R
     
      Error in print_greeting("Hello") : 
      argument "name" is missing, with no default 

We can also write function that have default values.

.. code-block:: R

   print_greeting <- function(name, greeting="Hello") {

       print(paste(greeting,", ",name,"!"))

    }

   print_greeting("Bryan")

When running this, we can give the ``name`` argument and we get a default ``greeting``. We could also set the ``greeting`` ourselves:

.. code-block:: R

   print_greeting <- function(name, greeting="Hello") {

       print(paste(greeting,", ",name,"!"))
    }

   print_greeting("Bryan", "Ey-up")

However, you may note I've switched the order of the arguments around. What happens if we didn't?

.. code-block:: R

   print_greeting <- function(greeting="Hello", name) {

       print(paste(greeting,", ",name,"!"))

    }

   print_greeting("Bryan")

.. admonition:: Solution
   :class: toggle

   .. code-block:: R
     
      Error in print_greeting("Hello") : 
      argument "name" is missing, with no default 

R tells us that we have forgotten to give an argument as ``name`` is missing. 

