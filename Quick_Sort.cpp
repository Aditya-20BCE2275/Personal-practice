// quick sort
#include <iostream>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// this function performs the correct positioning of the pivot element to sort the array
int partition(int arr[], int l, int h)
{
    cout<<"entered partition"<<endl;
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, h);
    return i + 1;
}
// This is the main function to perform recursive call of sorting technique 
void quicksort(int arr[], int l, int h)
{
    cout<<"entered quicksort"<<endl;
    if (l < h)
    {
        int pi = partition(arr, l, h);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, h);
    }
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    quicksort(arr, 0, 4 /*(size of array)*/);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
