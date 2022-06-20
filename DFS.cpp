#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> &StoreDfs, vector<int> adj[])
{
    StoreDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, StoreDfs, adj);
        }
    }
}

vector<int> DfsofGraph(int v, vector<int> adj[])
{
    vector<int> StoreDfs;
    vector<int> vis(v, 0);
    for (int i = 1; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, StoreDfs, adj);
        }
    }
    return StoreDfs;
}

int main()
{
    int v = 5;
    v++;
    vector<int> adj[v];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    vector<int> ans;
    ans = DfsofGraph(v, adj);
    for (int i = 0; i < 5; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}