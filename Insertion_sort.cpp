#include <iostream>
using namespace std;

// Insertion Sort
// In this sort we pick the current element and place it in its right position by shifiting all the numbers at its correct postion and after that position forward by 1 element position.
int main()
{
    int n;
    cout << "enter the number of elements to be entered " << endl;
    cin >> n;
    int a[n];
    for ( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // The sort starts from the second element because it comapares elements before its position in the array
    for (int i = 1; i < n; i++)
    {
        // A integer to compare all the elements before our current element to dertermine its correct location
        int current = a[i];
        // j to loop back to the elements before current element
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        // At the final iteration suppose the current's correct position stands to be a[0] then in while loop the variable j would end with a value j=-1; Thats why we make a[j+1] as current same applies to all other iteration and correct values of j.
        a[j + 1] = current;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    return 0;
}