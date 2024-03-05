R objects
----------------------------

We discussed objects back in :ref:`Objects and classes` which are containers for both
data and functions to manipulate that data.

R has support for objects and almost everything in R is actually an object. Those vectors,
dateframes, etc are all objects in R. However, to
create your own object you must first create a ``Class``. R has several types of classes, 
S3, S4, and RC (and actually some others too). Here, we'll stick to RC which requires a formal
definition of the class and integrates the methods within the class in a more 
Object-Oriented way. 

.. code-block:: R

    Person <- setRefClass("Person",
        fields = list(name = "character", age = "numeric"))

.. code-block:: R

    alice <- Person$new(name="Alice",age=41)
    print(alice)

This is not a particularly useful object, but shows the basic principles. You can acess
the fields using the ``$`` notation:

.. code-block:: R

    alice$name
    alice$age

    alice$age <- 42
    alice$age

We need to add some methods/functions to go along with our class.
Let's create the dog class we thought about previously:

.. code-block:: R

    Dog <- setRefClass("Dog",

            fields = list(
                name = "character",
                age = "numeric",
                colour = "character",
                state = "character"),

            methods = list(
                bark = function(){
                    print("Woof!")
                },
                walkies = function() {
                    state <<- "muddy"
                },
                beCleaned = function() {
                    if (state == "clean") {
                        print(paste(name," is already clean"))
                    } else if (state == "muddy") {
                        print(paste(name ," is now clean"))
                        state <<- "clean"
                    }
                }
            )
        )


    wilf <- Dog$new(name="Wilf",age=5,colour="Brown")
    wilf$bark()
    wilf$walkies()
    wilf$state

There are a few things here that are worth pointing out. First is the structure; note that the
fields are ``list``ed and then the functions are also ``list``ed. It's easy to forget a comma 
in there! Next is the use of ``<<-``. You'll learn more about this in the namespaces section, 
but this is to make it clear which ``state`` you are referring to. Finally, note that both the
functions and fields are accessed using the ``$`` notation. 

One of the key things about classes is that they can inherit other classes. We can therefore
build complex stacks of classes using base classes. Let's create a class for a Guide Dog:

.. code-block:: R

    GuideDog <- setRefClass("GuideDog",

            contains = "Dog",

            fields = list(
                training = "logical"
            ),

            methods = list(
                bark = function() {
                    print("Guide dogs don't bark")
                },
                complete_training = function() {
                    training <<- T
                }
            )
        )


So here we've added a new function ``complete_trianing`` and overridden the ``bark`` function. 

.. code-block:: R

    buddy <- GuideDog$new(name="Buddy",age=3,colour="tan",training=F)
    buddy$bark()

There are a lot other features of objects in R, but the main reason for learning about them here is that
most other modules/libraries in R create objects of some kind. You therefore need to be familiar with the
idea of a variable, e.g. ``buddy`` being able to have a function to call using the ``$`` notation. When you see
this; you are dealing with an object.
