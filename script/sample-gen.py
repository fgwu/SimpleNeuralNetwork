#!/usr/local/bin/python

import random
import string
from sets import Set

random.seed(2018)

string_set = Set()

total_num = 1000
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
pair_list = zip(sorted(string_set), range(total_num))
for p in pair_list:
    f.write("in: " + p[0] + "\nout: " + str(p[1]) + "\n")
f.close()

random.shuffle(pair_list)
f = open("training.txt","w")
for p in pair_list:
    f.write("in: " + p[0] + "\nout: " + str(p[1]) + "\n")
f.close()
