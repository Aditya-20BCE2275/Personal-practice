#include<iostream>
#include<climits>
using namespace std;
//function to find difference between max and min element
int diffMaxMiniter(int arr[],int n)
{
    //setting intial values to arr[0]
    int max = arr[0];
    int min = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return max-min;  
}
using namespace std;
int main()
{
    int arr[] = {92,8,48,10,42,74,90,67,39,26};
    //finds size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = diffMaxMiniter(arr,n);
    //int max = INT_MIN, min = INT_MIN;
   // MinMaxDaC(arr,0,n-1,min,max);
    cout<<"The difference between max and min values in array is "<<diff<<endl;
    //cout<<"The prod between max and min values in the array is "<<prod<<endl;
    return 0;
}