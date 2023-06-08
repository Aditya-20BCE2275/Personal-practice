#include <bits/stdc++.h>
using namespace std;

void ans(int &max, int i, int j, int steps, int st, int bad)
{
    if (i == bad)
        return;
    if (st == steps)
    {
        if (i > max)
        {
            max = i;
        }
        return;
    }

    ans(max,i+j,j+1,steps,st+1,bad);
    ans(max,i,j+1,steps,st+1,bad);
}
int main()
{
    int max = INT_MIN;
    int steps = 2;
    int bad = 1;
    int st = 0;
    ans(max, 0, 1, steps, st, bad);
    cout<<max;
    return 0;
}