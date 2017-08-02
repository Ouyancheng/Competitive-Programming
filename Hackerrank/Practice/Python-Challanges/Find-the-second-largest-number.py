if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    hi = -999999999
    lo = -999999999
    for x in range(0,n):
        if arr[x] > hi:
            lo = hi
            hi = arr[x]
        elif arr[x] < hi and arr[x] > lo:
            lo = arr[x]
    print lo
    
