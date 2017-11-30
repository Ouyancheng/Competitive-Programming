import sys

n = int(sys.stdin.readline())
l1 = list(map(int,sys.stdin.readline().split()))

m = int(sys.stdin.readline())
l2 = list(map(int,sys.stdin.readline().split()))

cnt = 0
hi = 0

for i in xrange(0,n):
  for j in xrange(0,m):
  	if l2[j] % l1[i] == 0 and l2[j]/l1[i] >= hi:
  		if l2[j]/l1[i] > hi:
  			hi = l2[j]/l1[i]
  			cnt = 1
  		else:
  			cnt += 1

print cnt