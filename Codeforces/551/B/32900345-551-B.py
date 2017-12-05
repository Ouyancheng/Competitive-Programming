import sys
from collections import Counter

def rstr():
    return sys.stdin.readline().rstrip()

def count(s):
    return Counter(s)

sc, sa, sb = rstr(), rstr(), rstr()
ca, cb, cs = count(sa), count(sb), count(sc)
acnt, bcnt, opt, f = [0] * 4

for it in xrange(len(sc)+1):
    lo = len(sc)
    for x,y in cb.items():
        lo = min(cs[x]/y,lo)
        if lo == 0:
            break
    if lo + it > opt:
        opt = lo + it
        acnt, bcnt = it, lo
    for i in xrange(26):
        x = chr(i+ord('a'))
        if cs[x] >= ca[x]:
            cs[x] -= ca[x]
        else:
            f = 1
            break
    if f == 1:
        break

ta, tb, tc = count(sa * acnt), count(sb * bcnt), count(sc)

sys.stdout.write(sa * acnt)
sys.stdout.write(sb * bcnt)
for i in xrange(26):
    x = chr(i+ord('a'))
    sys.stdout.write(str(x) * (tc[x] - (ta[x] + tb[x])))