import re
import string

class Solution:
    def isPalindrome(self, s):
        
        s = s.lower()
        s = s.replace(" ", "")
        punc = list(string.punctuation)
        s = "".join([i for i in s if i not in punc])
        
        print(s)
        l = len(s)
        print(l)
        if(l==0 or l==1):
            return True
        
        if(l%2==0):
            m = l//2 - 1
        else:
            m = l//2
        
        for i in range(m+1):
            if(s[i]!=s[l-i-1]):
                return False
        
        return True
        
        
print(Solution.isPalindrome(Solution,"A man, a plan, a canal: Panama"))