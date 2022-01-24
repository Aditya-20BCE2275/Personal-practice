#include <iostream>
using namespace std;

bool issafe(int **arr, int x, int y, int n)
{
    // if(x>=n && y>=n){
    //     return true;
    // }
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    int r = x, c = y;
    while (r >= 0 && c >= 0)
    {
        if (arr[r][c] == 1)
        {
            return false;
        }
        r--;
        c--;
    }

    r = x;
    c = y;
    while (r >= 0 && c >= 0)
    {
        if (arr[r][c] == 1)
        {
            return false;
        }
        r--;
        c++;
    }
    return true;
}

bool nqueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (issafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nqueen(arr, x + 1, n))
            {
                return true;
            }
            arr[x][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if (nqueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}