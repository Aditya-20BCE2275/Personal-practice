#include <iostream>
using namespace std;

// Try recording breaking day 

// Taking maximum of ith element and elements before it
int Max(int a[], int n)
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
        cout << mx << endl;
    }
}

// This function takes sums of all the subarrays
int SumSubarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + a[j];
        }
        cout << sum<<"\t"<<endl;
    }
}

// Longest arithematic subarray
int Arith(int a[],int n)
{
    int ans=2;
    int pd=a[1]-a[0];
    int j=2;
    int curr=2;
    while (j<n)
    {
        if(pd == a[j]-a[j-1])
        {
            curr++;
        }
        else
        {
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans = max(ans,curr);
        j++;
    }
    cout<<ans<<endl;
}

// Record breakers
  

int main()
{
    int n;
    cin >> n;
    cout << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    cout<<endl;
    Max(a, n);
    SumSubarr(a, n);
    Arith(a,n);
    return 0;
}