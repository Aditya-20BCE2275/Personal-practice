#include <iostream>
using namespace std;

// functional
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

// parameterized
void fact1(int n, int prod)
{
    if (n == 1)
    {
        cout << prod;
        return;
    }
    prod = prod * n;
    fact1(n - 1, prod);
}

int main()
{
    cout << fact(4) << endl;
    fact1(4, 1);
    return 0;
}