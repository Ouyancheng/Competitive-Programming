import sys

n = int(sys.stdin.readline())
l = list(map(int,sys.stdin.readline().split()))

prev = [-1] * 100005
dist = [-1] * 100005
can = [1] * 100005
out = []

for i in xrange(0,n):
	if prev[l[i]] == -1:
		prev[l[i]] = i
		dist[l[i]] = 0
	elif dist[l[i]] == 0:
		dist[l[i]] = i - prev[l[i]]
		prev[l[i]] = i
	else:
		d = i - prev[l[i]]
		if d == dist[l[i]]:
			prev[l[i]] = i
		else:
			can[l[i]] = 0

for i in xrange(0,n):
	if can[l[i]] == 1:
		can[l[i]] = 0
		out.append(l[i])

out.sort()

print len(out)

for i in xrange(0,len(out)):
	print out[i], dist[out[i]]