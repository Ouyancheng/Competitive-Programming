import sys

n = int(sys.stdin.readline())
t = 0
r = list(map(int,sys.stdin.readline().split()))
cap = list(map(int,sys.stdin.readline().split()))

cap.sort()
cap.reverse()

for x in r:
	t += x

if t > cap[0] + cap[1]:
	print "NO"
else:
	print "YES"
