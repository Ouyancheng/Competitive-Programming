from collections import Counter
import sys

def solve(s):
    c = Counter(s)
    z = 3 - len(c)
    o = len([x for x in c.values() if (x&1)])
    e = 3 - o;
    if z == 2:
        return len(s)
    if o == 0 or e == 0:
        return 2
    return 1

n = int(raw_input())

for i in xrange(0,n):
    line = sys.stdin.readline().strip()
    print solve(line)