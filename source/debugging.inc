Debugging
----------

Once you have some understanding of the error and the cause you can start to debug 
your code. The easiset form of debugging is called "print debugging". You insert
print statements around code to output the contents of variables to help you 
understand the flow of the program. The downside of this debugging is you have to 
add and then *remove* a lot of print statements!

If I'm not sure why code is not working, and perhaps more importantly, where, 
I first add "programming noise"; print statements like:

.. code-block::

    print("PN: 1")

    ... some code ...

    print("PN: 2")

By watching the print statements I can zero in where the code is breaking. I can then 
really zero in on a line or lines of code that are breaking.

If the error is in a loop, it can be helpful to print the loop index and the value
of any key variable sduring the loop. When you code breaks you know exactly which
loop index it was on. Running this in RStudio or Spyder means you can then 
explore your data using that index. Very helpful!

However print debugging can be unweidly, producing massive amounts of output
that can be be as hard to decipher as the error you're trying to fix.

.. admonition:: Practical exercise - Python

    .. code-block:::Python 
    
        # If number is even, print the sub of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print som of all odd numbers from 
        # 1 to N inclusive
        #
        # For example, when 
        # number is 10, the output should be 30 (2+4+6+8+10). When 
        # number is 9, the output should be 25 (1+3+5+7+9).

        number = 10

        i = 1

        while i < nomber:
            if number % 2 = 0:
                total = total + number
            i = i + 1

        print(total)


..  admonition:: Solution
    :class: toggle

    There were erros in syntax and logic! My version is below. More elgant solutions
    can be found too.
        
    .. code-block:::Python 

        # If number is even, print the sub of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print som of all odd numbers from 
        # 1 to N inclusive
        #
        # For example, when 
        # number is 10, the output should be 30 (2+4+6+8+10). When 
        # number is 9, the output should be 25 (1+3+5+7+9).

        number = 9

        i = 1
        total = 0
        while i <= number:
            if number % 2 == 0:
                if i % 2 == 0:
                    total = total + i
            if number % 2 == 1:
                if i % 2 == 1:
                    total = total + i

            i = i + 1

        print(total)

Another way, alluded to above, is within R (or Rstudio) or ipython (or Spyder) is
to run your code. When you get to the error your variables are still available and
you can explore them to see what might be wrong.

EXERCISE on console debugging (R and Python)

I've been writing code in one form or another for *cough* 35 years *cough* and
I *still* use print debugging, especially in when writing code for multiple
cores (parallel programming). It's incredibly useful and quick. However, some bugs or errors are
best fixed using specialist debugging software called a debugger. We'll cover 
debuggers in the optional mini-courses at the end.
 
