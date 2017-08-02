if __name__ == '__main__':
    s = input()
    s = ''.join(e for e in s if e.isalnum())
    print(len(s) > 0)
    print(len(s) > 0 and not s.isdigit())
    print(len(s) > 0 and not s.isalpha())
    print(len(s) > 0 and (not s.isdigit()) and not s.isupper())
    print(len(s) > 0 and (not s.isdigit()) and not s.islower())
    
"""
In the first line, print True if  has any alphanumeric characters. Otherwise, print False. 
In the second line, print True if  has any alphabetical characters. Otherwise, print False. 
In the third line, print True if  has any digits. Otherwise, print False. 
In the fourth line, print True if  has any lowercase characters. Otherwise, print False. 
In the fifth line, print True if  has any uppercase characters. Otherwise, print False.
"""