Debugging
----------

Once you have some understanding of the error and the cause you can start to debug 
your code. The easiset form of debugging is called "print debugging". You insert
print statements around code to output the contents of variables to help you 
understand the flow of the program. The downside of this debugging is you have to 
add and then *remove* a lot of print statements!

If I'm not sure why code isn't working, and perhaps more importantly, where, 
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

However print debugging can be unweidly, producing massive amoutns of output
that can be be as hard to decipher as the error you're trying to fix.

EXERCISE on print debugging (R and Python)

Another way, alluded to above, is within R (or Rstudio) or ipython (or Spyder) is
to run your code. When you get to the error your variables are still available and
you can explore them to see what might be wrong.

EXERCISE on console debugging (R and Python)

I've been writing code in one form or another for *cough*35 years*cough* and
I *still* use print debugging, especially in when writing code for multiple
cores. It's incredibly useful and quick. However, some bugs or errors are
best fixed using specialist debugging software called a debugger. 


pdb 

R equiv?


Exercises: Bug spotting (inc running debugger)
 
