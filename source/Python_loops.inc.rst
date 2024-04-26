Python Loops
------------
.. index::
  single: Loops; Python

As we saw in the coding fundamentals, loops are a tool to iterate over
many "bits" of data, like rows or columns in a spreadsheet, a list of parameters,
or through time (as in the example above). They are therefore fundamental
to a lot of data analysis.

Suppose we want to make a table to convert Celsius to Fahrenheit:

.. code-block:: output

    -20  -4.0
    -15   5.0
    -10   14.0
     -5   23.0
      0   32.0
      5   41.0
     10   50.0
     15   59.0
     20   68.0
     25   77.0
     30   86.0
     35   95.0
     40   104.0

How do we write a program that prints out such a table? We know that 

.. math::
   
   F = \frac{9}{5}C + 32

and a single line in this table is:

.. code-block:: python
   :caption: |python|

    C = -20
    F = 9.0/5.0*C + 32

    print(C, F)

We could therefore write:

.. code-block:: python
   :caption: |python|

    C = -20; F = 9.0/5.0*C + 32; print(C, F)
    C = -15; F = 9.0/5.0*C + 32; print(C, F)
    C = -10; F = 9.0/5.0*C + 32; print(C, F)
    C = -5; F = 9.0/5.0*C + 32; print(C, F)
    C = 0; F = 9.0/5.0*C + 32; print(C, F)
    C = 5; F = 9.0/5.0*C + 32; print(C, F)
    C = 10; F = 9.0/5.0*C + 32; print(C, F)
    C = 15; F = 9.0/5.0*C + 32; print(C, F)
    C = 20; F = 9.0/5.0*C + 32; print(C, F)
    C = 25; F = 9.0/5.0*C + 32; print(C, F)
    C = 30; F = 9.0/5.0*C + 32; print(C, F)
    C = 35; F = 9.0/5.0*C + 32; print(C, F)
    C = 40; F = 9.0/5.0*C + 32; print(C, F)

This is error prone though. What if we make a typo (which is likely)? How would we know? 
Also this is very boring and repetitive. Note, I've used ``;`` to separate out
statements so they can go on a single line.

The entire idea of writing code it to remove the 
repetitive, boring stuff and let the computer do that work. This is where loops come in.

Python ``for`` Loops
~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: For loops; Python

``for`` loops work in Python using a control variable (the thing that increments each loop) and 
an iterator (the thing we're iterating over). This is a really powerful concept as 
we can iterate over a list or a counter with the same construct. This is all
a bit abstract, so let's do some examples.

.. code-block:: python
   :caption: |python|

   my_list = [1, 2, 3, 6, 7, 10]
   for item in my_list:
      print(item)

The above creates a list (of numbers) and then iterates over that list
with the control variable being the individual item in the list. You should
see the following:

.. code-block:: output
   :caption: |cli| |python|

    1
    2
    3
    6
    7
    10

Note the indentation? We covered that briefly in the last section. Unlike other languages
Python uses white space to denote which statements are included in the ``for`` loop. They must
be indented to the same level, but there are no rules for how much. Most programmers
use 4 spaces. Some use 8, some (rarely) use 3.

I would recommend sticking to 4 spaces. In a text editor it's worth setting your :kbd:`Tab`
to be four spaces, rather than the `tab` character.

Going back to loops...we can also iterate over the list using a counter.

.. code-block:: python
   :caption: |python|

   my_list = [1, 2, 3, 6, 7, 10]
   for i in range(0,len(my_list),1):
      print(my_list[i])

The output will be identical to the above, but we're accessing the list via the index 
(here, the variable ``i``). What does ``i`` do then? Let's edit the code and find out.

.. code-block:: python
   :caption: |python|

   my_list = [1, 2, 3, 6, 7, 10]
   for i in range(0,len(my_list),1):
      print(i)

.. code-block:: output
   :caption: |cli| |python|

    0
    1
    2
    3
    4
    5

``i`` goes from 0 (Python starts counting from 0. R starts from 1) to the length of the list - 1. The ``range`` function
creates a list containing those numbers. So although this loops looks different to the first one we created,
it's actually identical in terms of it's construction.

.. index::
   single: range(); Python

The ``range`` function is ``range(start, stop, increment)``
which generates a list of integers: ``start``, ``start+increment``, ``start+2*increment``, and so on up to, but not including, ``stop``. 
We can also write ``range(stop)`` as an abbreviation for ``range(0, stop, 1)``, or ``range(start,stop)`` to assume an increment
of 1.

For loops are a really useful way of doing the same thing to each item in a list. 

.. admonition:: Practical exercise

   **Writing our table for conversion using a** ``for`` **loop?**

    Write out the Fahrenheit to Celsius conversion table using a ``for`` loop.

.. admonition:: Solution
   :class: toggle

   .. code-block:: python
      :caption: |python|

      for C in range(-20,41,5):
          F = 9.0/5.0*C + 32
          print(C, F)
      
   This version uses the `range` function to go from -20 to 41 (note: not 40!) in steps of 5
   and calculates F, before printing C and F. You could do this in one line of code, which 
   we will come to later.

In a ``for`` loop we always know how many times we should iterate that loop. What if we don't know in advance?
Python also has a ``while`` loop which will keep going as long as some condition is true.


.. youtube:: KMlEYgG1lYg
    :align: center



Python ``while`` loop
~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: While loops; Python

A while-loop executes repeatedly a set of statements as long as a boolean condition is ``True``

.. code-block:: python
   :caption: |python|

    while condition:
        <statement 1>
        <statement 2>
        ...

    <first statement after the loop>

We can write code to do a simple counter:

.. code-block:: python
   :caption: |python|

    counter = 0
    while counter <= 10:
        counter = counter + 1
        print(counter)

This will loop until the counter is greater than 10. So we will see:

.. code-block:: output
   :caption: |cli| |python|

    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11

Note the counter started from 0 and the while loop kept going until it was `>10`. The condition
can be any conditional statement, including key presses (but that requires some knowledge we don't have yet).


.. admonition:: Practical exercise

   **Writing our table for conversion using a** ``while`` **loop?**

    Write out the Fahrenheit to Celsius conversion table using a ``while`` loop.

.. admonition:: Solution
   :class: toggle

   .. code-block:: python
      :caption: |python|

      C = -20
      while C <= 40:
          F = 9.0/5.0*C + 32
          print(C, F)
          C = C + 5
      
   This is very easy to read and understand; especially the ending condition (unlike
   the the loop above where we had to use 41...).

.. youtube:: Ui28nauWJ9Y
    :align: center

