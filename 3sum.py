class Solution:
    def threeSum(self,nums):
        n = len(nums)
        res = []
        nums.sort()

        if(n<3):
            return []
        if(nums[0]==0 and nums[n-1]==0):
            return [[0,0,0]]
        
        for j in range(n-2):
            l=j+1    
            r=n-1
            while(l<r):
                sum = nums[j] + nums[l] + nums[r]
                if(sum == 0):
                    res.append((nums[j],nums[l],nums[r]))
                    l=l+1
                    r=r-1
                elif(0<sum):
                    r=r-1
                else:
                    l=l+1

        res = set(tuple(x) for x in res)            
        return res



obj = Solution()
nums = [-1, 0, 1, 2, -1, -4]
print(Solution.threeSum(obj,nums))