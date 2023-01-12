#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Lets assume escape character is *
    string s;
    getline(cin, s);
    // cout << s << endl;
    vector<string> v;
    v.push_back("01111110");
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cnt1=0;
            cnt0++;
            string temp = "";
            temp += s[i];
            v.push_back(temp);
        }
        if (s[i] == '1')
        {
            cnt1++;
            string temp = "";
            temp += s[i];
            v.push_back(temp);
        }
        if (cnt0 > 0 && cnt1 == 5)
        {
            v.push_back("0");
            cnt1 = 0;
            cnt0 = 0;
        }
    }
    v.push_back("01111110");
    cout << "Senders Side Stuffing" << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "This is the receiver sides string" << endl;
    for (int i = 1; i < v.size() - 1; i++)
    {
        // if (v[i] == "01111110")
        // {
        //     i++;
        //     cout << v[i];
        //     continue;
        // }
        cout << v[i];
    }
    return 0;
}