The fundamentals of code
=========================

Some terminology
----------------
.. index:: 
   single: constant
   single: operation
   single: function


Computer programming is full of jargon. Fortunately, most of the jargon is common across all
languages. The idea of this chapter is to cover those basics so that when we get to a language
we can focus on the language, rather than also learning the jargon!  In this chapter we're going to use pseudo-code. 
This is code-like text that is easier to read. 
There is no fixed syntax (you can make up your own!) and it's designed for us to read. 

This is a list of terms we will use throughout:

**Variable**: a variable is a container where you store something. You decide what that variable is called and what you put in it.

**Constant**: a bit of data that never changes throughout the code, unlike a variable.

**Operations**: an operation takes place between two things. These things could be variables, constants (or anything else in that language). 

**Datatype**: the type of data held by a variable. A floating point number (1.342), an integer (2), a string ("silly_string"), a character ("c"), 
or any other thing that can be defined. 

**Outputs**: what you code spits out. A line of text onto the screen, an image, a file, even a noise!

**Inputs**: what you code needs to run. This can be "hard-coded" or you can ask the user to supply it.

**Loops**: code often needs to do the same thing on a long list of data. We often use loops to do this. Loops can be nested (i.e. a loop within a loop)

**Conditionals**: you often run a bit of code if a certain condition is met, for example if the variable contains a number greater than 5, do this, otherwise do that.
This creates a logic flow to your code and allows decisions to be made.

**Functions**: if you find yourself doing the same few line of code again, and again, we don't type them out repeatedly, we instead 
create a function which we can call every time we want to run those lines. Functions take input (called arguments) and 
return data back to the main program (where you can store it in a variable, for example).


Defining a variable
--------------------
.. index:: 
   single: variable

A variable is a container to store your data. Most variables in interpreted languages are defined when you use them first time.
In compiled language you need to decide up-front which variables you need. Variables can change what they store throughout the code, 
including the type of data they store in most interpreted languages.

Some examples:

.. code-block::
   :caption: |pc|

   my_data = [1, 2, 3, 5, 19, 18]
   
I've create a variable called ``my_data`` which contains a list of integers.

.. code-block::
   :caption: |pc|

   my_favourite_number = 7

This variable contains a single integer, 7.

.. code-block::
   :caption: |pc|

   pi = 3.14159

This variable contains the real (or floating point) number for \pi to five decimal places.

.. code-block::
   :caption: |pc|

   name = "Jon"

This variable contains text or a string.

.. code-block::
   :caption: |pc|

   loaded_data = load_csv_file("mega_data_set.csv")

This variable contains whatever the "mega_data_set.csv" file contains, which was loaded via the ``load_csv_file`` function.

What about changing what's in a variable? Just set it:

.. code-block::
   :caption: |pc|

   my_name = "Jon"
   print(my_name)
   my_name="Fred"
   print(my_name)

What the above code will do is set the variable ``my_name`` to Jon, print it to screen, then set ``my_name`` to Fred and print that to screen. 
What the users sees is:

.. code-block:: output
   :caption: |pc|

    Jon
    Fred

All the above examples require the variable to be known up front (hard-coded). What if we don't know?

.. code-block::
   :caption: |pc|

   filename = ask_user_for_file()

Assuming the function (see below) works, filename will contain whatever the user tells us. We can then do something like:

.. code-block::
   :caption: |pc|

   data = load_file(filename)

where filename was given by the user and we then load in that file. That way nothing is hard-coded. 

How do you decide a good variable name?
.......................................

A good variable name should make sense, make the code readable to a human and be clear. In the above
I've used _ to separate words. This is good practice. You can also use CamelCase (i.e. a capital letter to 
separate words). Whichever way you choose, be consistent!

Good variables:

.. code-block::
   :caption: |pc|

   users_name
   temperature
   input_filename
   output_filename
   chemical_data
   topography_raster
   rivers_shapefile
   max_reef_growth_rate

Bad variables:

