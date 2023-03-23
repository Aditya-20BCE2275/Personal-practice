#include<bits/stdc++.h>
using namespace std;

// using 2 pointers
void swapa(int arr[],int l,int r)
{
    if(l >= r){
        return;
    }
    swap(arr[l],arr[r]);
    swapa(arr,l+1,r-1);
}

// uisng 2 pointers with a single pointers initialized
void swaparr(int arr[],int i,int n)
{
    if(i == n/2)
    {
        return;
    }   
    swap(arr[i],arr[n-1-i]);
    swaparr(arr,i+1,n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,9};
    int n = 7;
    swapa(arr,0,n-1);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    reverse(arr,arr+7);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    swaparr(arr,0,n);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
    return 0;
}