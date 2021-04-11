from cs50 import get_int
import sys


while True:
    snumber = input("Card number: ")
    if snumber.isdigit() and len(snumber) <= 16:
        break


cardlength = len(snumber)
number = int(snumber)
totalsum = 0
for i in range(0, cardlength):
    if i == 0:
        digit = ((number // 10**i) % 10)
        totalsum += digit
    elif i % 2 == 1:
        digit = 2 * ((number // 10**i) % 10)
        if digit > 9:
            totalsum += digit // 10 + digit % 10
        else:
            totalsum += digit
    else:
        digit = ((number // 10**i) % 10)
        totalsum += digit
if totalsum % 10 != 0:
    print("INVALID")
    sys.exit(1)


if cardlength == 13 and snumber.find("4", 0, 1) != -1:
    print("VISA")
    sys.exit(0)
elif cardlength == 15 and (snumber.find("34", 0, 2) == 0 or snumber.find("37", 0, 2) == 0):
    print("AMEX")
    sys.exit(0)
elif cardlength == 16:
    if snumber.find("4", 0, 1) != -1:
        print("VISA")
        sys.exit(0)
    elif (number // 10 ** 14) > 50 and (number // 10 ** 14) < 56:
        print("MASTERCARD")
        sys.exit(0)
else:
    print("INVALID")
    sys.exit(1)