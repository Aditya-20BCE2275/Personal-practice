#include<iostream>
#include<string>
using namespace std;

// this is solved using recursion
void reverse(string s)
{
    // the base case is set to when the lenght of string reaches 0 the string return going through all of the recursive calls
    if(s.length()==0)
    {
        return;
    }
    // here what we do is break down the string by removing its first character during each recursive call
    //So when the string hits the base condition we print only the first element of the recursive calls 
    // so they go like
    // binod
    // inod
    // nod
    // od
    // d
    // so when the functions returns and we print the first elements only the string gets reversed
    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0]<<"\t";
}


// for recursion we take the string as an input
 void replace(string s)
 {
     if(s.length()==0)  //base case
     {
         return;
     }  
    //  if a[i] and a[i+1] both are p and i we print 3.14 and take the substring of it from next 2 characters as the current character as replaced(printed as 3.14)
     if(s[0]=='p' && s[1]=='i')
     {
         cout<<"3.14";
         replace(s.substr(2));
     }
    //  if the values at a[i] are not p and i we print the characters as it is and pass the substring from the next position as the argument  
     else{
         cout<<s[0];
         replace(s.substr(1));
     }
 }

int main()
{
    string s = "pippxxppiixipi";
    replace(s);
    cout<<endl;
    // cout<<"binod"<<endl;
    // reverse("binod");     
    return 0;
}