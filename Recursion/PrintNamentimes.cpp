#include <iostream>
using namespace std;

void name(int i,int n)
{
    if (i > n)
        return;
    cout<<"Aditya"<<endl;
    i++;
    name(i,n);
}

int main()
{
    int n;
    cin >> n;
    name(1,n);
    return 0;
}