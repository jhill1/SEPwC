Python: dictionaries
-------------------------------

Dictionaries are linked lists; rather than accessing items via a numerical index, you access via a ``key``. A dictionary therefore contains a list of keys and a list of corresponding values. The keys have to be unique, but the values do not.

Python has dictionaries as an in-built datatype, set up using the ``{}`` braces:

.. code-block:: Python

   telephone = {'Bob': 3452345, 'Mildred': 532354}
   
You can then access using the keys, much like in a list:

.. code-block:: Python

   telephone['Bob']

You can add to a dictionary by using the ``[]`` notation:

.. code-block:: Python

   telephone['Grenville'] = 435353
   print(telelphone)

To check if a key is used in a dictionary, you can use the ``in`` keyword:

.. code-block:: Python

   'Bob' in telephone
   'Jack' in telephone


In addition to the ``{}`` construction you can also use ``dict`` construction:

.. code-block:: Python

   telephone = dict([('Bob', 3452345), ('Mildred', 53235)])
   # or even
   telephone = dict(Bob=3452345, Mildred=53235)
   # works for simple string keys

Looping with dictionaries
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Like lists, dictionaries are at their most powerful in loops. Also like lists there are a number of ways of looping over them.

.. code-block:: Python

    knights = {'gallahad': 'the pure', 'robin': 'the brave'}
    for k, v in knights.items():
        print(k, v)

    # or
    for knight in knights:
        print(knight, knights[knight])

Useful dictionary functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dictionaries also come with a number of useful functions. Commonly used ones are ``keys()`` and ``values()`` which return a list of the keys and values respectively.


