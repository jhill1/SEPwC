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
            F = 9/5*C + 32
          
        print(C, F)


.. admonition:: Solution
   :class: toggle

   This one is tricky! What is printed are the last values of the loop, so "40   104.0". The print 
   statement is not indented to within the loop, so is only run when the loop is finished.



