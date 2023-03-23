#include <bits/stdc++.h>
using namespace std;

// find the number contigous or non contiguos subseqence with sum = k
int sumK(int idx, int arr[], int n, int sum, int k)
{
    if (n == idx)
    {
        if (sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // not pick
    int l = sumK(idx + 1, arr, n, sum, k);

    // take
    sum += arr[idx];
    int r = sumK(idx + 1, arr, n, sum, k);
    sum -= arr[idx];
    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int k = 2;
    int sum = 0;
    cout << sumK(0, arr, n, sum, k);
    return 0;
}