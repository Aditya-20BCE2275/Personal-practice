#include <bits/stdc++.h>
using namespace std;

void Subs(int idx, int arr[], vector<int> &ans, int n)
{
    if (n == idx)
    {
        if (ans.size() == 0)
        {
            cout << "{}" << endl;
            return;
        }
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // Not taking anything
    Subs(idx + 1, arr, ans, n);

    // Taking the element at that position
    ans.push_back(arr[idx]);
    Subs(idx + 1, arr, ans, n);
    ans.pop_back();
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ans;
    Subs(0, arr, ans, n);
    return 0;
}