#include<iostream>
using namespace std;
void fact(int n)
{
    int prod=1;
    for(int i=n;i>0;i--)
    {
        prod=prod*i;
    }
    cout<<prod<<endl;
}
int main()
{
    int n;
    cout<<"enter the number of which factorial is found"<<endl;
    cin>>n;
    fact(n);
    return 0;
}