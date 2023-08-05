library(testthat)
context("Temperature function testing");
source("temperature_conversion.R");

test_that(desc = "Fahrenheit to Celsius", code = {
  
  temp_C <- F_to_C(50);

  # Test that the result is the correct value
  expect_that( object = temp_C, condition = equals(10) );
  
  # Test that the result is numeric
  expect_that( object = is.numeric(temp_C), condition = equals(TRUE) );
})

test_that(desc = "Celsius to Fahrenheit", code = {
  
  temp_F <- C_to_F(10);
  
  # Test that the result is the correct value
  expect_that( object = temp_F, condition = equals(50) );
  
  # Test that the result is numeric
  expect_that( object = is.numeric(temp_F), condition = equals(TRUE) );
})

# This test will fail
test_that(desc = "Fahrenheit to Celsius wrong", code = {
    temp_F <- F_to_C(50);
    expect_that( object = temp_F, condition = equals(2) );
})
