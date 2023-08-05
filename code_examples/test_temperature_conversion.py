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

    def test_that_will_fail(self):
        temp_c = temperature_conversion.toCentigrade(50)

        self.assertEqual(temp_c, 2)

if __name__ == '__main__':
    unittest.main()

