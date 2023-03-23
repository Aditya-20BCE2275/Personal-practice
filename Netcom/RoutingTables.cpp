#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "we address 1000 as infinity or no direct connection" << endl;
    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    int tab[n][n];
    int tabr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter the values of distances from node number " << i + 1 << " to " << j + 1 << endl;
            cin >> tab[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tabr[i][j] = 0;
        }
    }
    cout << "The non modified routing table is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tab[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
    cout << "The modified table is " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k != j)
                {
                    if (tab[i][j] > (tab[i][k] + tab[k][j]))
                    {
                        tabr[i][j] = k;
                        tab[i][j] = (tab[i][k] + tab[k][j]);
                    }
                }
            }
        }
        // cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tab[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
    cout<<"The nodes table which took alternate routes are : "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tabr[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
    return 0;
}