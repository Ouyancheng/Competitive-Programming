n = input()
s = set(map(int, raw_input().split())) 
sum = 0

nc = int(raw_input())

for i in range(0,nc):
    line = raw_input().split()
    cmd = line[0]
    if cmd == "pop":
        if len(s) > 0:
            s.pop()
    elif cmd == "discard" or cmd == "remove":
        e = int(line[1])
        if e in s:
            s.discard(e)
            
for i in s:
    sum += i

print sum