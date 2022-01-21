#include <iostream>
using namespace std;

// remove dulpiates from a string
string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if (ch == ans[0])
    {
        return ans;
    }
    else
    return ch+ans;
}

// move all x to the end of the string
string movex(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch =s[0];
    string ans = movex(s.substr(1));
    if(ch=='x')
    {
        return ans+ch;
    }
    else
    return ch+ans;
}

int main()
{
    // mcout<<movex("axxjkxuhdoixxd")<<endl;
    // cout<<removeDup("aabbcc");
    return 0;
}