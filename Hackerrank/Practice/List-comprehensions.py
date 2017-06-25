if __name__ == '__main__':
    x = int(raw_input())
    y = int(raw_input())
    z = int(raw_input())
    n = int(raw_input())
    
    k = [[t1,t2,t3] for t1 in range(0,x+1) for t2 in range(0,y+1) for t3 in range(0,z+1) if t1 + t2 + t3 != n]
    
    print k