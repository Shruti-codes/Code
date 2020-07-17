from collections import Counter

class Solution:
    def topKFrequent(self, nums, k):
        
        res = []
        co = Counter(nums)
        for x, count in co.most_common(k):
            res.append(x)
            
        return res



print(Solution.topKFrequent(Solution, [1,1,1,2,2,2,3,3,3], 3))