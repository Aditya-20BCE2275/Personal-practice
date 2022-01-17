#include<iostream>
using namespace std;

// Increment fucntion
int increment(int a)
{
    a++;
}
int increment1(int* pass)
{
    *pass = *pass+1;
}

// Pointers are variables that store the address of other variables;
int main()
{
    int a=10;
    // int* aptr creates a variable that stores the memory address of int a
    int* aptr = &a;
    cout<<endl;  
    cout<<"a = "<<a<<endl;
    // This outputs the memory address of a which is stored in aptr pointer;
    cout<<"aptr = "<<aptr<<endl;
    // &a also outputs memory address of a directly where is aptr its a completely different variable which stores the memory address of the variable a
    cout<<"&a = "<<&a<<endl;
    // *aptr after its creation whenever accessed is treated as a derefferncing operator and it couts the value of a not the address of a;
    cout<<"*aptr = "<<*aptr<<endl;

    //Pointer  arithematic
    // when we increment or decrement a pointer it does it according to the data type of the pointer 
    // an int pointer will increment its address by 4 whereas an char pointer will increment its value by 1;
    aptr++; 
    cout<<"increment of int a = "<<aptr<<endl;
    cout<<endl;

    // Pointers and arrays
    // arrays can be used in similar way as pointers. When we declare an array variable that variable is pointing towards the 0th element of that array.  

    int arr[]={10,20,30};
    // we dereffernce the pointers in the same way
    // cout<<*arr;
    // Traversing the array through pointer.. we cant inncrement the pointer arr through arr++
    for(int i=0;i<3;i++)
    {
        // we donot increment 4 bytes as arr is an indexing pointer it accesses the next index not the next memory location.
        cout<<*(arr+i)<<endl;
    }
    cout<<endl<<endl;

    // Pointer to Pointer
    //  I can store pointer inside a pointer but and to access the values in a particular variable we need to dereffernce .
    // So to get the value stored of an int which has a pointer which inturn is stored into a pointer we need to dereffernce it twice
    int p= 20;
    int* bptr=&p;
    // this pointer stores a pointer
    int** cptr;
    // storing memory address of bptr
    cptr= &bptr;
    // We dereffernce cptr twice to get the value stored inside p as cptr points to bptr and bptr points to p value;
    cout<<**cptr<<endl;
    cout<<endl;

    // passing pointers as functions
    int b=2;
    // Value of b doesnot change as it performs pass by value and it makes a copy of the value of the vaiable and it doesnot change the real value
    increment(b);
    cout<<"Pass by value = "<<b<<endl;

    //Value of b does change here as it is passed by reffernce as in this a pointer is sent and the value present inside that address block increases thus the vlaue of the variable overall chaanges as we want
    int* pass = &b;
    increment1(pass);
    cout<<"Pass by reffernce = "<<b<<endl;
    return 0;
}