#include<bits/stdc++.h>
using namespace std;

void sumofN(int sum, int n)
{

    if (n == 0)
    {
        cout << sum;
        return;
    }
    sumofN(sum + n, n - 1);
}

int main()
{
    int n;
    cin >> n;
    sumofN(0, n);
    return 0;
}