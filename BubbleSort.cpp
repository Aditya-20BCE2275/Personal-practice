#include <iostream>
using namespace std;
// The largest element is Bubbled upto the end of the array
int BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {2, 4, 43, 6, 9, 1, 3, 4, 4, 4, 4};
    BubbleSort(a, 11);
    return 0;
}