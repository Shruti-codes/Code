
import sys

tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
n=2
f = [0]*26
m = -sys.maxsize - 1

for i in range(len(tasks)):
	f[ ord(tasks[i]) - ord('A')] += 1

for i in range(len(f)):
	m = max(m, f[i])

m -= 1
s = m*n + m
for i in range(len(f)):
	s -= min(f[i], m)

if(s>0):
	print(len(tasks)+s)
else:
	print(len(tasks))



