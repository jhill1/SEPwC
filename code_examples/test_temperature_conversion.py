import pytest
import temperature_conversion

class TestTemperatureConversion():

    def test_c_to_f(self):

        temp_c = temperature_conversion.toCentigrade(50)

        assert temp_c==10
        assert type(temp_c)==float

    def test_f_to_c(self):

        temp_f = temperature_conversion.toFarenheit(10)

        assert temp_f == 50
        assert type(temp_f) == float

    def test_that_will_fail(self):
        temp_c = temperature_conversion.toCentigrade(50)

        assert temp_c == 2


