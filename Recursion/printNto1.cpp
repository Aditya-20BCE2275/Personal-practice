#include <iostream>
using namespace std;

void Nto1(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    n--;
    Nto1(n);
}

int main()
{
    Nto1(5);
    return 0;
}