#ifndef BFS_H
#define BFS_H

#include<iostream>
#include<list>

class Graph{
	int V;
	std::list<int>* adj;
public:
	//Graph();
	Graph(int no_of_vertices);
	void addEdge(int v, int w);
	bool BFS(int s);
};

#endif
