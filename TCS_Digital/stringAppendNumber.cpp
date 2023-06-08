#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    getline(cin,s);
    int l = 0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            t += s[i];
        }
        else
        break;
    }
    reverse(t.begin(),t.end());
    l = stoi(t);
    if(l==s.length()-t.length())
    cout<<"true";
    else
    cout<<"false";
    return 0;
}