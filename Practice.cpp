#include <bits/stdc++.h>
using namespace std;

bool sumK(int idx, int arr[], vector<int> &ans, int n, int sum, int k)
{
    if (n == idx)
    {
        if (sum == k)
        {
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        else
        return false;
    }

    // not pick
    if (sumK(idx + 1, arr, ans, n, sum, k) == true)
    {
        return true;
    }

    // pick
    ans.push_back(arr[idx]);
    sum += arr[idx];
    if (sumK(idx + 1, arr, ans, n, sum, k) == true)
    {
        return true;
    }
    // remove after
    ans.pop_back();
    sum -= arr[idx];
    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int k = 2;
    vector<int> ans;
    int sum = 0;
    sumK(0, arr, ans, n, sum, k);
    return 0;
}