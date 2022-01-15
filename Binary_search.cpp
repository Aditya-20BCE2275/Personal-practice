#include<iostream>
using namespace std;
// Binary search 
// elements should be pressent in sorted order 
// we compare the mid element of the array. if the array element is > key then we search the 1st half. And if the element < key -> 2nd half. And repeat the process.
// complexity = O(log n (base 2))
int Bsearch(int arr[],int n, int key)
{
    int s=0,e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int i,n;
    cout<<"enter the number of the elements u wanna enter"<<endl;
    cin>>n;
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the key u wanna find"<<endl;
    int key;
    cin>>key;
    cout<<Bsearch(arr,n,key);
    return 0;
}