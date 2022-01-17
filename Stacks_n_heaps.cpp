#include<iostream>
using namespace std;

//This program literally does nothing but comments explain the concept of Heaps and memory stacks 

int main()
{
    // Stack
    //  In executionof any code the functions in the code get added in the memory stack as memory frames

    // Heap works on dynamic memory allocation
    // In this we can allocate and deallocate memory manually in a heap
    // Heap has no fixed size
    // new operator is used to allocate memory in heap
    int* p =new int();
    // using derefferncing we give array to heap pointers
    // heaps allocate memory in the stack and heap variables contain memory address that of the variables in the stack
    *p=10;
    // in heaps we allocate memory manually using new int() we also have to deallocate memory using delete()
    // after deleting the pointer this pointer still exsists and points to nothing, thus its called a dangling pointer
    delete(p);
    // This creates a block of memory in memoyr stack
    p = new int[4];
    // this deletes the whole block of memory dynamically allocated through heap
    delete[]p;
    // This helps in destroying the dangling pointer and the heap pointer gets destroyed automatically when the main function is popped from the memory stack 
    p=NULL;
    return 0;
}