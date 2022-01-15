#include<iostream>
using namespace std;
int main()
{
    cout<<"ENter the no of elements wanted\n";
    int n,maxno=0;
    cin>>n; 
    int array[n];
    for(int i=0;i<n;i++)
    {
        maxno=max(maxno,array[i]);
        int minno=min(minno,array[i]);
        cin>>array[i];
    }
    cout<<"\n";
    
}