#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st,ele);
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insert(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;
    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}