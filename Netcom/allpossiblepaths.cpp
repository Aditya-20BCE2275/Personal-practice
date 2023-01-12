#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void path(int src, int tar, vector<int> adj[], vector<int> &temp, vector<vector<int>> &ans)
{
    temp.push_back(src);
    if (src == tar)
    {
        ans.push_back(temp);
        return;
    }
    for (auto it : adj[src])
    {
        path(it, tar, adj, temp, ans);
        temp.pop_back();
    }
}
int main()
{
    int num;
    cin >> num;
    unordered_map<int, int> umap;
    int g;
    for (int i = 0; i < num; i++)
    {
        cin >> g;
        umap[g] = i;
    }
    vector<int> arr2[num];
    int c, d;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> c >> d;
        addEdge(arr2, umap[c], umap[d]);
    }
    int a, b;
    cin >> a >> b;
    vector<vector<int>> ans;
    vector<int> temp;
    path(umap[b], umap[a], arr2, temp, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][1] << " ";
    }
    return 0;
}