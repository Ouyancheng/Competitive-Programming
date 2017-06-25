#!/bin/python

import sys

num = []

lo = 0;
hi = 0;

a,b,c,d,e = input().strip().split(' ')
a,b,c,d,e = [int(a),int(b),int(c),int(d),int(e)]

num.append(a);
num.append(b);
num.append(c);
num.append(d);
num.append(e);

num.sort();

lo = num[0] + num[1] + num[2] + num[3]
hi = num[1] + num[2] + num[3] + num[4]

print(lo,hi)