.. code-block::
   :caption: |pc|

   x
   temp
   fi
   fo
   chemdat
   top
   rs
   mrgr

The first list is clear with little doubt what that variable contains. The second list is not that helpful.
Is ``temp`` "temporary" or "temperature"? ``chemdat`` might be OK, but a bit hard 
to read. ``top`` is not helpful, topography or the top of something? ``x`` and ``rs`` could be anything! In 
5 year's time you will not remember what ``mrgr`` is, but ``max_reef_growth_rate`` will
always make sense. Note I've not typed ``maximum_reef_growth_rate`` as I feel max is reasonable shorthand 
for maximum, but others would disagree with me on that!

.. admonition:: Thought exercise

    **Variables**
    
    What would make a good variable name for the following?

    * A list of student names
    * A single student name
    * grain size data for a single location
    * A list of the above grain size data
    * sea surface temperature
    * the point-by-point trajectory of an object
    * an input filename supplied by the user

..  admonition:: Solution
    :class: toggle

    These are suggestions!

    * ``student_names``
    * ``name`` (or ``student_name``)
    * ``grain_size``
    * ``grain_sizes``
    * ``sea_surface_temperature`` (or possibly ``sst`` as that is a standard acronym)
    * ``trajectory``
    * ``input_filename``


Datatypes
---------
.. index:: 
   single: datatype

The variables we create can store any kind of data. In interpreted languages that can even change throughout the 
code. In compiled language you often have 
to fix the kind of data up front. The kind of data is the datatype.

Common datatypes are float (for a floating point number, 1.23412), integer (1, for example), 
a string ("like this one") a boolean (true or false). We can also make up 
our own datatypes! We can take the basic kinds and join them together, so for example, we can have a "list" datatype, which can contain
a fixed number of floats, e.g. ``[1.1, 23.5, 12321.2343242, 582.11]``. We could then make lists of lists, which we can think of as a table:

| 1   2   3   4   5
| 5   4   3   2   1
| 2   4   5   6   7 

