from collections import defaultdict

class Graph:
    
    def __init__(self,vertices):
        self.V= vertices 
        self.graph = [] 
    
    def add(self,u,v,w):
        self.graph.append([u, v, w])
    
    def printd(self, dist):
        print("Vertex   Distance from Source")
        for i in range(self.V):
            print("%d \t\t %d" % (i, dist[i]))
    
    def BellmanFord(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0
        for i in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
        for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                        print ("Graph contains negative weight cycle")
                        return
        self.printdx(dist)

 print("Graph with negative weighted edge")

g = Graph(5)
g.add(0, 1, 6)
g.add(0, 2, 7)
g.add(1, 2, 8)
g.add(1, 4, 5)
g.add(1, 3, -4)
g.add(2, 4, -3)
g.add(3, 0, 2)
g.add(3, 4, 7)
g.add(4, 1, -2)
g.add(2, 3, 9)
g.BellmanFord(0)