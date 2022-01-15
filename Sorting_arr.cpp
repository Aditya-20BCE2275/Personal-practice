#include<iostream>
using namespace std;

// We are using selection sort so we will run 2 loops from 1st element to the 2nd-last and then 2nd element to the last
int SelecSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int temp = a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}

int main()
{
    int n;
    cout<<"enter the number of elements u wanna enter"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    SelecSort(a,n);
    return 0;
}