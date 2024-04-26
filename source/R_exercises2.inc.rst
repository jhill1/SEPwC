R Exercises 2
--------------------

.. admonition:: Exercise

    Write the number guessing game out in R. You may need
    to search the internet for how to handle random numbers.

..  admonition:: Solution
    :class: toggle

    This is my code
    
    .. code-block:: R
        :caption: |R|

        print("Welcome to the number guessing game!")
        print("I have thought of a number between 1 and 100")
        print("Can you guess what it is?")

        number <- sample(1:100, 1)
        guess <- 0
        # we create a guess that cannot be the answer...

        while (guess != number) {
            print("Type your guess")
            guess <- as.numeric(readLines(file("stdin"),1))
            if (guess < number) {
                print("Your guess is less than my number")
                print("Try again")
            } else if (guess > number) {
                print("Your guess is greater than my number")
                print("Try again")
            } else if (guess == number) {
                print("Correct! You guessed right!")
                print("Bye!")
                stop()
            }
        }


.. admonition:: Exercise

    Modify the guessing game code to include a maximum
    number of tries (5). If the number of tries is 5 then 
    print a message to say the user lost the game

..  admonition:: Solution
    :class: toggle

    This is my code
    
    .. code-block:: R
        :caption: |R|

        print("Welcome to the number guessing game!")
        print("I have thought of a number between 1 and 100")
        print("You have 5 tries to guess")
        print("Can you guess what it is?")

        number <- sample(1:100, 1)
        guess <- 0
        tries <- 0
        max_tries <- 5
        # we create a guess that cannot be the answer...
        
        while (tries < max_tries) {
            tries <- tries + 1
            print("Type your guess")
            guess <- as.numeric(readLines(file("stdin"),1))
            if (guess < number) {
                print("Your guess is less than my number")
                print("Try again")
            } else if (guess > number) {
                print("Your guess is greater than my number")
                print("Try again")
            } else if (guess == number) {
                print("Correct! You guessed right!")
                print("Bye!")
                stop()
            }
        }

        print("Sorry, you had 5 goes. I win!")


