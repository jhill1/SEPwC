print("Welcome to the number guessing game!")
print("I have thought of a number between 1 and 100")
print("You have 5 tries to guess")
print("Can you guess what it is?")

number <- sample(1:100, 1)
guess <- 0
# we create a guess that cannot be the answer...
tries <- 0
max_tries <- 5

while (tries < max_tries) {
    print("Type your guess")
    guess = as.numeric(readLines(file("stdin"),1))
    tries <- tries + 1
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
print("Sorry, too many tries. I win!")

