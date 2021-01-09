#ifndef DFS_H
#define DFS_H

#include<iostream>
#include<list>

class Graph{
	int V;
	std::list<int>* adj;
public:
	//Graph();
	Graph(int no_of_vertices);
	void addEdge(int v, int w);
	bool DFS(int s);
	void DFSUtil(int v, bool visited[]);
};

#endif
