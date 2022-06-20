#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Display(int v, vector<int> adj[])
{
    for (int i = 1; i < v; i++)
    {
        cout << i << " =>> ";
        for (auto x : adj[i])
        {
            cout << "->" << x;
        }
        cout << endl;
    }
}

vector<int> bfs(vector<int> adj[], int v)
{
    vector<int> bfs;
    vector<int> vis(v, 0);

    for (int i = 1; i < v; i++)
    {
        if (!vis[i])
        {
            queue<int> q1;
            q1.push(i);
            vis[i] = 1;
            while (!q1.empty())
            {
                int node = q1.front();
                q1.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q1.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{
    int v;
    cin >> v;
    v++;
    vector<int> adj[v];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 5, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 6);
    Display(7, adj);
    vector<int> v1;
    v1 = bfs(adj, v);
    vector<int> :: iterator it;
    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}