#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

#define INF INT_MAX

// Edge structure
struct Edge
{
    int dest;
    int weight;
};

// Node structure
struct Node
{
    int id;
    int distance;
    int prev;
    vector<Edge> edges;
};

// Graph class
class Graph
{
private:
    vector<Node> nodes;
    int numNodes;

public:
    Graph(int n)
    {
        numNodes = n;
        nodes.resize(numNodes);
        for (int i = 0; i < numNodes; i++)
        {
            nodes[i].id = i;
            nodes[i].distance = INF;
            nodes[i].prev = -1;
        }
    }

    // Add an undirected edge
    void addEdge(int u, int v, int w)
    {
        Edge e1 = {v, w};
        nodes[u].edges.push_back(e1);
        Edge e2 = {u, w};
        nodes[v].edges.push_back(e2);
    }

    // Dijkstra's algorithm to find shortest path
    void dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        nodes[src].distance = 0;
        pq.push(make_pair(0, src));
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto &e : nodes[u].edges)
            {
                int v = e.dest;
                int w = e.weight;
                if (nodes[v].distance > nodes[u].distance + w)
                {
                    nodes[v].distance = nodes[u].distance + w;
                    nodes[v].prev = u;
                    pq.push(make_pair(nodes[v].distance, v));
                }
            }
        }
    }

    // Print the routing table for a node
    void printRoutingTable(int nodeID)
    {
        cout << "Routing table for node " << nodeID << ":" << endl;
        cout << "Dest\tNext Hop\tDist" << endl;
        for (int i = 0; i < numNodes; i++)
        {
            if (i != nodeID)
            {
                cout << i << "\t" << nodes[i].prev << "\t\t" << nodes[i].distance << endl;
            }
        }
    }
};

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;
    Graph g(n);
    cout << "Enter the edges and weights:" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int src;
    cout << "Enter the source node: ";
    cin >> src;
    g.dijkstra(src);
    for (int i = 0; i < n; i++)
    {
        g.printRoutingTable(i);
    }
    return 0;
}