#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    int top;
    int a[100];
    Stack()
    {
        top = -1;
    }

    void push(int data)
    {
        if (top == 99)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top = top+1;
        a[top] = data;
        cout<<"pushed"<<endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "The stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "The stack is empty" << endl;
            return;
        }
        cout << a[top] << endl;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.display();
    st.pop();
    st.display();
    st.peek();
    st.display();
    return 0;
}