import sys

ans = 0

n = int(sys.stdin.readline())

for i in xrange(0,n):
	l = list(map(int,sys.stdin.readline().split()))
	f = 0
	if l[0] + l[1] + l[2] >= 2:
		f = 1
	ans += f

print ans