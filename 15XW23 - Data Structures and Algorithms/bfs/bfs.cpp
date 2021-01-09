#include"bfs.h"

Graph::Graph(int V){
	this->V 		= V;
	this->adj		= new std::list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

bool Graph::BFS(int s){
	bool *visited 	= new bool[this->V];
	for(int i = 0 ; i<this->V ; i++)
		visited[i] = false;

	std::list<int> queue;
	visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    std::list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
	return true;
}
int main(){
	Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);

   std::cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
   g.BFS(2);

   return 0;
}
