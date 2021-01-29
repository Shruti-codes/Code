def all_pos(k,n):
    if((n==0 and k==0) or n<=0):
        return None
    elif k == 1 and n>0:
        return [[n]]
    all_ways = []
    for i in range(1,n+1):
        ret = all_pos(k-1,n-i)
        if ret is not None:
            for t in ret:
                all_ways.append([i]+t)
    return all_ways


print(all_pos(3,6))

