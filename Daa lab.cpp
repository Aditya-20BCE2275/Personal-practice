#include<iostream>
#include<climits>
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
int MinMaxDaC(int arr[], int l, int h, int &min, int &max){
    //if low == high
    if (l == h){
        if (max < arr[l]) {
            max = arr[l];
        }
        if (min > arr[h]) {
            min = arr[h];
        }
        return;
    }
    
    if (h - l == 1){
        if (arr[l] < arr[h]){
            if (min > arr[l]){
                min = arr[l];
            }
            
            if (max < arr[h]) {
                max = arr[h];
            }
        }
        else {
            if (min > arr[h]) {
                min = arr[h];
            }
            
            if (max < arr[l]) {
                max = arr[l];
            }
        }
        return;
    }
    //finding dividing point
    int mid = (l + h) / 2;
    MinMaxDaC(arr, l, mid, min, max);
    MinMaxDaC(arr, mid + 1, h, min, max);
    return max*min;
}

using namespace std;
int main()
{
    int arr[] = {92,8,48,10,42,74,90,67,39,26};
    //finds size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = diffMaxMiniter(arr,n);
    int max = INT_MIN, min = INT_MIN;
    int prodMaxMin = MinMaxDaC(arr,0,n-1,min,max);
    cout<<"The difference between max and min values in array is "<<diff<<endl;
    cout<<"The prod between max and min values in the array is "<<prodMaxMin<<endl;
    return 0;
}