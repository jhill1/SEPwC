Python: lists and tuples
-------------------------------
.. index::
  single: Lists; Python

We have used Python lists in other lessons, but here we'll go into more detail. The idea of a list
is fairly simple; a set of containers that contain data in an ordered way. 

A list is set up with something like:

.. code-block:: Python
   :caption: |python|

   a_list = [1, 2, "hello", 3.464356]

The list does not have to contain the same kind of data in each container (here we have 2 integers, a string and a float). 

How do we access the items of the list later? We use the index. 

.. code-block:: Python
   :caption: |python|

   print(a_list[0])
   print(a_list[1])
   print(a_list[2])
   print(a_list[3])

will print:

.. code-block:: bash
   :caption: |cli| |python|

    1
    2
    hello
    3.464356

Note that Python starts counting from 0, not 1. Also note how we access each container in the list - via the ``[ ]`` brackets. Python will tell us if we overstep the length of a list:

.. code-block:: Python
   :caption: |python|

   print(a_list[5])

    IndexError Traceback (most recent call last)
    Cell In [12], line 1
    ----> 1 print(a_list[5])

    IndexError: list index out of range


Python has some tricks up its sleeve though. What if we want the last item of the list, but we don't know how long it is?

.. code-block:: Python
   :caption: |python|

   print(a_list[-1])

Will return ``3.464356``.

Exercise: what does -2 and -3 give you? -5?

What is a tuple then?
~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Tuples; Python

There is a single difference between a list and tuple. A list can be modified; you can append items to it, remove items and generally do what you want with it. A tuple on the other hand is *immutable*. You cannot chnage it at all. Once it's made it is made. 

.. code-block:: Python
   :caption: |python|

   a_tuple = (1,2,3,4,5)

   print(a_tuple[0])
   print(a_tuple[1])
   print(a_tuple[2])
   print(a_tuple[3])

   a_tuple[0] = 6

Note we create a tuple using ``( )`` brackets, not ``[ ]`` brackets. We access the data just like a list though.


Common functions with lists
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Functions with lists; Python

Lists come with a number of functions attached to them and used often with them. The obvious one is ``len()`` which tells us the numebr of 
items/containers in that list:


.. code-block:: Python
   :caption: |python|

   print(len(a_list))

will return 4. ``len()`` is actually a generic function that works on other datatypes too, but is used a lot with lists:

.. code-block:: Python
   :caption: |python|

   print(len("Hello"))

Python then has a number of functions associated with only lists:

 * append() - Adds an element at the end of the list
 * clear() - Removes all the elements from the list
 * copy() - Returns a copy of the list
 * count() - Returns the number of elements with the specified value
 * extend() - Add the elements of a list (or any iterable), to the end of the current list
 * index() - Returns the index of the first element with the specified value
 * insert() - Adds an element at the specified position
 * pop() - Removes the element at the specified position
 * remove() - Removes the first item with the specified value
 * reverse() - Reverses the order of the list
 * sort() - Sorts the list

You use them like this:

.. code-block:: Python
   :caption: |python|

   a_list = [1, 2, "hello", 3.464356]
   print(a_list)
   a_list.pop()
   print(a_list)

Exercises...

Iterating over lists
~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Iterating over Lists; Python

As we saw above and in the introductory chapters, lists can be accessed via their indecies ``a_list[0]`` etc. To loop over a list you can therefore loop over a range of numbers from 0 to the length of the list-1 (the -1 is because we start counting from zero). It's common the use the ``range()`` function to create that list of indecies:

.. code-block:: Python
   :caption: |python|

   a_list = [1,2,3,4,5,6,7,8,9]

   for i in range(0,len(a_list)):
       print(i, a_list[i])

The code above creates a temporary list of numbers that go from 0 to 8. That temporary list is looped over and each loop the value is stored in the variable ``i``. We then use ``i`` as the index to access the list we want.

Exercise: read docs for the range function to understand why it doesn't go from 0 to 9.

This is a common design template in Python code as it can give some good flexibility, including starting from a non-zero index, ending the iteration before the end of the list, looping over several lists of the same length or indexing in steps other than 1. However, it is somewhat cumbersome with nested parentheses due to nested functions. 

An alternative way is to use the fact that a list is an ``Iterable`` object. Here, we specify the list after the ``in`` keyword in the loop. 

.. code-block:: Python
   :caption: |python|

   a_list = [1,2,3,4,5,6,7,8,9]

   for item in a_list:
       print(item)

Now ``item`` is a variable (so you can name it how you see fit), not an index, containing each list item, in order. This is much cleaner and more readable code. You have direct access to each item in the list without having to index the list (compare ``a_list[i]`` above to simply using ``item``).

If you have multiple lists of the same length you can integrate them over them simultaneously using the ``zip()`` functions:

.. code-block:: Python
   :caption: |python|

   a_list = [1,2,3,4,5,6,7,8,9]
   second_list = [11,12,13,14,15,16,17,18,19]

   for i1, i2 in zip(a_list,second_list):
       print(i1, i2)

Python is such a flexible language there are other ways to iterate over lists, but the two ways above are the most common. 


