def average(array):
    # your code goes here
    list = set()
    ans = 0
    for x in array:
        if x not in list:
            ans += x
        list.add(x)
    return ans/len(list)