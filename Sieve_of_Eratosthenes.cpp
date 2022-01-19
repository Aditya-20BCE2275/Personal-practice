#include <iostream>
using namespace std;

// This is a method to print all the prime numbers in a given range
// we first mark the all the multiples of the prime numbers in the given range starting with 2 (in this we take firt prime multiple jump its square as the multiples before it are marked)
// in the end the numbers which are left as unmarked are the prime numbers

int PrimeSieve(int n)
{
    int prime[1000] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            // this inner for loop marks all the multiples of i starting with i^2 because all the multiples of i before that would be already marked by multiples of primes before that numbers
            for (int j = i * i; j <= n; j = j + i)
            {
                // we make prime[i]=1 to mark the elements
                prime[j] = 1;
            }
        }
    }

    // this loop prints all the unmarked of prime[i] == 0 as they are the unmarked elements and thus they are prime
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

void factorization(int n)
{
    int spf[100] = {0};
    // in this loop all the elements are initialized to the numbers themselves as we first consider all the numbers to be prime
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }
    // in this loop we check if the spf of numbers are the numbers themselves and if yes we update the spf of those numbers
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i*i; j <= n; j = j + i)
            {
                // now as we start this loop from i^2 positions we check if the spf of those numbers are also the number itself and then update them
                if(spf[j]==j)
                    spf[j]=i;
                
            }
        }
    }
    while (n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];

    }
    
    
}
    int main()
    {
        int n;
        cin >> n;
        PrimeSieve(n);
        factorization(n);
        return 0;
    }