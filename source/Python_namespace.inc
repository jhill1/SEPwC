Python: namespace
-------------------------------
.. index::
  single: namespace; Python

Namespace and scope are the section of code where your variables are valid. A namespace
is a collection of currently defined symbolic names; basically a dictionary of variable
names pointing to the object in memory. There are several layers of namespaces in Python:

 1. Built-in
 2. Global
 3. Enclosing
 4. Local

These have different lifespans and Python handles the creation and deletion of the namespaces
as our code is executed. 

The namespaces
~~~~~~~~~~~~~~~

The built-in namespace contains all of Python's built-in objects which are
available every time you run any Python. We can
look at this:

.. code-block:: Python
    :caption: |python|

    dir(__builtins__)
    Out[1]: 
    ['ArithmeticError',
     'AssertionError',
     'AttributeError',
     'BaseException',
     'BlockingIOError',
     'BrokenPipeError',
     'BufferError',
     ...

You can see things like error objects, ``False`` etc in the list generated, as well as built-in
functions like ``len()``. 

The global namespace is created at the main level of any python program. As soon as the main body of any
Python code is executed this namespace created. You may have more than one of these as ``import`` 
statements create a global namespace for themselves. However, when you read ``global`` in terms if namespace
think of it as the one associated with your program. 

Local and enclosing namespaces are like sub-namespaces when you create a function. The variables (and functions!) 
created only exist within that function.

Python Scope
~~~~~~~~~~~~~
.. index::
  single: Scope; Python

These namespaces mean variables of the same name can exist at the same time. As long as they are
in a different namespace they won't interfere with each other. But how does Python know which one
to use. This is the concept of scope. 

Python looks for variables in the reverse order of the list above, so we will look
for a variable in:

 1. Local
 2. Enclosing
 3. Global
 4. Built-in

If you look for ``max()`` function, Python will look in the local, then enclosing, then global
then the built-in namespaces. 

.. code-block:: python
    :caption: |python|

    x = "global"

    def func1():
        x = "enclosing"

        def func2():
            print(x)

        func2()

    func1()
    print(x)

Before you run this, what will be printed? Now let's add another ``x``:

.. code-block:: python
    :caption: |python|

    x = "global"

    def func1():
        x = "enclosing"

        def func2():
            x = "local"
            print(x)

        func2()
        print(x)

    func1()
    print(x)

See if you can work out what will be printed this time. Our final exercise:

.. code-block:: python
    :caption: |python|
   
    def func1():
        x = "enclosing"

        def func2():
            x = "local"
            print(x)

        func2()
        print(x)

    func1()
    print(x)

What happens this time? Did you use a fresh ipython or script?

So how do you modify variables that aren't in the current scope?

.. code-block:: python
    :caption: |python|
    
    x = 20
    def func1():
        x = 40
        print(x)

    func1()
    print(x)

The ``x`` inside ``func1`` is a local reference. As ``func1`` exits that reference
is deleted. The ``print(x)`` then uses the ``x`` in the global namespace. 

What if ``x`` is a list and we try and modify it?

.. code-block:: python
    :caption: |python|

    x = [20, 40, 60]

    def func1():
        x[1] = 41
        print(x)

    func1()
    print(x)

Here, both the global *and* `local` give the same answer. We've modified the global variable within
the function. However, if we create a list of the same variable name, we'll have similar
behaviour to the previous example:

.. code-block:: python
    :caption: |python|

    x = [20, 40, 60]

    def func1():
        x = [20, 41, 60]
        print(x)

    func1()
    print(x)

If we want ``func1`` to actually modify the global variable we have to tell Python explicitly:

.. code-block:: python
    :caption: |python|

    x = [20, 40, 60]

    def func1():
        global x
        x = [20, 41, 60]
        print(x)

    func1()
    print(x)

If you create a global variable within a function it will be available to the global namespace:

.. code-block:: python
    :caption: |python|

    def func1():
        global x
        x = [20, 41, 60]
        print(x)

    func1()
    print(x)

(run in a new ipython or as a script as ``x`` has already been created). Constructs such as ``if``, ``with``, etc
do not create scope. 
