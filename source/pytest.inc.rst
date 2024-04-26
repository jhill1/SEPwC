Python: pytest
~~~~~~~~~~~~~~~~~~
.. index::
  single: Pytest; Python

Python has a few testing packages. ``pytest`` is a very common one. It 

We're going to test our Fahrenheit to Celsius and vice-versa functions from the first Python chapter. Let's get these two functions in an Python test file and save it:

.. code-block:: Python
   :caption: |python|

   def toFahrenheit(Centigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

   def toCentigrade(Fahrenheit):

       C =  (Fahrenheit - 32) * 5/9;

       return C

Save the contents as ``temperature_conversion.py``.

We can then use a separate file to create our tests. ``pytest`` is largely automated in terms of finding and running tests; we simply need to stick to a naming convention of having ``test_*.py`` or ``*_test.py`` in the filename. ``pytest`` will then find and run those files in the current directory and any subdirectories. You can organise your tests into files, with our without classes. If you do you a class it *must* begin with "Test". For our check on the above two functions we will create a single class, with three methods to run a total of five tests. Create a file called ``test_temperature_conversion.py`` (note the filename convention here, prepend ``test_`` to the filename of the thing you're testing).


.. code-block:: Python
    :caption: |python|


    import pytest
    import temperature_conversion

    class TestTemperatureConversion():

        def test_c_to_f(self):

            temp_c = temperature_conversion.toCentigrade(50)

            assert temp_c==10
            assert type(temp_c)==float

        def test_f_to_c(self):


            assert temp_f == 50
            assert type(temp_f) == float

        def test_that_will_fail(self):
            temp_c = temperature_conversion.toCentigrade(50)

            assert temp_c == 2

We can run that from the command line:

.. code-block:: bash
    :caption: |cli|

    pytest test_temperature_conversion.py

which gives the output:

.. code-block:: bash
    :caption: |cli|

    ================================= test session starts =================================
    platform linux -- Python 3.6.9, pytest-6.2.4, py-1.10.0, pluggy-0.13.1
    rootdir: /home/jh1889/work/teaching/SEPwC/code_examples
    collected 3 items                                                                     

    test_temperature_conversion.py ..F                                              [100%]

    ====================================== FAILURES =======================================
    ____________________ TestTemperatureConversion.test_that_will_fail ____________________

    self = <test_temperature_conversion.TestTemperatureConversion object at 0x7fb900264518>

        def test_that_will_fail(self):
            temp_c = temperature_conversion.toCentigrade(50)
        
    >       assert temp_c == 2
    E       assert 10.0 == 2

    test_temperature_conversion.py:23: AssertionError
    =============================== short test summary info ===============================
    FAILED test_temperature_conversion.py::TestTemperatureConversion::test_that_will_fail
    ============================= 1 failed, 2 passed in 0.15s =============================


This gives a summary of the system, including the version of Python and pytest; the directory the test was run from and the number of tests (3). The main results comes next with the filename and ``..F``. This tells us 2 tests have passed and one has failed. Details of the failure are then posted underneath, with the line of code and then (very useful) the values used in the assertion.
    
You may not want to run all the tests; just a specific test. We can tell pytest to do just that:

.. code-block:: bash
   :caption: |cli|

   pytest test_temperature_conversion.py::TestTemperatureConversion::test_that_will_fail

This runs just the test named ``test_that_will_fail`` in the class ``TestTemperatureConversion`` in the file ``test_temperature_conversion.py``

``pytest`` has a lot of other useful features such as marking tests, checking for wanted exceptions and fixtures. Have a look around the documentation of pytest to learn more.
