from collections import defaultdict

graph = defaultdict(list)
visited = [False]*9

def edge(graph,u,v):
    graph[u].append(v)
    graph[v].append(u)


def bfs(s):
	queue = []
	queue.append(s)
	visited[s] = True

	while(queue):
		s = queue.pop(0)
		print(s)

		for i in graph[s]:
			if(visited[i]==False):
				queue.append(i)
				visited[i]=True


edge(graph,0,1)
edge(graph,1,2)
edge(graph,2,3)
edge(graph,3,4)
edge(graph,3,5)
edge(graph,4,5)
edge(graph,4,6)
edge(graph,5,3)
edge(graph,5,4)
edge(graph,5,7)
edge(graph,6,4)
edge(graph,6,7)
edge(graph,7,6)
edge(graph,7,5)








bfs(2)
