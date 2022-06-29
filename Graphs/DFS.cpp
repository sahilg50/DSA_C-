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
    void DFS(int s);            // Method to print BFS traversal starting from node s.
    void deleteGraph();         // delete the graph and release the memory
    vector<bool> visited;       // Array to keep check of the visited nodes
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

void Graph::DFS(int s)
{
    cout << s << " ";
    visited[s] = true;

    for (auto it : adj[s])
    {
        if (!visited[it])
        {
            this->DFS(it);
        }
    }
}

void Graph::deleteGraph()
{
    delete[] this->adj;
}

int main()
{
    cout << endl
         << "Enter the total number of nodes and edges: ";
    int N, M;
    cin >> N >> M;
    Graph g(N);

    for (int i = 0; i < M; i++)
    {
        cout << endl
             << "Enter the edge: ";
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << endl
         << "Enter the starting node for dfs: ";
    int start;
    cin >> start;
    cout << "Following is the Depth First Traversal: ";
    g.DFS(start);

    g.deleteGraph();

    return 0;
}

/*
TC-> O(V + 2*E) -> Exact
SC-> O(V)
where V, E is the total number of vertices and edges respectively
*/