#include<iostream>
using namespace std;
// in this we recall the same function within itself thus solving all the problems in smaller parts

// in this function sum calls itself until it reaches the number to be zero . this is called recursion
int sum(int n)
{
    // when the number reaches 0 value is return before the function calls itself which prevents the function from going into an infinite loop
    if(n==0)
    {
        return 0;
    }
    // After the if gets executed all other functions also get returned to get the final answer all of this happens in memory stack
    return n + sum(n-1);
}

// this fuction behaves in a similar way
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}

// Executing Fibonacci series through recursion
// executing fionacci sequence 
// in this we repeatedly call the function fibonacci itself which in turn again due to its definition calls itself and this goes on until it hits the base conditions i.e 0 and 1 and this is called recursion
int fibo(int n)
