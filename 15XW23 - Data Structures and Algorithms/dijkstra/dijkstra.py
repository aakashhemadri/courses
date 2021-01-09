#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Wed Jan  9 10:51:06 2019

@author: Aakash Hemadri
"""
import sys
import numpy

class dijkstra:
    """Dijkstra's algorithm"""
    def __init__(self, data=[numpy.zeros((2,2),numpy.int8),1,1,'A']):
        self.graph = data[0]
        self.n_vertices = data[1]
        self.n_edges = data[2]
        self.source = data[3]
        self.dist = [sys.maxsize] * self.n_vertices
        self.dist[ 65 - ord(self.source)] = 0
        self.spanning_tree = [False] * self.n_vertices
        #Auto assign each vertice as an incremental Alphabet
        self.vertices = []
        for iter in range(self.n_vertices):
            self.vertices.append(chr(65+iter))     
    def min_distance(self):
        min = sys.maxsize
        min_index = 0
        for vertex in range(self.n_vertices):
            if(self.dist[vertex] < min and self.spanning_tree[vertex] == False):
                min = self.dist[vertex]
                min_index = vertex
        return min_index
    def algorithm(self):
        for iterator in range(self.n_vertices):
            u = self.min_distance()
            self.spanning_tree[u] = True
            for v in range(self.n_vertices):
                if self.graph[u][v] > 0 and self.spanning_tree[v] == False and self.dist[v] > self.dist[u] + self.graph[u][v]:
                    self.dist[v] = self.dist[u] + self.graph[u][v]
    def print_dist(self):
        """Print's distance from Source"""
        print("[Vertex]\t-\t[Distance from Source]")
        for iterator in range(self.n_vertices):
            print(self.vertices[iterator],"\t\t-\t\t",self.dist[iterator])
    def print_member(self):
        """Print function"""
        print(self.graph)
        print(self.n_vertices)
        print(self.n_edges)
        print(self.source)
        print(self.vertices)
def test():
    pass

if __name__ == "__main__":
    test()