The basics of code
===================

Some terminology
----------------

Computer programming is full of jargon. Fortunately, most of the jargon is comoon across all
languages. The idea of this chapter is to cover those basics so that when we get to a language
we can focus on the language, rather than also learning the jargon!  In this chapter we're going to use pseudo-code. This is code-like text that is easier to read. 
There is no fixed syntax (you can make up your own!) and it's designed for us to read. 

Variable: a variable is a container where you store something. You decide what that variable is called and what you put in it.

Constant: a bit of data that never changes throughout the code, unlike a variable.

Operations: an operation takes place between two things. These things could be variables, constants (or anything else in that language). 

Datatype: the type of data held by a variable. A floating point number (1.342), an integer (2), a string ("silly_string"), a character ("c"), 
or any other thing that can be defined. 

Outputs: what you code spits out. A line of text onto the screen, an image, a file, even a noise!

Inputs: what you code needs to run. This can be "hardcoded" or you can ask the user to supply it.


Loops: code often needs to do the same thing on a long list of data. We often use loops to do this. Loops can be nested (i.e. a loop within a loop)

Conditionals: you often run a bit of code if a certain condition is met, for example if the variable contains a number greater than 5, do this, otherwise do that.
This creates a logic flow to your code and allows decisions to be made.

Functions: if you find yourself doing the same few line sof code again, and again, we don't type them out repeatedly, we instead create a function which 
we can call every time we want to run those lines. Functions take input (called arguments) and return data back to the main program (where you can store it
in a variable, for example).


Defining a variable
--------------------

A variable is a container to store your data. Most variables in interpreted languages are defined when you use them first time. In compiled language you need to decide
up-front which variables you need. Variables can change what they store throughout the code.

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

What about changing what's in a variable? Just set it:

my_name = "Jon"
print(my_name)
my_name="Fred"
print(my_name)

What the above code will do is set the variable "my_name" to Jon, print it to screen, then set "my_name" to Fred and print that to screen. 
What the users sees is:

Jon
Fred

All the above examples require the variable to be known up front (hardcoded). What if we don't know?

filname = ask_user_for_file()

Assuming the function (see below) works, filename will contain whatever the user tells us. We can then do something like:

data = load_file(filename)

where filename was given by the user and we then load in that file. That way nothing is hardcoded. 

How do you decide a good variable name?
.......................................

A good variable name should make sense, make the code readable to a human and be clear. In the above
I've used _ to seperate words. This is good practice. You can also use CamelCase (i.e. a captial letter to 
seperate words). Whichever you do, be consistant!

Good variables:

users_name
temperature
input_filename
output_filename
chemical_data
topography_raster
rivers_shapefile
max_reef_growth_rate

Bad variables:

x
temp
fi
fo
chemdat
top
rs
mrgr

The first list is clear with little doubt what that variable contains. The second list is not that helpful. Is temp temporary or temperature? chemdat might be ok, but a bit hard 
to read. top is not helpful, topography or the top of something? x and rs could be anything! In 5 year's time you will not remember what mrgr is, but max_reef_growth_rate will
always make sense. Note I've not typed maximum_reef_growth_rate as I feel max is reasonable shorthand for maximum, but others would disagree with me on that!


Datatypes
---------



Operations
----------



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
