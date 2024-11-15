Our first coding exercise
==========================

We are going to write a very simple application to keep track of 
a to-do list. The application will be based around the CLI and take
three commands: list, add and remove. You add an item to the list using the `add`
option, remove using the `remove` option and print out the current list
using `list`. 

To keep tabs on what items are on the list we wil lsave the list to a 
text file (yes, this does mean you could just edit the text file...
I didn't say this was a realistic application...).

We can do this in either R or Python. This coding exercise is very similar
to the final assignment in terms of a skeleton code, functions to complete
and a test suite to check it's working OK.

What to do
----------

`cd` into a directory where you want to do this work. Then go to the repository
and fork it. Then run:

.. code-block:: cli
   :caption: |cli|
   
   git clone git@github.com:[USERNAME]/SEPwC_formative.git

With your username and (assuming you didn't change it) the repo name above.

You should then see `python` and `R` folders with a `todo.py` or `todo.R` and the answers.
`cd` into your language and open up the file. 

In the file you'll see a skeleton code; three functions that need to be completed, 
but their structure is ready for you. You'll also see some completed functions
that parse command line arguments.

Inside the folder you checked out there's also a `test` folder. In there you'll 
find a `test_script` and a file called `test_list.txt`. These are the tests. Open
the `test_script` file and have a look at the tests.

.. code-block:: python
   :caption: |python|

   import pytest
   import sys
   import os
   import shutil
   from pylint.lint import Run
   from pylint.reporters import CollectingReporter
   sys.path.insert(0,"../")
   sys.path.insert(0,"./")
   from dataclasses import asdict
   import todo
   test_file = "test/test_list.txt"
   
   class TestTodoList():
   
   def test_list_tasks(self):
       todo.TASK_FILE = test_file
       task_list = todo.list_tasks()
       expected_list ="1. Item 1\n2. Item 2\n3. Item 3\n4. Item 4\n5. Item 5"
                
       assert task_list == expected_list

and for R:

.. code-block:: R
   :caption: |R|

   suppressPackageStartupMessages({
   library(testthat)
   })

   # load in the script you want to test
   source("../todo.R", local=TRUE)
   test_file <- "test_list.txt"


   # tests --------------------
   test_that("list_tasks works correctly", {
      # Assuming test_file is defined and the necessary setup is done
  
     TASK_FILE <<- test_file
  
     task_list <- list_tasks()
     expected_list <- "1. Item 1\n2. Item 2\n3. Item 3\n4. Item 4\n5. Item 5"
  
     expect_equal(task_list, expected_list)
   })

You can run the tests now; they should fail as you have no code, but go ahead:

.. code-block:: python
   
