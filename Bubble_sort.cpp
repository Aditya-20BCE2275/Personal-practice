#include <iostream>
using namespace std;

//Bubble sort: Repeatedly sort two adjacent elements in ascending order
int Bubble(int a[], int n)
{
    int i;
    // int count = 1;
    // we have to check till n-1 elements as the last element remaining would be already sorted with other swap operations
    for (i = 0; i < n - 1; i++)
    {
        // here we do n-1-i because we need to check a[i+1]th element also so if we take case of 2nd iteration the last unsorted element to check would be n-2th element because we are gonna check the n+1 th element for swapping anyways.
        for (int j = 0; j < n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    int n;
    cout << "enter the number of elements u wanna enter" << endl;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Bubble(a,n);
    return 0;
}