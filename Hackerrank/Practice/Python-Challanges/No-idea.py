# Enter your code here. Read input from STDIN. Print output to STDOUT
line = map(int,raw_input().split())

n = line[0]
m = line[1]

ans = 0
arr = []
s1 = set()
s2 = set()

line = map(int,raw_input().split())

for i in range(0,n):
    arr.append(line[i])
    
line = map(int,raw_input().split())

for i in range(0,m):
    s1.add(line[i])

line = map(int,raw_input().split())

for i in range(0,m):
    s2.add(line[i])
    
for i in range(0,n):
    if arr[i] in s1:
        ans += 1
    elif arr[i] in s2:
        ans += -1
        
print ans