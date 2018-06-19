#!/usr/local/bin/python
import sys
import random
import string
from sets import Set

random.seed(2018)

string_set = Set()

if len(sys.argv) != 2:
    total_num = 10
else:
    total_num = int(sys.argv[1])
while len(string_set) < total_num:
    i = 0
    s = ""
    while i < 6:
        n = int(random.expovariate(0.1))
        if n >= 26:
            continue
        i = i + 1
        s += string.lowercase[n]
    string_set.add(s)

f = open("testing.txt","w")
f.write(str(total_num) + "\n")
pair_list = zip(sorted(string_set), range(total_num))
for p in pair_list:
    f.write("in: " + p[0] + "\nout: " + str(p[1]) + "\n")
f.close()

random.shuffle(pair_list)
f = open("training.txt","w")
f.write(str(total_num) + "\n")
for p in pair_list:
    f.write("in: " + p[0] + "\nout: " + str(p[1]) + "\n")
f.close()
