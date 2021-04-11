from cs50 import get_float

while True:
    dollars = get_float("Change owed in dollars?")
    if dollars >= 0:
        break

cents = round(dollars * 100)
coins = 0

if cents >= 25:
    while True:
        cents -= 25
        coins += 1
        if cents < 25:
            break

if cents >= 10:
    while True:
        cents -= 10
        coins += 1
        if cents < 10:
            break

if cents >= 5:
    while True:
        cents -= 5
        coins += 1
        if cents < 5:
            break

if cents >= 1:
    while True:
        cents -= 1
        coins += 1
        if cents < 1:
            break

print(coins)