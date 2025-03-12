Python: dictionaries
-------------------------------
.. index::
  pair: dictionary; python

Dictionaries are linked lists; rather than accessing items via a numerical index, you access via a ``key``. A dictionary therefore contains a list of keys and a list of corresponding values. The keys have to be unique, but the values do not.

Python has dictionaries as an in-built datatype, set up using the ``{}`` braces:

.. code-block:: Python
   :caption: |python|

   telephone = {'Bob': 3452345, 'Mildred': 532354}
   
You can then access using the keys, much like in a list:

.. code-block:: Python
   :caption: |python|

   telephone['Bob']

You can add to a dictionary by using the ``[]`` notation:

.. code-block:: Python
   :caption: |python|

   telephone['Grenville'] = 435353
   print(telephone)

To check if a key is used in a dictionary, you can use the ``in`` keyword:

.. code-block:: Python
   :caption: |python|

   'Bob' in telephone
   'Jack' in telephone


In addition to the ``{}`` construction you can also use ``dict`` construction:

.. code-block:: Python
   :caption: |python|

   telephone = dict([('Bob', 3452345), ('Mildred', 53235)])
   # or even
   telephone = dict(Bob=3452345, Mildred=53235)
   # works for simple string keys

Looping with Python dictionaries
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: loop; dictionary

Like lists, dictionaries are at their most powerful in loops. Also like lists there are a number of ways of looping over them.

.. code-block:: Python
    :caption: |python|

    knights = {'gallahad': 'the pure', 'robin': 'the brave'}
    for k, v in knights.items():
        print(k, v)

    # or
    for knight in knights:
        print(knight, knights[knight])

Useful dictionary functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: dictionary; functions

Dictionaries also come with a number of useful functions. Commonly used ones are ``keys()`` and 
``values()`` which return a list of the keys and values respectively. Both of these return lists
which can be looped over, e.g.

.. code-block:: Python
    :caption: |python|
 
    knights = {'gallahad': 'the pure', 'robin': 'the brave'}
    names = knights.keys()
    for n in names:
        print(knights[n])

is a common idiom you will see in Python code. 

.. admonition:: Practical exercise - capital cities

   Create a dictionary that holds a country as the key, and the capital
   city as the value, e.g. Germany - Berlin, UK - London.

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        capitals = {
            "Germany": "Berlin",
            "UK": "London",
            "USA": "Washington DC",
            "France": "Paris",
            "Burkina Faso": "Ouagadougou"
        }


.. admonition:: Practical exercise - capital cities: add

    Add more countries to your list, without creating a new variable.

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        capitals["Italy"] = "Rome"
        capitals["Mexico"] = "Mexico City"



.. admonition:: Practical exercise - capital cities: delete

    Remove the UK from the list. You may have to search the internet to find the answer to this one!

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        del capitals["UK"]

.. admonition:: Practical exercise - capital cities: edit

    Edit the value for one of your capitals. Ouagadougou is also known as Wagadugu

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        capitals["Burkina Faso"] = "Wagadugu"

.. admonition:: Practical exercise - capital cities: functions

    Find out how you might do the following:

     - Check if a key exists in a dictionary
     - Check the length of a dictionary
     - Create a copy of a dictionary
     - Clear a dictionary

..  admonition:: Solution
    :class: toggle

    .. code-block:: Python
        :caption: |python|

        if ("UK" in captials):
            print(capitals["UK"])

        print(len(capitals))

        capitals_mkII = capitals.copy()

        capitals.clear()

.. youtube:: 1VRrLLx_5oo
    :align: center
