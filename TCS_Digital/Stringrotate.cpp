// optimised
// string s1 = "hello";
//     string s2 = "lohelf";

//     s1+=s1;
//     cout<<s1.find(s2);
//     if(s1.find(s2)<s1.length())
//     {
//         cout<<"true";
//         return 0;
//     }
//     cout<<"false";

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "lohel";
    if (s1 == s2)
        cout << "true";
    string t = s1;

    do
    {
        if (s2 == t)
        {
            cout << "true";
            // break;
            return 0;
        }
        char a = t[t.length() - 1];
        string te = "";
        te+=a;
        t.pop_back();
        t.insert(0, te);
    } while (t != s1);
    cout << "False";
    return 0;
}