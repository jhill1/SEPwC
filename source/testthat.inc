R: testthat
~~~~~~~~~~~~

The first thing that you need to do is install the testthat R package. This can be done from CRAN using the code below.

.. code-block:: R

   install.packages("testthat")


Once testthat is installed, you can load it into your R sessions just like any other R package.

.. code-block:: R

   library(testthat)

We're going to test our Farenheit to Celcius and vice-vera functions from the first R chapter. Let's get these two functions in an R test file and save it:

.. code-block:: R

    F_to_C <- function(F_temp){
        C_temp <- (F_temp - 32) * 5/9;
        return(C_temp);
    }

    C_to_F <- function(C_temp){
        F_temp <- (C_temp * 9/5) + 32;
        return(F_temp);
    }

Save the contents as ``temperature_conversion.R``.

We use the ``test_that`` function of the testthat package to write sime simple tests for our two functions. The ``test_that`` function follows a simple structure with two arguments: ``desc`` provides a description (in quotes) of whatever is being tested, and ``code`` provides whatever code (within curly brackets) to test.

Within the bracketed code to be tested, one or more ``expect_that`` functions are run; each call to ``expect_that`` is an independent test. The ``expect_that`` function takes two arguments: ``object`` is the object that is being examined by the function and ``condition`` is the condition that the object is meant to satisfy.

.. code-block:: R

    test_that(desc = "Fahrenheit to Celsius", code = {
      
      temp_C <- F_to_C(50);

      # Test that the result is the correct value
      expect_that( object = temp_C, condition = equals(10) );
      
      # Test that the result is numeric
      expect_that( object = is.numeric(temp_C), condition = equals(TRUE) );
    })

We can create the same test for the ``C_to_F`` function:

.. code-block:: R

    test_that(desc = "Celsius to Fahrenheit", code = {
      
      temp_F <- C_to_F(10);
      
      # Test that the result is the correct value
      expect_that( object = temp_F, condition = equals(50) );
      
      # Test that the result is numeric
      expect_that( object = is.numeric(temp_F), condition = equals(TRUE) );
    })

You can run those two tests if you've compied them into your R session (along with the ``temperature_conversion.R`` file: hint ``source``).

The better idea is to simply run all the tests at once. So let's create a test file with the following contents (includign a fake test that will fail).


.. code-block:: R

    library(testthat);
    context("Temperature function testing");
    source("temperature_conversion.R");

    test_that("Fahrenheit to Celsius", {
      
      temp_C <- F_to_C(50);
      
      # Test that the result is numeric
      expect_that( is.numeric(temp_C), equals(TRUE) );
      
      # Test that the result is the correct value
      expect_that( temp_C, equals(10) );
    })

    test_that("Celsius to Fahrenheit", {
      
      temp_F <- C_to_F(10);
      
      # Test that the result is numeric
      expect_that( is.numeric(temp_F), equals(TRUE) );
      
      # Test that the result is the correct value
      expect_that( temp_F, equals(50) );
    })

    # This test will fail
    test_that(desc = "Fahrenheit to Celsius wrong", code = {
        temp_F <- F_to_C(50);
        expect_that( object = temp_F, condition = equals(2) );
    })

Save that as ``test-temperature_conversion.R`` (note the convention here; use the same filename as what is to be tested, with ``test-`` pre-pended). 

We can run that from the command line:

.. code-block:: bash

    Rscript test-temperature_conversion.R 

which gives the output:

.. code-block:: R

    Test passed 🎊
    Test passed 🥳
    ── Failure (???): Fahrenheit to Celsius wrong ──────────────────────────────────
    `x` not equal to `expected`.
    1/1 mismatches
    [1] 10 - 2 == 8
    Backtrace:
        ▆
     1. └─testthat::expect_that(object = temp_F, condition = equals(2))
     2.   └─testthat (local) condition(object)
     3.     └─testthat::expect_equal(x, expected, ..., expected.label = label)

    Error in reporter$stop_if_needed() : Test failed
    Calls: test_that -> <Anonymous>
    Execution halted

If you're in an R session you can run all tests in a directory:

.. code-block:: R

   test_dir(".")


which gives the output:

.. code-block:: R

    ✔ | F W S  OK | Context
    ✖ | 1       4 | Temperature function testing                                                                          
    ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
    Failure (test-temperature_conversion.R:30:5): Fahrenheit to Celsius wrong
    `x` not equal to `expected`.
    1/1 mismatches
    [1] 10 - 2 == 8
    Backtrace:
        ▆
     1. └─testthat::expect_that(object = temp_F, condition = equals(2)) at test-temperature_conversion.R:30:4
     2.   └─testthat (local) condition(object)
     3.     └─testthat::expect_equal(x, expected, ..., expected.label = label)
    ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

    ══ Results ═══════════════════════════════════════════════════════════════════════════════════════════════════════════
    ── Failed tests ──────────────────────────────────────────────────────────────────────────────────────────────────────
    Failure (test-temperature_conversion.R:30:5): Fahrenheit to Celsius wrong
    `x` not equal to `expected`.
    1/1 mismatches
    [1] 10 - 2 == 8
    Backtrace:
        ▆
     1. └─testthat::expect_that(object = temp_F, condition = equals(2)) at test-temperature_conversion.R:30:4
     2.   └─testthat (local) condition(object)
     3.     └─testthat::expect_equal(x, expected, ..., expected.label = label)

    [ FAIL 1 | WARN 0 | SKIP 0 | PASS 4 ]
    Error: Test failures


