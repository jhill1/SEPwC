Python: lists and tuples
-------------------------------

We have used Python lists in other lessons, but here we'll go into more detail. The idea of a list
is fairly simple; a set of containers that contain data in an ordered way. 

A list is set up with something like:

.. code-block:: Python

   a_list = [1, 2, "hello", 3.464356]

The list does not have to contain the same kind of data in each container (here we have 2 integers, a string and a float). 

How do we access the items of the list later? We use the index. 

.. code-block:: Python

   print(a_list[0])
   print(a_list[1])
   print(a_list[2])
   print(a_list[3])

will print:

.. code-block:: bash

    1
    2
    hello
    3.464356

Note that Python starts counting from 0, not 1. Also note how we access each container in the list - via the ``[ ]`` brackets. Python will tell us if we overstep the length of a list:

.. code-block:: Python

   print(a_list[5])

    IndexError Traceback (most recent call last)
    Cell In [12], line 1
    ----> 1 print(a_list[5])

    IndexError: list index out of range


Python has some tricks up its sleeve though. What if we want the last item of the list, but we don't know how long it is?

.. code-block:: Python

   print(a_list[-1])

Will return ``3.464356``.

Exercise: what does -2 and -3 give you? -5?

What is a tuple then?
~~~~~~~~~~~~~~~~~~~~~~

There is a single difference between a list and tuple. A list can be modified; you can append items to it, remove items and generally do what you want with it. A tuple on the other hand is *immutable*. You cannot chnage it at all. Once it's made it is made. 

.. code-block:: Python

   a_tuple = (1,2,3,4,5)

   print(a_tuple[0])
   print(a_tuple[1])
   print(a_tuple[2])
   print(a_tuple[3])

   a_tuple[0] = 6

Note we create a tuple using ``( )`` brackets, not ``[ ]`` brackets. We access the data just like a list though.


Common functions with lists
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Lists come with a number of functions attached to them and used often with them. The obvious one is ``len()`` which tells us the numebr of 
items/containers in that list:


.. code-block:: Python

   print(len(a_list))

will return 4. ``len()`` is actually a generic function that works on other datatypes too, but is used a lot with lists:

.. code-block:: Python

   print(len("Hello"))




append()	Adds an element at the end of the list
clear()	Removes all the elements from the list
copy()	Returns a copy of the list
count()	Returns the number of elements with the specified value
extend()	Add the elements of a list (or any iterable), to the end of the current list
index()	Returns the index of the first element with the specified value
insert()	Adds an element at the specified position
pop()	Removes the element at the specified position
remove()	Removes the first item with the specified value
reverse()	Reverses the order of the list
sort()	Sorts the list


