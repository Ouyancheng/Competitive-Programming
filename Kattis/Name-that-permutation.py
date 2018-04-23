import sys

n, k, o, a = 0, 0, [0] * 51, [x for x in range(1, 51)]

def conv(cur, base):
	if base < n + 1:
		o[n - base] = cur % base
		conv(cur // base, base + 1)

def go(cur, mask):
	if mask != 0:
		cnt, i = -1, -1
		while cnt != o[cur]:
			i += 1
			if mask & (1 << i):
				cnt += 1
		sys.stdout.write(str(a[i]) + " \n"[cur == n - 1])
		go(cur + 1, mask & ~(1 << i))

def main():
	for line in sys.stdin:
		global n, k
		n, k = list(map(int, line.split(' ')))
		conv(k, 1)
		go(0, (1 << n) - 1)

main()