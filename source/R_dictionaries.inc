R dictionaries
----------------------------

Dictionaries are linked lists; rather than accessing items via a numerical index, you access via a ``key``. A dictionary therefore contains a list of keys and a list of corresponding values. The keys have to be unique, but the values do not.

R doesn't have a built-in dictionary datatype, *but* vectors, matricies, lists etc can behave like dictionaries. 

.. code-block:: R

    telephone = c('Bob'=3452345, 'Mildred'=532354)
   
You can then access using the keys, much like in a list:

.. code-block:: R

    telephone['Bob']

You can add to a dictionary by using the ``[]`` notation:

.. code-block:: R

   telephone['Grenville'] = 435353
   print(telelphone)

To check if a key is used in a dictionary, you can use the ``%in%`` keyword. However, R will look in the ``values`` by default, so we have to tell it to look in the ``names()``:

.. code-block:: R

   'Bob' %in% names(telephone)
   'Jack' %in% names(telephone)



Looping with dictionaries
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Like lists, dictionaries are at their most powerful in loops. Also like lists there are a number of ways of looping over them. You can loop as you would a vector:

.. code-block:: R

    knights = c('gallahad'='the pure', 'robin'='the brave')
    for (k in knights) {
        print(k)
    }

which loops over the values. If we want to loop over the keys:

.. code-block:: R

    knights = c('gallahad'='the pure', 'robin'='the brave')
    for (k in names(knights)) {
        print(paste(k, knights[k]))
    }


Some useful tricks with R dictionaries
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Because R doesn't have built in dictionaries, it's a bit cumbersome to 
delete items and manipulate a dictionary in place. You often find yourself
reassigning the dictionary to the same variable. For example:

.. code-block:: R

    telephone[names(telephone) != "Grenville"]
    
Gives the `telephone` dictionary without `"Grenville"`. To make that change permanaent, 
you reassign the output back into telephone:


.. code-block:: R

    telephone <- telephone[names(telephone) != "Grenville"]

If any code you write makes eavy use of dictionaries, it is worth writing little
helper functions to do this so you code is cleaner.

R does have libraries that make proper dictionaries. `hash` is one such library. 
If you are making heavy use of dictionaries, it may be better to use that library instead!

