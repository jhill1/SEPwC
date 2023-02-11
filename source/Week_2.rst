The basics of code
===================

Some terminology
----------------

Computer programming is full of jargon. Fortunately, most of the jargon is comoon across all
languages. The idea of this chapter is to cover those basics so that when we get to a language
we can focus on the language, rather than also learning the jargon!  In this chapter we're going to use pseudo-code. This is code-like text that is easier to read. 
There is no fixed syntax (you can make up your own!) and it's designed for us to read. 

Variable: a variable is a container where you store something. You decide what that variable is called and what you put in it.
Most variables in interpreted languages are defined when you use them first time. In compilde language you need to decide
up-front which variables you need. Variables can change what they store throughout the code.

Constant: a bit of data that never changes throughout the code, unlike a variable.

Operations: an operation takes place between two things. These things could be variables, constants (or anything else in that language). 

Datatype: the type of data held by a variable. A floating point number (1.342), an integer (2), a string ("silly_string"), a character ("c"), 
or any other thing that can be defined. 

Outputs: what you code spits out. A line of text onto the screen, an image, a file, a noise!

Inputs: what you code needs to run. This can be "hardcoded" or you can ask the user to supply it.


Loops: code often needs to do the same thing on a long list of data. We often use loops to do this. Loops can be nested (i.e. a loop within a loop)

Conditionals: you often run a bit of code if a certain condition is met, for example if the variable contains a number greater than 5, do this, otherwise do that.
This creates a logic flow to your code and allows decisions to be made.

Functions: if you find yourself doing the same few line sof code again, and again, we don't type them out repeatedly, we instead create a function which 
we can call every time we want to run those lines. Functions take input (called arguments) and return data back to the main program (where you can store it
in a variable, for example).


Defining a variable
--------------------


Some examples:

my_data = 1, 2, 3, 5, 19, 18
I've create a variable called ``my_data`` which contains a list of numbers.

my_favourite_number = 7

This varibale contains a single number, 7.


pi = 3.14159
This variable contains the number for \pi to five decimal places.

name = "Jon"

This variable contains text.

loaded_data = load_csv_file("mega_data_set.csv")

This variable contains whatever the "mega_data_set.csv" file contains.



Operations
----------


Datatypes
---------



Outputs
-------

Inputs
------


Loops
-----


Conditionals
------------



Functions
---------
