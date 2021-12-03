#include<iostream>
using namespace std;
void fibo(int e)
{
    int fib[e+2];
    fib[0]=0;
    fib[1]=1;
    cout<<fib[0]<<endl<<fib[1]<<endl;
    for(int i=0;i<e;i++)
    {
        fib[i+2]=fib[i]+fib[i+1];
        cout<<fib[i+2]<<endl;
    }
}
int main()
{
    int num;
    cout<<"this shows the fibonacci series"<<endl;
    cin>>num;
    fibo(num);
    return 0;
}