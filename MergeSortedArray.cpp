#include <iostream>
#include <vector>
using namespace std;

// Merge 2 sorted Arrays
// {2,4,6,9} {1,7,10}

int *MergeSortedArrays(int *arr1, int *arr2, int n, int m)
{
    int cnt = 0, j = 0, k = 0;
    if (n == 0)
    {
        return arr2;
    }

    if (m == 0)
    {
        return arr1;
    }

    int *arr = new int[n + m];
    while (j < n || k < m)
    {
        if (arr1[j] < arr2[k])
        {
            arr[cnt] = arr1[j];
            j++;
            cnt++;
        }
        else
        {
            arr[cnt] = arr2[k];
            k++;
            cnt++;
        }
    }
    return arr;
}

int main()
{
    int arr1[] = {23,54,66};
    int arr2[] = {1, 7, 10};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int *newArray = MergeSortedArrays(arr1,arr2, n, m);
    for (int i=0;i<n+m;i++)
    {
        cout << newArray[i] << " ";
    }
    return 0;
}