def count_substring(string, sub_string):
    ans = 0
    for i in range(0,len(string)-len(sub_string)+1):
        if(string[i:len(sub_string)+i] == sub_string):
            ans += 1
    return ans