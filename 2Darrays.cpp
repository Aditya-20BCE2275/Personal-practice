#include <iostream>
using namespace std;
// 2D matrix
int main()
{
    int n, m;
    cin >> n >> m;
    cout << endl;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Searching in a 2D array
    int key;
    cout << "enter the key to be searched" << endl;
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == key)
            {
                cout << "element is found at " << i << " " << j << endl;
            }
        }
    }

    // Spiral order matrix travesal
        // int row_start = 0, column_start = 0, row_end = n - 1, column_end = m - 1;
        // while (row_start <= row_end && column_start <= column_end)
        // {
        //     for (int i = column_start; i < column_end; i++)
        //     {
        //         cout << a[row_start][i] << " ";
        //     }
        //     row_start++;

        //     for (int i = row_start; i <= row_end; i++)
        //     {
        //         cout<<a[i][column_end]<<" ";
        //     }
        //     column_end--;

        //     for (int i = column_end; i >= column_start; i++)
        //     {
        //         cout<<a[row_end][i]<<" ";
        //     }
        //     row_end--;

        //     for(int i=row_end;i>=row_start;i--)
        //     {
        //         cout<<a[i][column_start]<<" ";
        //     }
        //     column_start++;
            
        // }
    return 0;
}