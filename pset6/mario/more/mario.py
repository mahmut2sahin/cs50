from cs50 import get_int

while True:
    height = get_int("Height= ")
    if height > 0 and height < 9:
        break

for i in range(height):
    for j in range(height - (i + 1)):
        print(" ", end=(""))
    for m in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for n in range(i + 1):
        print("#", end="")
    print()
