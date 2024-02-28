Testing code
============

You've spend days writing the most elegant and beautiful code imaginable. It's readable, well designed and runs quickly. How do you know it runs correctly? How do you know how easy it is to break? This is where testing comes in.

Testing is integral to writing software as otherwise there is no point in writing it. You will, of course, test in some way as you write code as you will run your code to check it doesn't give syntax errors at least! In this chapter you’ll learn how to transition from informal *ad hoc* testing (simple testing), to automated testing (also known as unit testing). This will:

 * Fewer bugs. Because you’re explicit about how your code should behave, you will have fewer bugs. The reason why is a bit like the reason double entry book-keeping works: because you describe the behaviour of your code in two places, both in your code and in your tests, you are able to check one against the other. With informal testing, it’s tempting to just explore typical and authentic usage, similar to writing examples. However, when writing formal tests, it’s natural to adopt a more adversarial mindset and to anticipate how unexpected inputs could break your code.

 * Better code structure. Code that is well designed tends to be easy to test and you can turn this to your advantage. If you are struggling to write tests, consider if the problem is actually the design of your function(s). The process of writing tests is a great way to get free, private, and personalised feedback on how well-factored your code is. Functions that are easier to test are usually easier to understand and recombine in new ways.

 * Bug fixing. When we start to fix a bug, we first convert it into a (failing) test. This is wonderfully effective at making your goal very concrete: make this test pass. This is basically a special case of a general methodology known as test driven development (see later chapter on software development).

 * Robust code. If you know that all the major functionality of your package is well covered by the tests, you can confidently make big changes without worrying about accidentally breaking something.

In this chapter we will discover the different types of tests and how to formalise those tests into something that can be automated.

Simple testing
---------------

Whilst most guides and internet sites deal with more formalised testing, we should start at a more fundamental level. Testing code involved running it. You should run your code often to check for syntax errors and unexpected errors. Rather than spending hours writing code, then test; it is much more productive to write a block of code, then test the code to that point. 

Basic testing involves created a subset of your input data (if any) and printing out variables to check they are what you expect them to be, given the data read in. This is *not* a robust method of testing code, but will give you confidence as you go along. This is also useful if you don't know *exactly* what you'll get after a block of code (e.g. from an external library). By printing it out, we can check what ``type`` and what the data looks like. In a formal test it's impossible to do that until you see the data anyway. 

You *are* testing your code by running code like this, but informally. The problem will arise in a few months time when you come back to this and you will struggle to remember all the informal tests you ran. If you want to add a new feature you'll probably break some of the past informal tests. 

Example of loading a data set and checking it (strip all but header and three rows), print and check. Need to create an awkward data set to to make the point, e.g. getting datetimes correct and indexing.


Regression tests
------------------

When it comes to formal testing, the first type of test is called a *regression test*. This takes a full run of the code and checks that output is what is expected. This could be based on theoretical consideration or from past executions of the code. The distinction to other kinds of tests is that the whole program is run from start to finish.

Examples of theoretical and past behaviour


Unit tests
------------

Whilst regression tests test the whole executable, unit tests only test a single function or object within the code. The generally check against theoretical results (or simple calculations) with strictly controlled input to the function. This is often where we test unexpected behaviour too; for example putting two strings into a function to add two numbers: do we get a sensible error message? 

Unit tests are designed to test each function to the limits and make sure it returns the right answers and behaves correctly if the wrong kind of data is passed in. If all the program's functions are tested then, in theory, the whole program should work. 

Unit tests also help with debugging. If a user reports a bug, the error message often gives the function that it occurred in. Using the user's data you can create a unit test to confirm the bug (replicate it). Then debug your code until that new test passes.

Examples; simple function with assert, assert nearly, etc.


Static tests
-------------

The above tests involve running the code. Another type of testing is called static testing or *linting*. This checks the syntax of the code against specified standards. It was invented initially for the C programming language where the programmer has to manage memory themselves and a linter helped spot potential issues there. For R and Python a linter check our code against published standards. 

For Python, the standards are set by the community and written up as "PEP" (Python Enhancement Proposal) documents. In R the standards are also community-based but with less formal acceptance. A common style used is the ``tidyverse`` style. 

Regardless of the style chosen, the important thing is *consistency*. Consistency within functions/modules/objects is most important, consistency within projects is next, consistency across projects is least important. It is also important to know when to *break* consistency. Your golden rule for breaking a linter recommendation is if it doesn't improve readability of the code. Code is read more than it is written and the computer doesn't care about readability as long as it's valid syntax. 

Whilst linters are valuable tools to check your consistency they are not hard and fast rules to follow. 


Examples from R and Python

UI tests
----------

User interface testing is perhaps the hardest thing to test. When presented with any type of user interface (GUI, CLI, or even through files) users will do the oddest things from your point of view as a programmer. This is normal as we are all the sum of our experiences. However, sticking to conventions helps ameliorate some of the potential issues here. 

UI testing is a type of regression testing. You can automate CLI-based UI's easily. Automating GUI's is trickier, but possible. For our purposes we will stick to CLIs.

Example of testing a CLI

Testing frameworks
---------------------

The tests above have been manual in nature. Testing comes into it's own when it's automated. It may still need to be initiated manually (see below for fully automatic, continuous testing), but all tests are run and the results summarised automatically. 

Both R and Python have testing frameworks; modules/libraries that help set-up, run and tear-down all tests in your code. We'll cover each in turn, but skip to whichever language you've chosen.

.. include:: pytest.inc
.. include:: testthat.inc
.. include:: continuous_testing.inc

