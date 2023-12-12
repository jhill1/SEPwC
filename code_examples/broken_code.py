# If number is even, print the sub of all even numbers from
# 1 to N, inclusive
# If number if odd, print som of all odd numbers from 
# 1 to N inclusive
#
#For example, when 
# number is 10, the output should be 30 (2+4+6+8+10). When 
# number is 9, the output should be 25 (1+3+5+7+9).

number = 9

i = 1
total = 0
while i <= number:
    if number % 2 == 0:
        if i % 2 == 0:
            total = total + i
    if number % 2 == 1:
        if i % 2 == 1:
            total = total + i

    i = i + 1

print(total)
