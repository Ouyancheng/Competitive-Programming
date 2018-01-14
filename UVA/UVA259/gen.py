import random

t = random.randint(20, 100)

for i in xrange(t):
	for j in xrange(10):
		yes = random.choice([0, 1]);
		users = random.randint(1, 3)
		connections = random.randint(1, 5)
		if yes:
			print "%c%d" % (chr(j + ord('A')), users),
			s = set()
			for k in xrange(connections):
				s.add(str(random.randint(0, 9)))
			print "".join(list(s))
	print