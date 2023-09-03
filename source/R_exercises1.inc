R Exercises
------------

Try the following exercsies. For any of the exercises, feel free to type out the code and try it for real first, or figure out and see if you were right.

.. admonition:: Exercise

    Will the code below work?

    .. code-block:: R
    
        a <- 45
        name <- "Fred"

        if (a > name) {
            print(paste("You have a great name,",name,"!"))
        } else {
            print("Numbers are greater")
        }


.. admonition:: Solution
   :class: toggle

   Yes! In R, the number is "coerced" into a string for comparison. You then end up 
   doing string comparisons. This is something to watch out for in R. R will do this
   coercion for most datatypes and hence can introduce bugs if you're not careful.


.. admonition:: Exercise

    What is printed here?

    .. code-block:: R
    
        limit = 15
        
        for (i in seq(13,limit,2)) {
            print(i)
        }


.. admonition:: Solution
   :class: toggle

   The numbers 13 and 15 are printed. The range goes in steps of 2 so we have i = 13, then 15. The sequence
   then stops at 15 inclusive.


.. admonition:: Exercise

    What is printed here?

    .. code-block:: R
    
        for (C in seq(-20,41,5)) {
            F = 9.0/5.0*C + 32
        }
        print(paste(C, F))


.. admonition:: Solution
   :class: toggle

   This one is tricky! What is printed are the last values of the loop, so "40   104.0". The print 
   statement is outside the loop, so is only run when the loop is finished.

.. admonition:: Exercise

    Write a program to convert some old data in square feet to SI units (metres squared).
    1 foot = 0.3048 metres. So 1 foot squared is 0.092903 metres squared.

    Out data goes from 2 ft sq to 20 ft sq in steps of 2, inclusive. Print your conversions.

.. admonition:: Solution
   :class: toggle

    .. code-block:: R
    
        conversion = 0.092903
        for (sqft in seq(2,20,2)) {
            sqm = sqft * conversion
            print(paste(sqft, sqm))
        }


