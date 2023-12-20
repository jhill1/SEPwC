Python Exercises 2
--------------------

.. admoition:: Exercise

    Write the number guessing game out in Python. You may need
    to search the internet for which module
    to import to do random integers

..  admonition:: Solution
    :class: toggle

    This is my code
    
    .. code-block:: python

        import random
        import sys

        print("Welcome to the number guessing game!")
        print("I have thought of a number between 1 and 100")
        print("Can you guess what it is?")

        number = random.randint(1,100)
        guess = 0
        # we create a guess that cannot be the answer...

        while guess != number:
            guess = int(input("What's your guess? "))
            if guess < number:
                print("Your guess is less than my number")
                print("Try again")
            elif guess > number:
                print("Your guess is greater than my number")
                print("Try again")
            elif guess == number:
                print("Correct! You guessed right!")
                print("Bye!")
                sys.exit()



