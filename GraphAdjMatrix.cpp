#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of nodes and number of edges" << endl;
    int n, m;
    cin >> n >> m;
    int adjmat[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjmat[i][j] = 0;
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "enter the nodes which are connected" << endl;
        cin >> u >> v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}