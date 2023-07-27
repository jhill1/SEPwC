Solving issues and debugging
=============================

When writing code you will inevitavely get it wrong occasionally. You will therefore always hit some issues when writing any code. Some issues are easy to fix (you've typo'd a library or module), whilst some are 
extremely difficult to fix (a bug deep in a library that is used by a library you use). Here, we're going to concentrate on what kind of issues
you might come across and how you might go about understanding them.

The same kind of issues will crop up for both Python and R. I will give examples of both as we go through.

Types of issues
----------------

There are several types of issues you will come across:

 - warnings: These are not errors. They could be anything from "this code will go out of date in 10 years time" to "you haven't set something you should have. This may not work". Read it carefully and decide if you need to care or not.
 - errors: These are errors and you need to fix them. R and Python will tell you where the error is and often how to fix it. These are your problem to deal with.
 - bugs: These are also errors and you also need to fix them. However, you may get no warnings, or message, just output you didn't expect! A bug is simply unexpected beahviour. It is usually your problem to deal with, however, it is possible the bug is in a library you're using. We will learn how to report these kind of issues if we need to.
 - seg faults: This is a major error in the code. A segmentation fault (or seg fault) is usually caused by accessing memory you shouldn't have access to. In Python and R these are very rare as memory allocation is handled for us, rather than by us. However, libraries like numpy use C and hence we could experience one of these.

Simple issues
--------------

The majority of issues encountered when writing code are really straight forward. You have messed up the syntax, or typo'd a library name, etc. 
This happens a lot. As someone who has used dozens of programming languages over the years I often mix them up and type some weird hybrid
of R, Python, Perl, PHP and/or Matlab. Possibly with a bit of Fortran and C in there too. Each language has it's own idiosynchronies which you 
will get used to. In addiiton, it's very easy to type a `[` instead of a `{`. 

What makes these errors simple though is that you are told about them when you run the code! Sometimes a bit obscurely, but once you can decipher
the error message 

Examples of R issues, Python issues; type errors and the like

Examples of warnings


Bugs
------

Code with a simple bug (some namespace thing, probably)

Security bugs - e.g. parsing user code without checking

Examples of reporting a bug - github

Examples of bugs

Example of sag fault

Fixing Errors
-------------

Read error carefully

Search for the error (and include other info).

Reminder that the error is theirs most of the time

Get them to think about what this means for a user using their code 

Debuggers
----------

pdb 

R equiv?


Exercises: Bug spotting (inc running debugger)

