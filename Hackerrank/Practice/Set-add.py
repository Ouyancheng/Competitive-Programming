# Enter your code here. Read input from STDIN. Print output to STDOUT

se = set()

num = int(raw_input())

for x in range(0,num):
    country = raw_input()
    se.add(country)
    
print len(se)