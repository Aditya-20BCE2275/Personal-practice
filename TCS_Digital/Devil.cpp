#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "LLLMMMSppoo$ABCD@XYZ@";
    int m = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '@' || s[i] == '$' )
        {
            cnt++;
            m = max(cnt,m);
            cnt = 0;
        }
        cnt++;
    }
    cout << m;
    return 0;
}