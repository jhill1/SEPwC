R conditionals
---------------

As we saw in the coding fundementals, conditionals are a tool to make decisions
in code; they control the flow of code. We can make those decisions based on the state of the program at the time.

We want to inform the user if their climate is either a hot desert, arctic desert, temperate rainforest, or tropical 
rainforest. We ask them to supply either a "high" or "low" temperature and either a "high" or "low" humidity.

.. code-block:: output

   You gave me: "high" temperature and "high" humidity.

   It's a tropical rainforest


How do we write a program that prints out such a statement, based on that input? We know the following:

.. list-table:: Environments
   :header-rows: 1

   * - Temperature
     - Humidity
     - Environment
   * - "high"
     - "high"
     - Tropical rainforest
   * - "high"
     - "low"
     - Hot desert
   * - "low"
     - "high"
     - Temperate rainforest
   * - "low"
     - "low"
     - Arctic desert

So we need to be able to make a decision, based on those the variables, temperature and humidity. 
This is where `if` statements come in.

Basic `if` statement
~~~~~~~~~~~~~~~~~~~~

The `if` statment consists of an `if` condition, followed by zero or more `else if` conditions. A final `else`
statement can be used to capture the situation where everything is `FALSE`.
In general, we can put together multiple conditions. Only the first condition that is `TRUE` is executed.

.. code-block:: R

    if (condition1) {
        <block of statements, executed if condition1 is TRUE>
    } else if (condition2) {
        <block of statements, executed if condition1 is FALSE and condition2 is TRUE>
    } else if (condition3) {
        <block of statements, executed if conditions 1 and 2 are FALSE and condition3 is TRUE>
    } else {
        <block of statements, executed if conditions 1, 2, and 3 are FALSE>
    }

    <next statement of the program>

Let's do one of the conditions of our table above.

.. code-block:: R

   humidity <- "high"
   temperature <- "high"

   if (humidity == "high") {
      print("Either temperate or tropical rainforest")
   }

Here, we've check the value of humidity. If the value is "high", the following is printed:

.. code-block:: output

   [1] "Either temperate or tropical rainforest"
   
If humidity is anything else (including "High", "low", "sweaty"), then nothing is printed.
   
Not the best of code, engineering-wise, but it will work. Try it out.

.. admonition:: Practical exercise

   **Add an `else` block**

    Amend the example below to add an `else` block to print something if humidity is not "high"

.. admonition:: Solution
   :class: toggle

   .. code-block:: R

      humidity <- "HIGH"
      temperature <- "high"

      if (humidity == "high") {
         print("Either temperate or tropical rainforest")
      } else {
         print(paste0("Don't understand ", humidity))
      }

   Here, we've printed the message "Don't understand " with the value of humidity then printed,
   so you should see:

   .. code-block:: output

      [1] "Don't understand HIGH"

We now need to do all combinations, with some logic to decide a few things. There are (as always!) 
a number of ways of doing this. This is using `else if` and boolean operators:

.. code-block:: R

   humidity <- "high"
   temperature <- "high"

   if (humidity == "high" & temperature == "high") {
      print("Tropical rainforest")
   } else if (humidity == "high" & temperature == "low") {
      print("Temperate rainforest")
   } else if (humidity == "low" & temperature == "high") {
      print("Hot desert")
   } else if (humidity == "low" & temperature == "low") {
      print("Arctic desert")
   } else {
      print("I don't understand the inputs")
      print(paste0("Temperature: ", temperature))
      print(paste0("Humidity: ", humidity))
      print("Both should be `high` or `low`")
   }

Here, we've used the `&` operator (and) to check that *both* temperature and humidity are
set appropriately. If the user supplies anything other than "high" or "low" it should print
an message.

..  admonition:: Learn more
    :class: toggle

    Note the error message we gave in the `else` block contains what the user
    had supplied us with. It often helps to print out the variables in quesiton
    when you do the else like this. It helps you, the programmer, to debug and it helps
    the user possibly see what to change to fix. Here, we've also told the user what they should be

    In reality, these variable should be checked before hand and a more informative error message could
    be given *before* any processing takes place. This code is so tiny that it makes no difference.

The second way of working out the logic is by nested `if` statements. Here's an example:

.. code-block:: R

    mark <- 71

    if (mark >= 40 & mark <= 100) {
        if (mark >= 70) {
            print("First!")
        } else if (mark >= 60) {
            print("2:i!")
        } else if (mark >= 50) {
            print("2:2.")
        } else {
            print("3rd")
        }
    } else if (mark > 100) {
        print("This mark is too high.")
    } else if (mark < 0) {
        print("This mark is too low.")
    } else {
        print("Fail :(")
    }

The above code will do the following:

 * Is the mark between 40 and 100 (inclusive)?
 * if so...
    * is the mark greater than or equal to 70? Print "First!" if so
    * if not, is it above 60?
    * if not, is it above 50
    * if not, print "3rd"
 * if not, check the mark isn't more than 100
 * or less than 0
 * otherwise the mark is between 0 and 39 (inclusive), which is a fail mark.

Check you understand the flow of the code and note that the `if` statements are done in order, so 
if the first one is `FALSE`, `mark` must be less than 40 or greater than 100.

.. admonition:: Practical exercise

   **Test the code**

    Try the code above with different values of `mark`. Does it work as expected?

.. admonition:: Solution
   :class: toggle

   It should work for all floating point and integer values of mark. What if you set `mark = "test"`?
   Then what does it do? You should see:

   .. code-block:: output

      [1] "This mark is too high."

    which is becasue 100 is converted to a string by R to do the comparison. "test" is > than "100" ("t" is
    after "1" in the alphabet). You need to be careful of this when doing comparisons!

Now you've seen nested `if` statements in action. Try the final practical exercise of this section.

.. admonition:: Practical exercise

   **Nested `if` version**

   Re-write the environment code using nested `if` statements


.. admonition:: Solution
   :class: toggle

   Your code should look something like the following:

   .. code-block:: R

       humidity <- "high"
       temperature <- "high"

       if (humidity == "high") {
          if (temperature == "high") {
              print("Tropical rainforest")
          } else if (temperature == "low") {
              print("Temperate rainforest")
          } else {
              print(paste0("Didn't understand temperature ", temperature))
          }
       } else if (humidity == "low") {
          if (temperature == "high") {
              print("Hot desert")
          } else if (temperature == "low") {
              print("Arctic desert")
          } else {
              print(paste0("Didn't understand temperature ", temperature))
          }
       } else {
          print("I don't understand the humidity")
          print(paste0("Humidity: ", humidity))
          print("Should be `high` or `low`")
       }
      
   The advantage here is we can have more nuanced error messages (relating to temperature or humidity, ratehr than both), but
   there is repeated code and it might be harder to follow the logic. I prefer the previous version, but this works just fine.
