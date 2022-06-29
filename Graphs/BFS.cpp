#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int n;
    vector<int> *adj;

public:
    Graph(int n);               // Constructor, n is the total number of verticesin graph.
    void addEdge(int u, int v); // Method to add undirected edge between u and v.
    void BFS(int s);            // Method to print BFS traversal starting from node s.
    void deleteGraph();         // delete the graph and release the memory
    vector<bool> visited;
};
Graph::Graph(int n)
{
    this->n = n;
    this->adj = new vector<int>[n];
    this->visited.resize(n, false);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(int s)
{

    queue<int> Q;
    visited[s] = true;
    Q.push(s);

    while (!Q.empty())
    {
        s = Q.front(), Q.pop();
        cout << s << " ";
        for (int it : adj[s])
        {
            if (!visited[it])
            {
                visited[it] = true;
                Q.push(it);
            }
        }
    }
}

void Graph::deleteGraph()
{
    delete[] this->adj;
}

int main()
{
    // Note that this code will only work for the connected graph. For the disconnectd graph, check out the number of connected components code.
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << "Following is the Breadth First Traversal ";
    g.BFS(2);

    return 0;
}

/*
TC-> O(V + 2*E) -> Exact
SC-> O(V)
where V, E is the total number of vertices and edges respectively
*/
