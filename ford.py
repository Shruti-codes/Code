class Edge(object):
    def __init__(self, u, v, w):
        self.source = u
        self.sink = v
        self.capacity = w

class FlowNetwork(object):
    def __init__(self):
        self.adj = {}
        self.flow = {}
    
    def add_vertex(self, vertex):
        self.adj[vertex] = []
    
    def get_edges(self, v):
        return self.adj[v]

    def add_edge(self, u, v, w=0):
        if u == v:
            print("error")
        edge = Edge(u,v,w)
        redge = Edge(v,u,0)
        edge.redge = redge #redge is not defined in Edge class
        redge.redge = edge
        self.adj[u].append(edge)
        self.adj[v].append(redge)
        self.flow[edge] = 0
        self.flow[redge] = 0
    
    def find_path(self, source, sink, path, path_set):
        if source == sink:
            return path
        for edge in self.get_edges(source):
            residual = edge.capacity - self.flow[edge]
            if residual > 0 and not (edge,residual) in path_set:
                path_set.add((edge, residual))
                result = self.find_path( edge.sink, sink, path +[(edge,residual)], path_set)
                if result != None:
                    return result

    def max_flow(self, source, sink):
        path = self.find_path(source, sink, [], set())
        while path != None:
            flow = min(res for edge,res in path)
            for edge,res in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink, [], set())
        return sum(self.flow[edge] for edge in self.get_edges(source))


g = FlowNetwork()
[g.add_vertex(v) for v in "sabcdeft"]
g.add_edge('s','a',3)
g.add_edge('s','c',5)
g.add_edge('s','e',2)
g.add_edge('a','b',2)
g.add_edge('a','t',4)
g.add_edge('b','t',3)
g.add_edge('b','d',2)
g.add_edge('c','e',3)
g.add_edge('c','d',4)
g.add_edge('e','f',4)
g.add_edge('f','d',2)
g.add_edge('f','t',3)
print g.max_flow('s','t')