Debugging
----------

Once you have some understanding of the error and the cause you can start to debug 
your code. The easiest form of debugging is called "print debugging". You insert
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
of any key variables during the loop. When you code breaks you know exactly which
loop index it was on. Running this in RStudio or Spyder means you can then 
explore your data using that index. Very helpful!

However print debugging can be unwieldy, producing massive amounts of output
that can be be as hard to decipher as the error you're trying to fix.

.. admonition:: Practical exercise - Python

   .. code-block:: python 
    
        # If number is even, print the sum of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print sum of all odd numbers from 
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

    There were errors in syntax and logic! My version is below. More elegant solutions
    can be found too.
        
    .. code-block:: python 

        # If number is even, print the sum of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print sum of all odd numbers from 
        # 1 to N inclusive
        #
        # For example, when 
        # number is 10, the output should be 30 (2+4+6+8+10). When 
        # number is 9, the output should be 25 (1+3+5+7+9).

        number = 10

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

.. admonition:: Practical exercise - R

    .. code-block:: R
    
        # If number is even, print the sum of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print sum of all odd numbers from 
        # 1 to N inclusive
        #
        # For example, when 
        # number is 10, the output should be 30 (2+4+6+8+10). When 
        # number is 9, the output should be 25 (1+3+5+7+9).

        number = 10

        i = 1

        while (i < nomber) {
            if number %% 2 = 0 {
                total = total + number
            }
            i = i + 1
        }

        print(total)


..  admonition:: Solution
    :class: toggle

    There were errors in syntax and logic! My version is below. More elegant solutions
    can be found too.
        
    .. code-block:: R

        # If number is even, print the sum of all even numbers from
        # 1 to N, inclusive
        # If number if odd, print sum of all odd numbers from 
        # 1 to N inclusive
        #
        # For example, when 
        # number is 10, the output should be 30 (2+4+6+8+10). When 
        # number is 9, the output should be 25 (1+3+5+7+9).

        number = 10

        i = 1
        total = 0
        while (i <= number) {
            if (number %% 2 == 0) {
                if (i %% 2 == 0) {
                    total = total + i
                }
            }
            if (number %% 2 == 1) {
                if (i %% 2 == 1) {
                    total = total + i
                }
            }

            i = i + 1
        }

        print(total)


Console debugging
~~~~~~~~~~~~~~~~~

Another way, alluded to above, is within R (or Rstudio) or ipython (or Spyder) is
to run your code. When you get to the error your variables are still available and
you can explore them to see what might be wrong.

Let's do a similar exercise to the above in the console. Launch either the Python or R
console (in Spyder or RStudio is fine).

