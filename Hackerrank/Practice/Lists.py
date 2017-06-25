if __name__ == '__main__':
    N = int(raw_input())
    a = [];
    while N > 0:
        s = raw_input().split(' ')
        if s[0] == "insert":
            (i,v) = (int(s[1]),int(s[2]))
            a.insert(i,v)
        elif s[0] == "remove":
            v = int(s[1])
            if a.count(v):
                a.remove(v)
        elif s[0] == "append":
            v = int(s[1])
            a.append(v)
        elif s[0] == "sort":
            a.sort()
        elif s[0] == "reverse":
            a.reverse()
        elif s[0] == "pop":
            a.pop()
        elif s[0] == "print":
            print str(a)
        N-=1;