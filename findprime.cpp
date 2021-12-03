#include<iostream>
#include<math.h>
using namespace std;
void isprime(int a,int b)
{
    for(int i=a;i<b;i++)
    {
        int f=0;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j == 0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        cout<<i<<" is a prime number"<<endl;
        else
        cout<<i<<" is a composite number"<<endl;
    }
}
int main()
{
 int a,b;
 cin>>a>>b;
 isprime(a,b);
 return 0;
}