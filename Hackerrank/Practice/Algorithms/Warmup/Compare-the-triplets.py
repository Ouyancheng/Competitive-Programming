#!/bin/python3

import sys

alice = 0
bob = 0

def cmp(a,b):
    global alice
    global bob
    if a>b:
        alice = alice + 1
    elif a<b:
        bob = bob + 1

def solve(a0, a1, a2, b0, b1, b2):
    cmp(a0,b0)
    cmp(a1,b1)
    cmp(a2,b2)
    return (alice,bob)
    # Complete this function

a0,a1,a2 = input().strip().split(' ')
a0,a1,a2 = [int(a0),int(a1),int(a2)]
b0,b1,b2 = input().strip().split(' ')
b0,b1,b2 = [int(b0),int(b1),int(b2)]
result = solve(a0, a1, a2, b0, b1, b2)
print (" ".join(map(str, result)))


