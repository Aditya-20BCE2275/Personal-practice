#include <iostream>
using namespace std;
// Minimum element is placed at the start through swaps
void SelectionSort(int arr[], int n)
{
    // int mini = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3, 1, 5, 2, 7, 8, 9, 22, 65, 2, 2, 2, 2};
    SelectionSort(arr, 13);
    return 0;
}