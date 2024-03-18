Python objects
---------------
..index::
  single: Objects; python

We discussed objects back in :ref:`Objects and classes` which are containers for both
data and functions to manipulate that data.

Python has support for objects and almost everything in Python is actually an object. To
create your own object you must first create a ``Class``.

.. code-block:: python

    class MyClass:
        variable = 5

.. code-block:: python

    obj = MyClass()
    print(obj.variable)

This is not a particularly useful object! All objects in python come with a special
function which is called when you make a new object: ``__init__()``. This function
allows you to set up anything when a new object is made from you ``Class``.

Let's create the dog class we thought about previously:

.. code-block:: python

    class Dog:

        def __init__(self, name, age, colour):

            self.name = ""
            self.age = 0
            self.colour = ""
            self.state = "clean"

        def bark(self):
            print("Woof!")

        def walkies(self):
            self.state = "muddy"

        def beCleaned(self):
            if (self.state == "clean"):
                print(name + " is already clean")
            elif (self.state == "muddy"):
                print(name + " is now clean")
                self.state = "clean"


    wilf = Dog("Wilf",5,"Brown")
    wilf.bark()
    wilf.walkies()
    wilf.state

There are a few things here that are worth pointing out. First is the use of ``self``. This is a variable
that is the current object; it has to be the first variable in any function within the class. This allows
the ``wilf.bark()`` to work as ``wilf`` is passed as the ``self`` variable. 

One of the key things about classes is that they can inherit other classes. We can therefore
build complex stacks of classes using base classes. Let's create a class for a Guide Dog:

.. code-block:: python

    class GuideDog(Dog)
        pass

This creates a new class from the Dog class previously. It doesn't add anything as yet, but we have
all of the variables and functions from the ``Dog`` class. We can add to or override any of these.

.. code-block:: python

    class GuideDog(Dog):
        
        def __init__(self, name, age, colour):
            super().__init__(name, age, colour)
            self.completed_training = False

        def bark(self):
            print("Guide dogs don't bark")

        def complete_trianing(self):
            self.completed_training = True

So here we've added a new function ``complete_trianing`` and overridden the ``bark`` function. 

.. code-block:: python

    buddy=GuideDog("Buddy","3","tan")
    buddy.bark()

There are a lot other features of objects in Python, but the main reason for learning about them here is that
most other modules/libraries in Python create objects of some kind. You therefore need to be familiar with the
idea of a variable, e.g. ``buddy`` being able to have a function to call using the ``.`` notation. When you see
this; you are dealing with an object.