We can even make datatypes that mix all of these together (along with some functions to operate on them) to create
objects (we'll come to those later). 

.. admonition:: Thought exercise

    **Datatypes**
    
    What kind of data are the following? (They will be one of interger, float, string, character or list)

    * 1.0
    * 1
    * 1 divded by 2
    * Hello
    * 42e-45
    * @
    * 4, 56, 2345.23423, 324, 45.34

..  admonition:: Solution
    :class: toggle

    * 1.0: float
    * 1: integer
    * 1 divided by 2: float (0.5)
    * Hello: string
    * 42e-45: float, 0.00000...42 
    * @: character
    * 4, 56, 2345.23423, 324, 45.34: list (of floats and integers)


Operations
----------
.. index:: 
   single: operation

Operations are how to start to manipulate data. For example:

.. code-block::
   :caption: |pc|

   user_input = get_user_number()
   print("You gave me" user_input)
   new_value = user_input + 5
   print("You now have " new_value)

So the above, if the user put in 2, the user would see

  You gave me 2
  You now have 7

Operations cover any mathematical operation (multiply, divide, subtract), but also some more
specialist ones like "modulus" which gives you the reminder of a division. We can also *overload*
operations so "add" works on multiple data types, for example:

.. code-block::
   :caption: |pc|

   my_string = "hello"
   ending = " world"

   complete_string = my_string + ending

Which will do what you think it does and put "hello world" into complete_string. Which 
symbol is used depends on the language and not all languages can do this.

.. admonition:: Thought exercise

    **Operations**
    
    What is the answer to the following operations?

    .. code-block:: 
       :caption: |pc|

        var_1 = 5
        var_2 = 10
        var_3 = 20

        ? = var_1 + var_2
        ? = var_1 * var_1
        ? = var_3 / var_2
        ? = ((var_3 / var_2) * var_1) + var_2


..  admonition:: Solution
    :class: toggle

    * 15
    * 25
    * 2
    * 20


Booleans and Logic
------------------
.. index:: 
   single: boolean
   single: logic

A boolean is either ``true`` or ``false``. In code this is very important as it allows our code
to make decisions based on the value of variables.

.. code-block::
   :caption: |pc|

   3 < 5
   15 == 15
   5 >= 1
   4 < 5 && 5 < 6
   4 < 5 || 6 < 3

All the above will return ``true``. 3 is less than 5, etc. The ``&&`` means *and*, so *both* booleans must
be true for that statement to also be true; so 4 must be less than 5 *and* 5 must be less than 6. The 
``||`` means *or*. In this case only 1 of the boolean must be true for the statement to also return ``true``.
So either 4 must be less than 5 (``true``) *or* 6 must be less than 3 (``false``). 

If we then add some variables into the mix.

.. code-block:: 
   :caption: |pc|

   i = 5
   print(i<10)
   print(i>10)

Will print:

.. code-block:: output
   :caption: |pc|

   True
   False


.. admonition:: Thought exercise

    **Booleans**
    
    What is the answer to the following boolean operations?

    .. code-block:: 
       :caption: |pc|

        var_1 = 5
        var_2 = 10
        var_3 = 20

        ? = var_1 < var_2
        ? = var_3 < var_2 / var_1
        ? = var_3 == var_1
        ? = var_3 < var_2 && var_2 > var_1
        ? = var_3 > var_2 || var_2 < var_1
        ? = var_1 >= 5
        ? = var_3 > var_2 && var_1 < var_2


..  admonition:: Solution
    :class: toggle

    * True
    * False
    * False
    * False
    * True
    * True
    * True


Outputs
-------
.. index:: 
   single: output

The output is something you, the programmer decides. It might be a text file, a CSV file, a graphic, etc., etc., it
may just be the result printed to screen.

.. code-block::
   :caption: |pc|
   
   my_secret = "I'm Batman..."
   print(my_secret)
   write.file("My_Secret.txt", my_secret)
   speak(my_secret)

Will output the contents of ``my_secret`` to the screen, to a file and say it. Not much of a secret now...


Inputs
------
.. index:: 
   single: input

Input are, unsurprisingly, the opposite of outputs. Like the outputs of a program they come in many forms.
The simplest are the *hard-coded* inputs.

.. code-block::
   :caption: |pc|

   my_file = "top_secret_data.csv"
   secret_data = load.csv(my_file)

Here the input is the file "top_secret_data.csv", which is hard-coded into the program. The program will
read whatever is in that file so to read in different data you could a) swap the filename to something else
or b) replace the contents of the file with your new data. 

Neither is particularly convenient to a user and would need explaining. A better solution is to ask the user
which file to use. So how can we do this? We can use the command-line argument idea we learnt last week:

.. code-block::
   :caption: |pc|

   command_line_arguments = get_command_line_args("--input_file", "--output_file")
   input_file = command_line_argument[input_file]
   data = load.csv(input_file)

Or we could pop-up a little box, which you'll be familiar to you:

.. code-block::
   :caption: |pc|

   input_file = ask_file_pop_up()
   data = load.csv(input_file)


Loops
-----
.. index:: 
   single: loop

A lot of time we need to repeat the same thing on bits of data. Imagine a scenario where we have a
huge list of files we need to extract a single bit of data from each of these. We need to do the thing
(parse and extract the files) a lot of times. To do this we can loop over the files:

.. code-block::
   :caption: |pc|

   storage = StorageContainer
   list_of_files = ["file1.csv", "file2.csv", ..... "file3.csv"]

   for each file in list_of_files
      file_contents = load.csv(file)
      data_I_need = grab_data(file_contents)
      put(data_I_need into storage)

This is a really powerful concept and one of the main things we do when process data using code. Here's
another example looping over cells in a raster (DEM or topography) file

.. code-block::
   :caption: |pc|

   raster = load.raster("my_raster_file.tif")
   for each x in raster.x_direction
      for each y in raster in raster.y_direction
         raster[x,y] = x*y

