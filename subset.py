import math
class Solution:
    def subsets(self, nums):
        n = len(nums)
        ps = 2**n
        res = []
        co = 0
        sub = []
        
        for co in range(ps):
            sub = []
            for i in range(n):
                if((co & 1 << i) > 0):
                    sub.append(nums[i])
                    
            res.append(sub)
                      
        return res
        
        

print(Solution.subsets(Solution, [1,2,3]))