n1 = int(input())
s1 = set(map(int,input().strip().split()))

n2 = int(input())
s2 = set(map(int,input().strip().split()))

print(len(s1.symmetric_difference(s2)))