This code sets each cell in the raster to x*y where x is the number of cells in the east-west direction
and y is the number of cells in the north-south direction. This is a bit abstract, so let's go through this
is step-by-step.

Here's our raster which contains 5 cells in the x-direction and 4 in the y-direction and contains the following
(random) numbers:

| 1 2 3 4
| 2 2 3 4
| 3 2 3 4
| 4 2 3 4
| 5 2 3 4

The first loop therefore goes from 1 to 5, the second loop goes from 1 to 4. We can then write down what
x and y will do for each loop:

| x = 1, y = 1
| x = 1, y = 2
| x = 1, y = 3
| x = 1, y = 4
| x = 2, y = 1
| x = 2, y = 2
| x = 2, y = 3
| x = 2, y = 4
| x = 3, y = 1
| x = 3, y = 2
| x = 3, y = 3
| x = 3, y = 4
| x = 4, y = 1
| x = 4, y = 2
| x = 4, y = 3
| x = 4, y = 4
| x = 5, y = 1
| x = 5, y = 2
| x = 5, y = 3
| x = 5, y = 4

So what does the raster then contain after this loop?, we can also work that out:

| x = 1, y = 1, x*y = 1
| x = 1, y = 2, x*y = 2
| x = 1, y = 3, x*y = 3
| x = 1, y = 4, x*y = 4
| x = 2, y = 1, x*y = 2
| x = 2, y = 2, x*y = 4
| x = 2, y = 3, x*y = 6
| x = 2, y = 4, x*y = 8
| x = 3, y = 1, x*y = 3
| x = 3, y = 2, x*y = 6
| x = 3, y = 3, x*y = 9
| x = 3, y = 4, x*y = 12
| x = 4, y = 1, x*y = 4
| x = 4, y = 2, x*y = 8
| x = 4, y = 3, x*y = 12
| x = 4, y = 4, x*y = 16
| x = 5, y = 1, x*y = 5
| x = 5, y = 2, x*y = 10
| x = 5, y = 3, x*y = 15
| x = 5, y = 4, x*y = 20

So our raster grid now contains.

| 1 2 3 4
| 2 4 6 8
| 3 6 9 12
| 4 8 12 16
| 5 10 15 20


.. admonition:: Thought exercise

    **Loops**
    
    What's the largest number printed out in this code?

    .. code-block:: 
       :caption: |pc|

        max_x = 3
        max_y = 4
        for i < max_x
            for j < max_y
                print(i*j)


..  admonition:: Solution
    :class: toggle

    6. The loop will go:
    .. line-block::
    
        i = 1, j = 1
        i = 1, j = 2
        i = 1, j = 3
        i = 2, j = 1
        i = 2, j = 2
        i = 2, j = 3

        so the largest number is 6.


.. admonition:: Thought exercise

    **Loops**
    
    How many nested loops do you need to traverse all values in a three-dimensional array?


..  admonition:: Solution
    :class: toggle

    Three. One per dimension. 


Conditionals
------------
.. index:: 
   single: conditional

Conditional statements run code based on a variable meeting some condition. They allow code to *branch* and
perform actions based on some criteria.

For example, only take a square root if the number if > than 0

.. code-block::
   :caption: |pc|

   if number > 0
     square_root = square_root(number)

This means the square root will only be calculated if our number is greater than zero. But what if it's equal to or 
less than zero? We may need to add another condition or catch all the other possibilities, so:

.. code-block::
   :caption: |pc|

   if number > 0
      square_root = square_root(number)
   else
      print("Can't take the square root of " number ". Exiting")
      exit()

Here, if the condition is not met, the program prints an error message and exits

We can nest conditions too, like we did with the loops.

