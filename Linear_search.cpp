#include <iostream>
using namespace std;

int main()
{
    cout << "enter the number values for linear search" << endl;
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the number u wanna find" << endl;
    cin >> key;
    int flag =0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            flag=1;
            cout << i;
        }
    }
    if(flag==0)
    {
        cout<<"Key not found"<<endl;
    }
    return 0;
}