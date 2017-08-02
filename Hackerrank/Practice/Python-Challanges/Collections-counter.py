from collections import Counter

n = int(input())
arr = Counter(list(map(int,input().split())))
n = int(input())
ans = 0

for i in range(0,n):
    a,b = list(map(int,input().split()))
    if arr[a] > 0:
        ans = ans + b
        arr[a] = arr[a] - 1

print(ans)