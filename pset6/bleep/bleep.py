from cs50 import get_string
from sys import argv


def main():
    if len(argv) != 2:
        print("Usage: bleep.py banned.txt")
        exit(1)

    banlist = list()
    f = open(argv[1], "r")
    for line in f:
        banlist.append(line.rstrip("\n"))

    text = get_string("What message would you like to censor?")
    split = text.split()

    for word in split:
        loword = word.lower()
        if loword in banlist:
            for i in range(len(word)):
                print("*", end="")
            print(" ", end="")
        else:
            print(word, end=" ")
    print()


if __name__ == "__main__":
    main()