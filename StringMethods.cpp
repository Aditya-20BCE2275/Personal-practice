#include<iostream>
// algorithm has sort func
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string s1 ="fam",s2="ily";
    // we can output strings by directly adding them too but this doesnot change the values of strings like append
    cout<<s1+s2<<endl;
    //  this appends the s2 to string s1 thus s1 becomes family. we can do this vice versa as well
    s1.append(s2);
    cout<<s1<<endl;
    // we can access a particular character of the string just like the arrays
    cout<<s1[2]<<endl;
    
    string a="ok this is a test string";
    // we can clear the contents inside the string by using clear function
    a.clear();
    cout<<"the contents inside the strings are = "<<a<<endl;

    // To compare 2 strings we use string.compare(string2)

    // 0 : if both strings are equal.
    // A value < 0 : if s1 is shorter than s2 or,
    // first character that doesn't match is smaller than s2.
    // A value > 0 : if s1 is longer than s2 or,
    // first character that doesn't match is greater

    cout<<s1.compare(s2)<<endl;

    // fucntion to check if the string is empty string.empty()
    if(a.empty())
    {
        cout<<"the string is empty"<<endl;
    }

    // If we want to delete specific indexes from the string we use string.erase(starting index, No of elements to be deleted)
    s1.erase(0,2);
    cout<<s1<<endl;

    // string.find("words we wanna find") is used to search and find the string index at which the following word occurs
    string str = "find something in this";
    cout<<str.find("some")<<endl;

    // if we want to insert some string inside already exsisting string we can use string.insert(index at which u wanna insert,"words u wanna insert")
    str.insert(4," inserted");
    cout<<str<<endl;

    // the length of the string can be determined using string.length() or using string.size()
    // to check this lets have a loop size

    for (int i = 0; i < str.length(); i++)
    {
        cout<<str[i]<<endl;
    }
    
    // if we want to retrive sub-string from a string we can use string.substr(index of start of substring, no of words )
    cout<<str.substr(6,4)<<endl;

    // We can convert numeric strings to int and vice versa by stoi(string) and to_string(x)
    string numeric = "786";
    int x = stoi(numeric);
    cout<<"string to integer = "<<x<<endl;
    cout<<to_string(x) + "2"<<endl;

    //Sorting a string by sort function . if we wish to sort from begining to end we can use sort(string.begin(),string.end()) 
    string so = "asfubeojfoeadbabug";
    sort(so.begin(),so.end());
    cout<<so<<endl;
    int ok = stoi(numeric)+stoi(numeric);
    cout<<ok;
    return 0;
}