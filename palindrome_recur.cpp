#include <iostream>
using namespace std;

bool p(string s, int l, int r)
{
    if (l >= r)
    {
        return true;
    }
    if(s[l] != s[r])
    {
        return false;
    }
    return p(s,l+1,r-1);
}

int main()
{
    string s = "madam";
    cout<<p(s,0,s.length()-1);
    return 0;
}