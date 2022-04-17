#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopre(string s)
{
    string res;
    stack<char> st;
    reverse(s.begin(), s.end());
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] == '(')
    //     {
    //         s[i] = ')';
    //     }
    //     if (s[i] == ')')
    //     {
    //         s[i] = '(';
    //     }
    // }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << "(a-b/c)*(a/k-l)" << endl;
    cout << infixtopre("(a-b/c)*(a/k-l)") << endl;
    return 0;
}