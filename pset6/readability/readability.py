import sys

text = input("Text: ")
textlen = len(text)

sentences = text.count(".") + text.count("?") + text.count("!")
words = text.count(" ") + 1
letters = 0
for i in range(textlen):
    if ord(text[i]) <= 122 and ord(text[i]) >= 65:
        letters += 1


L = (100 / words) * letters
S = (100 / words) * sentences
index = 0.0588 * L - 0.296 * S - 15.8


if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")