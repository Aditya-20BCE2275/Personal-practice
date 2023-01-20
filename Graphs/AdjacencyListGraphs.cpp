#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "the edges are " << i << " -> ";
        for (auto y : adj[i])
        {
            cout << y << " -> ";
        }
        cout << " END " << endl;
    }
}


int main()
{
    int V = 4;
    vector<int> graph[V];
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    printGraph(graph, V);
    return 0;
}