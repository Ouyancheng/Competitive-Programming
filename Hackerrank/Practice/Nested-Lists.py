fi = 99999999999999
se = 999999999999999

tmp = [];

for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    tmp.append([name,score])
    if score < fi:
        se,fi = fi,score
    elif score > fi and score < se:
        se = score
        
tmp.sort();

for a in tmp:
    if a[1] == se:
        print a[0]
        
