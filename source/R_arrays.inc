R vectors, lists, arrays 
----------------------------


We have used R vectors in other lessons, but here we'll go into more detail. The idea of a vector
is fairly simple; a set of containers that contain data in an ordered way. 

A vector is set up with something like:

.. code-block:: R

   a_vector <- c(1, 2, "hello", 4.43535, 5, 6)

The ``c()`` sets up the vector and then items are seperated by ``,``. Note the vector does not need to be of the same type.
You can also create a vector using the ``:`` operator:

.. code-block:: R

   x <- 1:7
   y <- 2:-2

This create a sequence from the first to the next in steps of 1. Similarly, the ``seq()`` function can create a sequence of numbers:

.. code-block:: R

   x <- seq(1, 3, by=0.2)
   y <- seq(1, 5, length.out=4)


Once we've created a vector, how do we access these data? We use index notation. Note that R starts counting from 1 (unlike Python and many other languages, which start from 0). Index notation uses ``[]`` to indicate which index we want to use:

.. code-block:: R

   a_vector = c(1, 2, 3, 4)

   print(a_vector[1])
   print(a_vector[2])
   print(a_vector[3])
   print(a_vector[4])

will print:

.. code-block:: bash

   1
   2
   3
   4


.. note::
 
   R will not error if we access an item out of the range of the vector:

   .. code-block:: R

      print(a_vector[5])

   will instead return ``NA`` (i.e. no-data). This is something that can catch you out later (speaking from experience!).


Apart from accessing vectors a single item at a time, R has some tricks to play too:

.. code-block:: R

   a_vector = c(1, 2, 3, 4)   

   a_vector[c(1,3)] # acces 1 and 3 and return another vector
   a_vector[-1] # access all but the 1st, returning another vector
   a_vector[a_vector < 3] # return any items with a value of < 3. 


Iterating over vectors
~~~~~~~~~~~~~~~~~~~~~~~~

Vectors come into their own when you can loop over them, performing the same task on each item of data. We've done this already in previous chapters. One way is to use the index of each item:

.. code-block:: R

   a_vector <- c(1, 2, 3, 4, 5)

   for(i in 1:length(a_vector)) {
      print(a_vector[i])
   }

Here, we've used the ``:``operator to create a temporary vector of indices that goes from 1 to the length of the vector we want to iterate over. Index notation is useful as it allows you to loop over several vectors simultaneously using the same indexing (assuming they are the same length or you handle the ``NA`` returned for out-of-bounds access). 

We can also simply iterate over the vector items themselves:


   a_vector <- c(1, 2, 3, 4, 5)

   for(item in a_vector) {
      print(item)
   }

Now ``item`` is a variable (so you can name it how you see fit), not an index, containing each vector items, in order. This is much cleaner and more readable code. You have direct access to each item in the vector without having to index the vector (compare ``a_vector[i]`` above to simply using ``item``).
