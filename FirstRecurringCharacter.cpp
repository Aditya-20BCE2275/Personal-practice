#include<bits/stdc++.h>
using namespace std;

int FirstRecurringElement(int arr[],int n)
{
    unordered_map<int,int>ump;
    for(int i=0;i<n;i++)
    {
        ump[arr[i]]++;
        if(ump[arr[i]] == 2)
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int a[] = {2,3,4,5};
    cout<<"The first recurring element is "<<FirstRecurringElement(a,4)<<endl;
    return 0;
}