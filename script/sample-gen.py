#!/usr/local/bin/python

import random
import string
from sets import Set

random.seed(2018)

string_set = Set()

while len(string_set) < 1000000:
    i = 0
    s = ""
    while i < 6:
        n = int(random.expovariate(0.1))
        if n >= 26:
            continue
        i = i + 1
        s += string.lowercase[n]
    string_set.add(s)

f = open("training.txt","w")
f.write("topology: 6 10 1\n")
r = 0
for s in sorted(string_set):
    f.write("in: " + s + "\nout: " + str(r) + "\n")
    r = r + 1

f.close()
