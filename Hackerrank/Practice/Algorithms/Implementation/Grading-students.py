#!/bin/python3

import sys

def solve(grades):
    for i in range(0,len(grades)):
        if grades[i] >= 38:
            dist = 5-int(grades[i]%5)
            if dist < 3:
                grades[i] = grades[i] + dist
    return grades
    # Complete this function

n = int(input().strip())
grades = []
grades_i = 0
for grades_i in range(n):
   grades_t = int(input().strip())
   grades.append(grades_t)
result = solve(grades)
print ("\n".join(map(str, result)))

