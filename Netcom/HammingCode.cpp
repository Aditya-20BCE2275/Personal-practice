#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Senders Side Processing
    string s;
    getline(cin, s);
    cout << s[4];
    int k = s.length();
    int r;
    for (int i = 1; i <= k; i++)
    {
        if (pow(2, i) > k + i)
        {
            r = i;
            break;
        }
        // break;
    }
    string si0 = " " + (string)s[4], si1 = " " + (string)s[3], si2 = " " + (string)s[2], si3 = " " + (string)s[1], si4 = " " + (string)s[0];
    cout << si0 << si1 << si2 << si3 << si4;
    int y = stoi(si4);
    cout << y;
    int r0 = (stoi(si4) + stoi(si3) + stoi(si2) + stoi(si1)) % 2;
    int r1 = (stoi(si3) + stoi(si2) + stoi(si1) + stoi(si0)) % 2;
    int r2 = (stoi(si4) + stoi(si3) + stoi(si1) + stoi(si0)) % 2;
    int r3 = (stoi(si4) + stoi(si3) + stoi(si2) + stoi(si0)) % 2;

    vector<int> v;
    v.push_back(r0);
    v.push_back(r1);
    v.push_back(r2);
    v.push_back(r3);
    for (auto u : v)
    {
        cout << u << "\t";
    }
    string code = s;
    for (auto x : v)
    {
        s += to_string(x);
    }

    Recievers Side Processing int s0 = (stoi(si4) + stoi(si3) + stoi(si2) + stoi(si1) + r0) % 2; int s1 = (stoi(si3) + stoi(si2) + stoi(si1) + stoi(si0) + r1) % 2;
    int s2 = (stoi(si4) + stoi(si3) + stoi(si1) + stoi(si0) + r2) % 2;
    int s3 = (stoi(si4) + stoi(si3) + stoi(si2) + stoi(si0) + r3) % 2;

    if (s0 == 0 && s1 == 0 && s2 == 0 && s3 == 0)
    {
        cout << "Message recieved correctly" << endl;
    }
    return 0;
}