#include <iostream>
using namespace std;

//  bhai ye virtual ka system samjh nai aaya kya scene hai

class prac
{
public:
    int i;
    // function overloading
    virtual void fun()
    {
        cout << "this is the first function" << endl;
    }
    virtual void fun(int i)
    {
        cout << "this is the second function" << endl;
    }
    virtual void fun(char c)
    {
        cout << "this is the third function" << endl;
    }

    prac operator=(prac &a) // Operator overloading
    {
        cout << i - a.i << endl;
    }
};

class deri : public prac
{
public:
    void fun()
    {
        cout <<"this is the derived classes first function "<<endl;
    }
};

int main()
{
    prac a;
    prac* pracptr;
    prac b;
    pracptr = &b;
    pracptr -> fun();
    // cin >> b.i;
    // cout << b.i << endl;
    // a.fun();
    // a.fun(1);
    // a.fun('c');
    // cin >> a.i;
    // cout << a.i << endl;
    // a = b;
    return 0;

}