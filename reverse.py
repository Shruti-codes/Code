n=0b00000010100101000001111010011100
res = 0
for i in range(32):
	res = res<<1
	res = (n & 1) | res
	n = n>>1
	

print(res)
