s1 = set();
s2 = set();

n1 = int(raw_input())
line = map(int,raw_input().split())
for x in line:
    s1.add(x)

n2 = int(raw_input())
line = map(int,raw_input().split())

for x in line:
    s2.add(x)
    
print len(s1.intersection(s2))