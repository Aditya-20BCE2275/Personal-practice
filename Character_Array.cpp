#include <iostream>
using namespace std;

int main()
{
    // Strings in character array end with a null character="\0";
    // this is just to cout whole array with while loop which ends with null character
    char arr[100] = "apple";
    int i=0;
    while (arr[i] != '\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }

    //  Check palindrome in (char array / words
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;
    bool check = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=a[n-2-i])
        {
            cout<<a[i]<<a[n-1-i];
            check = 0;
            break;
        }        
    }
    if (check == 1)
    {
        cout<<"word is a palindrome"<<endl;
    }
    else
    cout<<"word in not a palindrome"<<endl;
    
    return 0;
}