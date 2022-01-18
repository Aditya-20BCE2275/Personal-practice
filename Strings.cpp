#include<iostream>
#include<string>
using namespace std;

int main()
{
    // Methods to declare the strings
    // this method inputs only words as their strings not whole lines 
    string str;
    cin>>str;
    cout<<str<<endl;
    // this methods prints same characters for n number of times
    // it only prints single characters in form of a string 
    string str1(5,'A');
    cout<<str1<<endl;
    // Predeclared string
    string str2;
    str2 ="Aditya Mohite";
    cout<<str2<<endl<<endl;
    // Entering sentences in strings
    string str3;
    cout<<"enter the sentence u want to enter in the string"<<endl;
    getline(cin,str3);
    cout<<str3<<endl;
    return 0;
}