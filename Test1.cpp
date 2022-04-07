#include <iostream>
#include <climits>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    // int start = 0;+
    long long sum = 0;
    long long max1 = INT_MIN;
    int i = 0;
    while (i < n)
    {
        sum = sum + arr[i];
        if (max1 < sum)
        {
            max1 = max(sum, max1);
        }

        if (sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    return max1;
}

int main()
{
    int arr[] = {12,3,2,-23,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr,n)<<endl;
    return 0;
}