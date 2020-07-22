#lapindrome

T = int(input())

while(T!=0):
	s = input()
	l = len(s)
	flag = 0
	T -= 1
	

	alpha = [0]*26
	i=0
	j=l-1

	while(i<j):
		alpha[ord(s[i]) - 97] += 1
		alpha[ord(s[j]) - 97] -= 1
		i += 1
		j -= 1


	for i in range(0,26):
		if(alpha[i]!=0):
			flag = 1
			break

	if(flag==0):
		print("YES")
	else:
		print("NO")
