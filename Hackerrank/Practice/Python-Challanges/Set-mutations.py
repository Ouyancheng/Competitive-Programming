ans = 0
n = int(input())
a = set(map(int,input().strip().split()))
b = set()
q = int(input())
for i in range(0,q):
    x,y = input().strip().split()
    b = set(map(int,input().strip().split()))
    if x == "intersection_update":
        a.intersection_update(b)
    elif x == "update":
        a.update(b)
    elif x == "symmetric_difference_update":
        a.symmetric_difference_update(b)
    elif x == "difference_update":
        a.difference_update(b)

for i in a:
    ans += i
    
print(ans)