from collections import defaultdict

graph = defaultdict(list)
l =[0]*20
f =[0]*20
color = ["white"]*20
parent = [float("inf")]*20
low = [float("inf")]*20
time = 0
root = 5
Art = []
path = []

def edge(graph,u,v):
    graph[u].append(v)


def dfs(v):
	for u in graph[v]:
		if(color[u]=="white"):
			dfs_visit(u)


def dfs_visit(u):
	global time
	time = time + 1
	nchild =0
	color[u] = "gray"
	l[u] = time
	path.append(u)

	for i in graph[u]:
		if(color[i]=="gray" and parent[i]!=u):
			print("cycle exists")

		if(color[i]=="white"):
			nchild = nchild +1
			parent[i] = u
			dfs_visit(i)
			low[u] = min(low[u], low[i])
			if(nchild>1 and parent[u] == -1 ):
				Art.append(u)
			elif (parent[u] != -1 and low[i] >= l[u]):
				Art.append(u)
		elif(i!=parent[u]):
			low[u] = min(low[u], l[i])

	color[u] = "black"
	time = time +1
	f[u]=time
	return nchild


edge(graph,1,2)
edge(graph,1,3)
edge(graph,2,5)
edge(graph,4,8)
edge(graph,2,3)
edge(graph,2,6)
edge(graph,3,6)
edge(graph,5,6)
edge(graph,1,4)
edge(graph,4,7)
edge(graph,7,8)

dfs(1)

print("Articulation point")
print(Art)

print("dfs")
print(path)