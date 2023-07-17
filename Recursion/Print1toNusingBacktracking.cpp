#include<iostream>
using namespace std;

void printBack(int n)
{
    if(n == 0)
    {
        return;
    }
    // n--;
    printBack(n-1);
    cout<<n<<endl;
}

int main()
{
    printBack(5);
    return 0;
}