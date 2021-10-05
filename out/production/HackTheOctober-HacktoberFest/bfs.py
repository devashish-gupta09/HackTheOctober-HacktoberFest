import matplotlib.pyplot as plt
import networkx as nx
import time

'''
This program takes edge list as input and performs Breadth First Search
It plots the graph and also show setp by step traversal of each node
Coder:  Ravi Verma
Contact: ravivermaj488@gmail.com
'''
class Graph:
    def __init__(self):
        self.graph = []
        
    def addEdge(self,v1,v2):
        self.graph.append([v1,v2])
        self.graph.append([v2,v1])
        self.graph.sort()

    def __str__(self):
        s = "\nGraph"
        for edge in self.graph:
           s += "\nedge ({},{})".format(edge[0],edge[1])
        return s

    def bfs(self,root):
        visited = [root]
        queue = [root]
        print("Breadth First Traversal")
        plt.ion()
        G = nx.Graph()
        G.add_edges_from(self.graph)
        nx.draw_planar(G,with_labels = True,arrows=True,node_size=3000,font_size=30,font_color="yellow",width=5)
        plt.show()
        plt.pause(10)
        plt.clf()

        G = nx.Graph()

        while(queue):
            vertex = queue.pop(0)
            print(vertex)
            for edge in self.graph:
                if(edge[0]==vertex and edge[1] not in visited):
                    queue.append(edge[1])
                    visited.append(edge[1])
                    G.add_edge(edge[0],edge[1])
                    nx.draw_planar(G,with_labels = True,arrows=True,node_size=3000,font_size=30,font_color="yellow",width=5)
                    plt.show()
                    plt.pause(3)
                    plt.clf()
        nx.draw_planar(G,with_labels = True,arrows=True,node_size=3000,font_size=30,font_color="yellow",width=5)
        plt.show()
        plt.pause(30)

    def __getitem__(self,key):
        return self.graph[key];


if __name__ == '__main__':
    N=0
    print("Enter the number of edges")
    N=int(input())
    G = Graph()
    for i in range(0,N):
        print("Enter the edge")
        print("vertex 1")
        v1 = int(input())
        print("vertex 2")
        v2 = int(input())
        G.addEdge(v1,v2)
    
    print('Enter the starting vertex')
    R = int(input())
    G.bfs(R)