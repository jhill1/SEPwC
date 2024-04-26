Python examples
~~~~~~~~~~~~~~~~
.. index::
  single; Syntax Errors; python

If we make an error in our Python code we will receive a message like:

.. code-block:: Python
    :caption: |python|

    impot numpy
    
gives

.. code-block:: output
    :caption: |cli| |python|

    impot numpy
          ^
    SyntaxError: invalid syntax

Python generally tells you what the error is and even points to it in a small representation of your code.
Consider the following simple code.

.. code-block:: Python
    :caption: |python|

    def calculate_sum(a, b):
        total = a + b
        return total

    x = 5
    y = 10
    z = calculate_sum(x, w)
    print(z)

will give you:

.. code-block:: bash
    :caption: |cli| |python|

          5 x = 5
          6 y = 10
    ----> 7 z = calculate_sum(x, w)
          8 print(z)

    NameError: name 'w' is not defined

Line number, exact error and some context. Easy! The only thing is to work out what is meant by the error type.

Some common errors you will see and their meaning:

 * **NameError**: The variable or function doesn't exist
 * **TypeError**: You've tried to do an operation using the wrong kind of data, e.g. add an integer and a string.
 * **IndexError**: You've tried to acces a list or dictionary out of the range
 * **AttributeError**: You've tried to use a method on an object that doesn't exist

In more complex code, Python will also give a *stack trace* where you can see the various
functions that eventually lead to where the error is. Let's look at this simple code:

.. code-block:: Python
    :caption: |python|

    # example.py
    def say(name):
        print('Hello, ' + nam)

    say('Jon')

There's an error here (``nam`` instead of ``name``). When we run this:

.. code-block:: bash
    :caption: |cli| |python|


    Traceback (most recent call last):
      File "test.py", line 5, in <module>
        say('Jon')
      File "test.py", line 3, in say
        print('Hello, ' + nam)
    NameError: name 'nam' is not defined

We read this from the bottom up. The error is a ``NameError``. It is on line 3 of our code. We caused this by calling
the ``say`` function on line 5. We can see this is a bug in the ``say`` function. If that's our code we can fix, if it's not
re-read any documentation for the function and check you're passing in the correct data. 
