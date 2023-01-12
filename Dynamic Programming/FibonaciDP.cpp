#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main()
{
    int n;
    cout << "enter the number to be found fibo of" << endl;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << fibo(n, dp)<<endl;

    // This is solution made by Tabulation
    int prev2 = 0;
    int prev = 1;
    int cur;
    for(int i=2;i<=n;i++)
    {
        cur = prev+prev2;
        prev2 = prev;
        prev = cur;
    }
    cout<<"This is top down approach "<< prev<< endl;
    return 0;
}

// time complexity = o(n)
// space complexity = o(n) + o(n)(Array Space)
