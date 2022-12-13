#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Lets assume escape character is *
    string s;
    getline(cin, s);
    // cout << s << endl;
    vector<char> v;
    v.push_back('$');
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '$')
        {
            v.push_back('*');
        }
        else if (s[i] == '*')
        {
            v.push_back('*');
        }
        v.push_back(s[i]);
    }
    v.push_back('$');
    cout << "Senders Side Stuffing" << endl;
    for (auto x : v)
    {
        cout << x;
    }
    cout<<endl;
    cout<<"This is the receiver sides string"<<endl;
    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i] == '*')
        {
            i++;
            cout<<v[i];
            continue;
        }
        cout<<v[i];
    }
    return 0;
}