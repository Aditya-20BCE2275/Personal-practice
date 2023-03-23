#include <bits/stdc++.h>
using namespace std;

void sumk(int idx, int n, int arr[], vector<int> &ans, int s, int k)
{
    if (idx == n)
    {
        if (s == k)
        {
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // not take
    sumk(idx + 1, n, arr, ans, s, k);

    // take
    ans.push_back(arr[idx]);
    s += arr[idx];
    sumk(idx + 1, n, arr, ans, s, k);
    ans.pop_back();
    s -= arr[idx];
}

int main()
{
    int arr[] = {1, 2, 1};
    vector<int> ans;
    int n = 3;
    sumk(0, n, arr, ans, 0, 2);
    return 0;
}