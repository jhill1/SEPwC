R Loops
-------

As we saw in the coding fundementals, loops are a tool to iterate over
many "bits" of data, like rows or columns in a spreadsheet, a list of parameters,
or through time (as in the example above). They are therefore fundemental
to a lot of data analysis.

Suppose we want to make a table to convert Celsius to Farenheit:

.. code-block:: output

    -20  -4.0
    -15   5.0
    -10  14.0
    -5  23.0
    0  32.0
    5  41.0
    10  50.0
    15  59.0
    20  68.0
    25  77.0
    30  86.0
    35  95.0
    40 104.0

How do we write a program that prints out such a table? We know that 

.. math::
   
   F = \frac{9}{5}C + 32

and a single line in this table is:

.. code-block:: R

    C = -20
    F = 9/5*C + 32

    print(C, F)

We could therefore write:

.. code-block:: R

    C = -20; F = 9/5*C + 32; print(C, F)
    C = -15; F = 9/5*C + 32; print(C, F)
    C = -10; F = 9/5*C + 32; print(C, F)
    C = -5; F = 9/5*C + 32; print(C, F)
    C = 0; F = 9/5*C + 32; print(C, F)
    C = 5; F = 9/5*C + 32; print(C, F)
    C = 10; F = 9/5*C + 32; print(C, F)
    C = 15; F = 9/5*C + 32; print(C, F)
    C = 20; F = 9/5*C + 32; print(C, F)
    C = 25; F = 9/5*C + 32; print(C, F)
    C = 30; F = 9/5*C + 32; print(C, F)
    C = 35; F = 9/5*C + 32; print(C, F)
    C = 40; F = 9/5*C + 32; print(C, F)

This is error prone though. What if we make a typo (likely)? How would we know? Also this
is very boring and repetative. The entire idea of writing code it to remove the 
repetative, boring stuff and let the computer do that work. This is where loops come in.

`for` Loops
~~~~~~~~~~~

'for' loops work in Python using a control variable (the thing that increments each loop) and 
an iterator (the thing we're iterating over). This is a really powerful concept as 
we can iterate over a list or a counter with the same construct. This is all
a bit abstract, so let's do some examples.

.. code-block:: R

   my_list = c(1, 2, 3, 6, 7, 10)
   for (item in my_list) {
      print(item)
   }

The above creates a vector (of numbers) and then iterates over that list
with the control variable being the individual item in the list. You should
see the following:

.. code-block:: output

   [1] 1
   [1] 2
   [1] 3
   [1] 6
   [1] 7
   [1] 10

The loop is made using the `for` command, which is then followed by the loop conditions
in parenthesis `(  )`. The loop itself is delimited using curly braces `{  }`. R doesn't care
about indentation as long as the `{ }` contains the statements within the loop. So this code
works just as well:

.. code-block:: R

   my_list = c(1, 2, 3, 6, 7, 10)
    for (item in my_list) {
   print(item)}

But it not as readable! Remmeber, when writing code we are writing code for humans
to read it, rather than computer to execute it.

Going back to loops...we can also iterate over the list using a counter.

.. code-block:: R

   my_list = c(1, 2, 3, 6, 7, 10)
   for (i in seq(1,length(my_list),1)) {
      print(my_list[i])
   }

The output will be identical to the above, but we're accessing the list via the index 
(here, the variable `i`). What does `i` do then? Let's edit the code and find out.

.. code-block:: R

   my_list = c(1, 2, 3, 6, 7, 10)
   for (i in seq(1,length(my_list),1)) {
      print(i)
    }

.. code-block:: output

    1
    2
    3
    4
    5
    6

`i` goes from 1 (R starts counting from 1, Python from 0) to the length of the list. The `seq` function
creates a list contining those numbers. So although this loops looks different to the first one we created,
it's actually identical in terms of it's construction.

The `seq` function is `seq(start, stop, increment)`
which generates a list of integers: `start`, `start+increment`, `start+2*increment`, and so on up to, and including, `stop`. 
We can also write `seq(stop)` as an abbreviation for `seq(1, stop, 1)`, or `seq(start,stop)` to assume an increment
of 1.

For loops are a really useful way of doing the same thing to each item in a list. 

.. admonition:: Practical exercise

   **Writing our table for conversion using a `for` loop?**

    Write out the Farenheit to Celsius conversion table using a `for` loop.

.. admonition:: Solution
   :class: toggle

   .. code-block:: R

      for (C in seq(-20,40,5)) {
          F = 9/5*C + 32
          print(paste(C,F))
      }
      
   This version uses the `seq` function to go from -20 to 40 in steps of 5
   and calculates F, before printing C and F. Note the use of `paste` to join the
   two number together on one line.

In a `for` loop we always know how many times we should iterate that loop. What if we don't know in advance?
R also has a `while` loop which will keep going as long as some condition is true.

`while` loop
~~~~~~~~~~~~

A while-loop executes repeatedly a set of statements as long as a boolean condition is `True`

.. code-block:: R

    while (condition) {
        <statement 1>
        <statement 2>
        ...
    }

    <first statement after the loop>

We can write code to do a simple counter:

.. code-block:: R

    counter = 0
    while (counter <= 10) {
        counter = counter + 1
        print(counter)
    }

This will loop until the counter is greater than 10. So we will see:

.. code-block:: output

    [1] 1
    [1] 2
    [1] 3
    [1] 4
    [1] 5
    [1] 6
    [1] 7
    [1] 8
    [1] 9
    [1] 10
    [1] 11

Note the counter started from 0 and the while loop kept going until it was `>10`. The condition
can be any conditional statement, including key presses (but that requires some knowledge we don't have yet).


.. admonition:: Practical exercise

   **Writing our table for conversion using a `while` loop?**

    Write out the Farenheit to Celsius conversion table using a `while` loop.

.. admonition:: Solution
   :class: toggle

   .. code-block:: R

      C = -20
      while (C <= 40) {
          F = 9/5*C + 32
          print(paste(C, F))
          C = C + 5
      }
      
   This is very easy to read an understand; especially the ending condition.