.. admonition:: Practical exercise - Python

    .. code-block:: python 
    
        # Print each combo of description-animal combinations
        # If you are about to print "funny dog", break out of the loop
        
        descriptions = ['funny`, 'cute', 'friendly']
        animals = ['koala", 'cat', 'dog', 'panda']

        for d in description:
            for a in animals:
                print(d + a)


.. admonition:: Solution
    :class: toggle

    My first error was:

    .. code-block:: python

        File "<ipython-input-2-c3f93577d321>", line 4
            descriptions = ['funny`, 'cute', 'friendly']
                                 ^
        SyntaxError: invalid syntax
    
    I then tried to fix that line alone in the console:

    .. code-block:: python

        descriptions = ['funny', 'cute', 'friendly']

    That works, so now I can try the next line by itself. That also gives an error:

    .. code-block:: python

        In [4]: animals = ['koala", 'cat', 'dog', 'panda']
           ...: 
          File "<ipython-input-4-35bcfad5a05c>", line 1
            animals = ['koala", 'cat', 'dog', 'panda']
                                   ^
        SyntaxError: invalid syntax

    I see the issue: `"` instead of `'`. So again, get that line right in the console. 

    Got that done, so now I can copy and paste the loop only. Yet another error:

    .. code-block:: python

        NameError                                 Traceback (most recent call last)
        <ipython-input-6-ca6d0650fc82> in <module>()
        ----> 1 for d in description:
              2     for a in animals:
              3         print(d + a)

        NameError: name 'description' is not defined
    
    I can see the issue (forgot an `s`). so fix that and try again. I can fix it by pressing up and 
    navigating to the right place and fix the code. I can then use the arrows to go back to the bottom
    of the code block and press return to re-run. An now the code produces something!

    .. code-block:: python

        In [7]:         for d in descriptions:
           ...:             for a in animals:
           ...:                 print(d + a)
           ...: 
        funnykoala
        funnycat
        funnydog
        funnypanda
        cutekoala
        cutecat
        cutedog
        cutepanda
        friendlykoala
        friendlycat
        friendlydog
        friendlypanda

    Not quite right, but runs now at least. A little trick in ipython is to use the `%history` which gives
    all the code I've run. I can grab that and re-write my base code. I can then debug as above or continue
    in the ipython console.

    My final code is:

    .. code-block:: python 
           
        # Print each combo of description-animal combinations
        # If you are about to print "funny dog", break out of the loop
        
        descriptions = ['funny', 'cute', 'friendly']
        animals = ['koala', 'cat', 'dog', 'panda']

        print_message = True
        for d in descriptions:
            for a in animals:
                message = d + " " + a
                if message == "funny dog":
                    print_message = False
                
                if print_message:
                    print(message)

            if not print_message:
                break
       

.. admonition:: Practical exercise - R

    .. code-block:: R 
    
        # Print each combo of description-animal combinations
        # If you are about to print "funny dog", break out of the loop
        
        descriptions = c('funny", 'cute"', 'friendly')
        animals = c('koala", 'cat', 'dog', 'panda')

        for (d in description) {
            for (a in animals) {
                print(paste(d,a))
            }
        }


.. admonition:: Solution
    :class: toggle

    My first error was, copying and pasting the code in the R console:

    .. code-block:: 

        >         # Print each combo of description-animal combinations
        >         # If you are about to print "funny dog", break out of the loop
        >         
        >         descriptions = c('funny", 'cute"', 'friendly')
        Error: unexpected symbol in "        descriptions = c('funny", 'cute"'
        >         animals = c('koala", 'cat', 'dog', 'panda')
        Error: unexpected symbol in "        animals = c('koala", 'cat"
        > 
        >         for (d in description) {
        +             for (a in animals) {
        +                 print(paste(d,a))
        +             }
        +         }
        Error: object 'description' not found


    A lot of errors. We can probably fix them from top to bottom. So let's
    try dealing with the first error by editing the `descriptions` variable.
    We can try in the console to get it to work. Pressing up in the R console until 
    we get to the line. Then edit the line; note the backtick vs `'`. so
    `descriptions = c('funny', 'cute', 'friendly')`. That works! Do the same 
    for the `animals` variable too.


    Now let's deal with the loops error; once we have the two vectors set-up
    properly, copy and paste the loop:

    .. code-block:: R

        >         for (d in description) {
        +             for (a in animals) {
        +                 print(paste(d,a))
        +             }
        +         }
        Error: object 'description' not found
    
    Typo! It should be `descriptions`. Fix that by pressing up, and editing the code; you'll then
    need to copy and paste the rest of the loop in. Success! Running code!

    .. code-block:: R

        >         for (d in descriptions) {
        +             for (a in animals) {
        +                 print(paste(d,a))
        +             }
        +         }
        [1] "funny koala"
        [1] "funny cat"
        [1] "funny dog"
        [1] "funny panda"
        [1] "cute koala"
        [1] "cute cat"
        [1] "cute dog"
        [1] "cute panda"
        [1] "friendly koala"
        [1] "friendly cat"
        [1] "friendly dog"
        [1] "friendly panda"

    Not quite right, but runs now at least. Now we need to edit the loop to get the logic right.

    My final code is:

    .. code-block:: R
           
        # Print each combo of description-animal combinations
        # If you are about to print "funny dog", break out of the loop
        
        descriptions = c('funny', 'cute', 'friendly')
        animals = c('koala', 'cat', 'dog', 'panda')

        print_message = TRUE
        for (d in descriptions) {
            for (a in animals) {
                message = paste(d,a)
                if (message == "funny dog") {
                    print_message = FALSE
                }
                if (print_message) {
                    print(message)
                }
            }
        }


I've been writing code in one form or another for *cough* 35 years *cough* and
I *still* use print debugging, especially in when writing code for multiple
cores (parallel programming). It's incredibly useful and quick. However, some bugs or errors are
best fixed using specialist debugging software called a debugger. We'll cover 
debuggers in the optional mini-courses at the end.
 
