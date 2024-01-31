import random
import sys

print("Welcome to the number guessing game!")
print("I have thought of a number between 1 and 100")
print("You have 5 tries to guess")
print("Can you guess what it is?")

number = random.randint(1,100)
guess = 0
tries = 0
max_tries = 5
# we create a guess that cannot be the answer...

while tries < max_tries:
    guess = int(input("What's your guess? "))
    tries += 1
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

print("Sorry, you had 5 goes. I win!")