.. code-block::
   :caption: |pc|

   if number > 0
      if number < 100
         print("Your number is > 0 and < 100)

The above can also be written using logic:

.. code-block::
   :caption: |pc|

   if number > 0 and number < 100
      print("Your number is > 0 and < 100)

You can negate conditionals too:

.. code-block::
   :caption: |pc|

   if not number <= 0
      square_root = square_root(number)

This is *exactly* equivalent to our first example above (note the *not* and the <= which is opposite to >)

In all languages you will find things like is equal to (for example ==), is less than, greater than, less than or equal to, etc..
Most languages have some form of "or" and "and" operations. 


.. admonition:: Thought exercise

    **Conditionals**
    
    Which statement will be printed out?

    .. code-block:: 
       :caption: |pc|

        max_x = 3
        max_y = 4
        if max_x > 3
            print("Hi!")
        else if max_x < 4 && max_y <4
            print("Hello!")
        else if max_x == 3
            print("Hola!")
        else if max_y == 4
            print("Hej!")
        else
            print("Bonjour!")

..  admonition:: Solution
    :class: toggle

    Hola! will be printed. The first if is not true, so we move to the next, which is also not true.
    The third is true, so we go inside that conditional and hence print("Hola!") is executed. The forth 
    statement is also true, but the code will not enter that block as it is part of the same ``if..else`` block.
    The ``else`` would be executed if none of the satements were true.


Functions
---------
.. index:: 
   single: function

Function are for bits of code you run lots or complex code that can be wrapped up so the main code is easier to read. 
Rather than have a sorting algorithm in your code, you wrap that code into a function and then your code is easier to read.
Functions also make a code much easier to test.

.. code-block::
   :caption: |pc|
   
   a_list_of_numbers = [1,4,2,3,6,4]
   sorted_list = sort(a_list_of_numbers)
   print(sorted_list)

Is much easier to read than:

.. code-block::
   :caption: |pc|
   
   a_list_of_numbers = [1,4,2,3,6,4]
   n = length(a_list_of_numbers) 
   for i in range(n):
     for j in range(0, n-i-1):
       if a_list_of_numbers[j] > a_list_of_numbers[j+1] : 
         # swap the numbers around
         number1 = a_list_of_numbers[j]
         number2 = a_list_of_numbers[j+1]
         a_list_of_numbers[j+1] = number1
         a_list_of_numbers[j] = number2
   
   print(a_list_of_numbers)

The algorithm above is a bubble sort.

..  admonition:: Learn more
    :class: toggle

    **Bubble Sort**
    
    Just like the way bubbles rise from the bottom of a glass, bubble sort is a simple algorithm that sorts a list, allowing either lower or 
    higher values to bubble up to the top. The algorithm traverses a list and compares adjacent values, swapping them if they are not in the correct order.

    With a worst-case complexity of O(n^2) (this means the time it takes to complete increases with the square of the length of the list), 
    bubble sort is very slow compared to other sorting algorithms like quicksort. The upside is that it is one of the easiest sorting algorithms 
    to understand and code from scratch.

    From technical perspective, bubble sort is reasonable for sorting small-sized arrays or specially when executing sort algorithms on 
    computers with remarkably limited memory resources.

    **Example:**
    
    First pass through the list:
    
    Starting with ``[4, 2, 6, 3, 9]``, the algorithm compares the first two elements in the array, 4 and 2. It swaps them because 2 < 4: ``[2, 4, 6, 3, 9]``
    
    It compares the next two values, 4 and 6. As 4 < 6, these are already in order so nothing is swapped.
    
    The next two values are swapped because 3 < 6: ``[2, 4, 3, 6, 9]``
    
    The last two values, 6 and 9, are already in order, so the algorithm does not swap them.
    
    Second pass through the list:
    
    2 < 4, so there is no need to swap positions so we stay with: ``[2, 4, 3, 6, 9]``
    
    The algorithm swaps the next two values because 3 < 4: ``[2, 3, 4, 6, 9]``
    
    No swap as 4 < 6: ``[2, 3, 4, 6, 9]``
    
    Again, 6 < 9, so no swap occurs: ``[2, 3, 4, 6, 9]``
    
    The list is already sorted, but the bubble sort algorithm doesn't realize this. Rather, it needs to complete an entire pass through the list without swapping any 
    values to know the list is sorted.

    Third pass through the list:
    
    ``[2, 4, 3, 6, 9]`` => ``[2, 4, 3, 6, 9]``
    
    ``[2, 4, 3, 6, 9]`` => ``[2, 4, 3, 6, 9]``
    
    ``[2, 4, 3, 6, 9]`` => ``[2, 4, 3, 6, 9]``
    
    ``[2, 4, 3, 6, 9]`` => ``[2, 4, 3, 6, 9]``
    
    Clearly bubble sort is far from the most efficient sorting algorithm. Still, it's simple to implement yourself.


So we would then create the sort algorithm into a function

.. code-block::
   :caption: |pc|

   function sort(numbers)
      
      n = length(numbers)
      for i in range(n):
        for j in range(0, n-i-1):
          if numbers[j] > numbers[j+1] : 
            # swap the numbers around
            number1 = a_list_of_numbers[j]
            number2 = a_list_of_numbers[j+1]
            a_list_of_numbers[j+1] = number1
            a_list_of_numbers[j] = number2
      return numbers

   a_list_of_numbers = [1,4,2,3,6,4]
   sorted_list = sort(a_list_of_numbers)
   print(sorted_list)

We now have a function that sorts number in our code. The main code is easier to read and we can sort any lists of numbers
as many times as we wish, without writing the same code over and over. This really comes in handy (as we shall see when test code).

As you break your code down into smaller chunks, you can test each chunk to make sure
sure it works as you expected (including when you give it "incorrect" data). If all the functions in your code work in the tests
then you can be more confident your whole code works.

Objects and classes
-------------------
.. index:: 
   single: class
   single: object

Modern programming uses objects to pass data around. This style of programming is called
object-oriented programming. An object is a collection of data *and* functions that go together.
Objects are widely used in both Python and R modules/libraries, so it's worth getting our head
around them now.

An object is a single instance of a class. Think of the ``Class`` as the template. You can 
make multiple instances of that ``Class`` and each one is an ``Object``.

Let's make a ``Dog`` class. Each ``Dog`` has a set of attributes and some actions. Those will depend
on what we need this class to do, but as this is a thought exercise for now, let's 
keep it simple.

Each ``Dog`` should have

  * a name
  * age
  * a colour

Each ``Dog`` should then be able to:

  * bark
  * go for walkies
  * be cleaned

We would create a class something like:

.. code-block::
   :caption: |pc|

    Class Dog
        self.name = ""
        self.age = 0
        self.colour = ""
        self.state = "clean"

        function init(name, age, colour)
            self.name = name
            self.age = age
            self.colour = colour

        function bark()
            print("Woof!")

        function walkies()
            self.state = "muddy"

        function beCleaned()
            if (self.state == "clean")
                print(name + " is already clean")
            else if (self.state == "muddy")
                print(name + " is now clean")
                self.state = "clean"

So what does this class do? It contains four variables: ``name``, ``age``, ``colour`` and ``state``. This are initialised when 
an object is created and that expects the name, age and colour to be set. The ``Dog`` class then had three methods: 
``bark()``, ``walkies()`` and ``beCleaned()``. When you call bark on your ``Dog`` object, "Woof!" is printed to screen.
When you call ``walkies()`` the ``state`` is set to "muddy" (even if the state is already "muddy"). If you call ``beCleaned()``
then the ``state`` is checked and the altered accordingly, with a message. 

You could then have a pack of dogs by creating multiple objects and they behave as separate ``Dogs``:

.. code-block::
   :caption: |pc|

    Dog1 = new Dog("Bob", 2, "white")
    Dog2 = new Dog("Fluffy", "5", "black")
    Dog1.bark()
    Dog2.walkies()


.. admonition:: Thought exercise

    **Objects**
    
    Create a class for a car. Think about what variables need to be stored
    and what functions are needed. The use case for this car class is to 
    create a traffic model (i.e. you'll have multiple cars travelling around some
    imaginary roads).

    There are no answers to this, but we can discuss in class.
