import sys

big = 1 << 31

for s in sys.stdin:
  print(s.strip('\n'))
  d1 = s.find('+')
  d2 = s.find('*')
  if d1 != -1:
    s = s[:d1] + ' ' + s[d1] + ' ' + s[d1+1:]
  else:
	  s = s[:d2] + ' ' + s[d2] + ' ' + s[d2+1:]
  t = s.split()
  t = [int(t[0]), t[1], int(t[2])]
  if t[0] >= big:
    print("first number too big")
  if t[2] >= big:
    print("second number too big")
  if eval(str(t[0]) + str(t[1]) + str(t[2])) >= big:
    print("result too big")
