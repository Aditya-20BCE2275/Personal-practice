// All of this will be executed and must be calculated and visualzed in binary number systems
#include<iostream>
using namespace std;
    // in bit manipulation and bitwise opreations as whole left shift (<<) multiplies the number with the power of 2 
    // for example
    //  1<<2 = 1 * 2^2(4) ; in bits its can be represented as 
    // n = 0001 
    // n<<2
    // n = 0100 ie n=4 so this is what bitwise operation does

    // similarly for right shift the number gets divided by the power of 2
    // 4>>2 = 2 / 2^2 = 1; its bits can be represented as follows :
    // n = 0100
    // n>>2 
    // n = 0001 
    
// GetBit : in this we have to determine that the bit is 0 or 1 in on that particular position
// it takes the number and position at which the bit has to be checked and left shifts 1 to that position and performs and operation on it. If the number on that position is 1 then only the output will be 1
int getbit(int n,int pos)
{
    return((n &(1<<pos))!=0);
}

// SetBit : in this we have to set the bit at a particular position or in other words at a particular positin we have to make the bit 1
// it takes the number and the position at which the bit is to be set as 1 and then using left shifts of 1 it performs an or operation on it. so it will set the bit 1 even if one of the bits are 1 or both of them are 1 
int setbit(int n,int pos)
{
    return(n | (1<<pos));
}

//ClearBit :  This is used to make bit at a particular position 0 
// it takes the number and the position at which the bit is to be set as 0 and then using left shifts we take 1 to that position, this number made by left shifts of 1 is called as mask. now we take the complement/negation of this mask and perform and operation on them. this makes the masked number at that position 0 and rest all 1. Thus the number at the desired location will result into 0 and rest all would would remain unaffected

int clearbit(int n,int pos)
{
    return(n & (~(1<<pos)));
}

// UpdateBit : In this we will update the bitvalue at a particular position to our desired bit value which we have to send as an argument 
// it first uses clearbit operation too clear the bit at that position and then we will setbit
int updatebit(int n,int pos,int value)
{
    int mask = ~(1<<pos);
    n = n & mask;
    // int this we use term value because the value desired might be 0 or 1. So we enter value there instead of a hardcoded 0 or 1.
    return (n | (value<<pos));
}
int main()
{
    // cout<<getbit(5,2)<<endl;
    // cout<<setbit(5,1)<<endl;
    // cout<<clearbit(5,2)<<endl;
    cout<<updatebit(5,1,1);
    return 0;
}