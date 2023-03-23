#include<bits/stdc++.h>
using namespace std;
// sum of n natural numbers
// usnig parameterized

void f(int n,int s)
{
    if(n == 1)
    {
        cout<< 1 + s;
        return;
    }
    f(n-1,s+n);
}

int main()
{
    f(4,0);
    return 0;
}