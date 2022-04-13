#include <iostream>
#include <stack>
using namespace std;

void reversesentence(string s)
{
    stack<string> sta;

    for (int i = 0; s[i] != '\0'; i++)
    {
        string w = "";
        while (s[i] != ' ' && i<s.length())
        {
            w = w + s[i];
            i++;
        }
        sta.push(w);
    }

    while (!sta.empty())
    {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Aditya Mohite";
    reversesentence(s);
    return 0;
}