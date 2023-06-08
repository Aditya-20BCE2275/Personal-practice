#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Kadane's Algo
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int m = INT_MIN;
    int i = 0;
    int sum = 0;
    while (i < 9)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            i++;
            continue;
        }
        m = max(m, sum);
        i++;
    }
    cout << m << endl;
    return 0;
}