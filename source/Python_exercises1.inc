Python Exercises
--------------------

Try the following exercsies. For any of the exercises, feel free to type out the code and try it for real first, or figure out and see if you were right.

.. admonition:: Exercise

    Will the code below work?

    .. code-block:: Python
    
        a = 45
        name = "Fred"

        if a > name:
            print("You have a great name, "+name+"!")


.. admonition:: Solution
   :class: toggle

   No. You cannot compare a number to a string


.. admonition:: Exercise

    What is printed here?

    .. code-block:: Python
    
        limit = 15
        
        for (i in range(13,limit,2)):
            print(i)


.. admonition:: Solution
   :class: toggle

   The number 13 is printed only. The range goes in steps of 2, so hits 15 on the second
   iteration, which is equal to the upper limit of range, so the loop terminates.

.. admonition:: Exercise

    What is printed here?

    .. code-block:: Python
    
        for C in range(-20,41,5):
            F = 9.0/5.0*C + 32
          
        print(C, F)


.. admonition:: Solution
   :class: toggle

   This one is tricky! What is printed are the last values of the loop, so "40   104.0". The print 
   statement is not indented to within the loop, so is only run when the loop is finished.


.. admonition:: Exercise

    What's with ``9.0/5.0``? In all the exercises above converting centigrade to Farenheit I've used ``9.0/5.0``.
    Why not ``9/5``? Let's try it.

    .. code-block:: Python
    
        C = -20
        # Where therefore expect F to be -4
        F = 9.0/5.0*C + 32  
        print(C, F)
        F = 9/5*C + 32  
        print(C, F)


.. admonition:: Solution
   :class: toggle

   This one is very subtle. ``9/5*C`` is done in integer maths. ``9/5`` comes out as ``1`` (try it in python). You therefore get the
   wrong answer. By typing ``9.0/5.0`` we push python into using floating point maths so you get ``1.8``. You only need one floating
   point number in an operation to make it all floaitng point, so just using ``9.0/5`` will suffice. This is a very easy bug to introduce
   into any code (I have!) so it's worth getting in the habit of typing ``9.0`` or ``9.`` when using any number you mean to be a float
   in python.


.. admonition:: Exercise

    Write a program to convert some old data in square feet to SI units (metres squared).
    1 foot = 0.3048 metres. So 1 foot squared is 0.092903 metres squared.

    Out data goes from 2 ft sq to 20 ft sq in steps of 2, inclusive. Print your conversions.

.. admonition:: Solution
   :class: toggle

    .. code-block:: Python
    
        conversion = 0.092903
        for sqft in range(2,21,2):
            sqm = sqft * conversion
            print(sqft, sqm)


