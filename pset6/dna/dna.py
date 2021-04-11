import sys
import csv

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")

with open(sys.argv[2]) as f:
    seq = f.read()

with open(sys.argv[1]) as f:
    reader = csv.reader(f)
    STR = next(reader)
    STR.remove("name")


with open(sys.argv[1]) as f:
    dna = csv.DictReader(f)
    dnalist = list(dna)


max_str = {}
for estiar in STR:
    max_counts = 0
    for i in range(len(seq)):
        counts = 0
        if seq[i: (i + len(estiar))] == estiar:
            j = 0
            while seq[(i + j): (i + j + len(estiar))] == estiar:
                counts += 1
                j += len(estiar)
            if counts > max_counts:
                max_counts = counts
    max_str[estiar] = max_counts


for person in dnalist:
    counteql = 0
    for strs in max_str:
        if person[strs] != str(max_str[strs]):
            break
        else:
            counteql += 1
            continue
    if counteql == len(STR):
        print(person["name"])
        sys.exit()

print("No match")
