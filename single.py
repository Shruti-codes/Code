import sys
nums = [1403617094,-490450406,-1756388866,-967931676,1878401007,1878401007,-74743538,1403617094,-1756388866,-74743538,-490450406,-1895772685]
res = []
nums.append(sys.maxsize)
nums.sort()
# print(nums)
l = len(nums)
i=1
while(i<l):
    co=0
    while(nums[i] == nums[i-1]):
        co += 1
        i += 1
    if(co==0):
        res.append(nums[i-1])
    i += 1
            
print(res)