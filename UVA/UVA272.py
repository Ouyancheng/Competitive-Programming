import sys

par = 0

for s in sys.stdin:
  for c in s:
    if c == "\"":
      par ^= 1
      if (par & 1) == 1:
        sys.stdout.write("``")
      else:
        sys.stdout.write("''")
    else:
      sys.stdout.write(c)
