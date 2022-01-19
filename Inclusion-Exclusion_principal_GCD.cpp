#include<iostream>
using namespace std;
// Question : there are 2 numbers a and b find the total number of occurences which are divisible by both a nd b between 1 and a number n

    // inclusion-Exclusion principal : It is used to find the number of ways to do something
    // It is used to find total number of student types of questions that we did in set theories
    // it is about coding set operations
int divisible(int n,int a,int b)
{
    // this gives numbers that arre divisible by a
    int c1 = n/a;
    // this gives numbers that arre divisible by b
    int c2 = n/b;
    // this gives numbers that arre divisible by a and b both
    int c3 = n/(a*b); 

    // we return this 
    return c1+c2-c3;
}

// Euclid algorithm to find GCD(Greatest Common Divisor) / HCF(Highest Common Factor)
// If we subtract two numbers their HCF/GCD doesnot change
// Based on this concept we will derive thier HCF 
// we will take the repeated mod of the two numbers which will inturn subtract them.

void GCD(int a,int b)
{
    int rem;
    while(b!=0)
    {
        rem = a%b;
        a=b;
        b=rem;
    }
    // We cout a as ans because when rem will become 0 a will become a and thus the previous and of b is the answer needed
    cout<<a<<endl;
}

int main()
{
    cout<<divisible(40,5,7)<<endl;
    GCD(42,24);
    return 0;
}