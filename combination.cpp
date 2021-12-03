#include<iostream>
using namespace std;
int fact(int n)
{
    int prod=1;
    for(int i=n;i>0;i--)
    {
        prod=prod*i;
    }
    //cout<<prod<<endl;
    return prod;
}
void comb(int n,int r)
{
    //comb = n!/(r!*(n-r)!)
    int comb=(fact(n)/(fact(r)*fact(n-r)));
    cout<<"the combination is "<<comb;
}
int main()
{
    int n,r;
    //cout<<"enter the number of which factorial is found"<<endl;
    cin>>n;
    cin>>r;
    //fact(n);
    comb(n,r);
    return 0;
}