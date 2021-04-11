import sys
from cs50 import get_string

if len(sys.argv) != 2:
    print("Usage: ./caesar key")
    sys.exit(1)

key = int(sys.argv[1]) % 26
text = get_string("plaintext: ")

print("ciphertext:", end="")
for i in text:
    if (ord(i) >= 65 and ord(i) < 90):
        if (ord(i) + key) > 90:
            print(chr((ord(i) + key) % 90 + 64), end="")
        else:
            print(chr(ord(i) + key), end="")
    elif (ord(i) >= 97 and ord(i) <= 122):
        if (ord(i) + key > 122):
            print(chr((ord(i) + key) % 122 + 96), end="")
        else:
            print(chr(ord(i) + key), end="")
    else:
        print(i, end="")
print()
