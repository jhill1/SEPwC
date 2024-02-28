Python Exercises
--------------------

Try the following exercises. For any of the exercises, feel free to type out the code and try it for real first, or figure out and see if you were right.

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

.. youtube:: 04-ylxjUaAk
    :align: center


.. admonition:: Exercise

    What is printed here?

    .. code-block:: Python
    
        limit = 15
        
        for (i in range(13,limit,2)):
            print(i)

.. admonition:: Solution
   :class: toggle

   The number 13 is printed only. However, this is only the case after we've fixed the code!

    .. code-block:: Python
    
        limit = 15
        
        for i in range(13,limit,2):
            print(i)

   The range goes in steps of 2, so hits 15 on the second
   iteration, which is equal to the upper limit of range, so the loop terminates.

.. youtube:: 1cuDMdeTSmE
    :align: center

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

.. youtube:: KTQ2r287cvY
    :align: center

