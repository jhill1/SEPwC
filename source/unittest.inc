Python: unittest
~~~~~~~~~~~~~~~~~~

Python has a few testing packages. ``unittest`` is a very common one. It 

We're going to test our Farenheit to Celcius and vice-vera functions from the first R chapter. Let's get these two functions in an R test file and save it:

.. code-block:: Python

   def toFarenheit(Centigrade):

       F = 9.0/5.0*Centigrade + 32.0

       return F

   def toCentigrade(Farenheit):

       C =  (Farenheit - 32) * 5/9;

       return C

Save the contents as ``temperature_conversion.py``.

We can then use a seperate file to create our tests. ``unittest`` is based around objects and methods within that object. Each method is a test. For our check on the above two functions we will create a single object, with three methods to run a total of five tests. Create a file called ``test_temperature_conversion.py`` (note the filename convention here, prepend ``test_`` to the filname of the thing you're testing).


.. code-block:: Python


   import unittest
   import temperature_conversion

    class TestTemperatureConversion(unittest.TestCase):

        def test_c_to_f(self):

            temp_c = temperature_conversion.toCentigrade(50)

            self.assertEqual(temp_c, 10)
            self.assertIsInstance(temp_c, float)

        def test_f_to_c(self):

            temp_f = temperature_conversion.toFarenheit(10)

            self.assertEqual(temp_f, 50)
            self.assertIsInstance(temp_f, float)

        def test_that_will_fail(self)
            temp_c = temperature_conversion.toCentigrade(50)

            self.assertEqual(temp_c, 2

    if __name__ == '__main__':
        unittest.main()

We can run that from the command line:

.. code-block:: bash

    python3 test_temperature_conversion.py

which gives the output:

.. code-block:: bash

    ..F
    ======================================================================
    FAIL: test_that_will_fail (__main__.TestTemperatureConversion)
    ----------------------------------------------------------------------
    Traceback (most recent call last):
      File "test_temperature_conversion.py", line 23, in test_that_will_fail
        self.assertEqual(temp_c, 2)
    AssertionError: 10.0 != 2

    ----------------------------------------------------------------------
    Ran 3 tests in 0.000s

    FAILED (failures=1)

You may not want to run all the tests; just a specific test. We can make use of python -m flag

.. code-block:: bash

   python3 -m unittest test_temperature_conversion.TestTemperatureConversion.test_that_will_fail

This runs just the test named ``test_that_will_fail`` in the class ``TestTemperatureConversion`` in the file ``test_temperature_conversion``


