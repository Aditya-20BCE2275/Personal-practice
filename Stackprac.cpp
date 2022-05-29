#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        node *n = new node(data);
        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        node *del = top;
        top = top->next;
        delete del;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "the stack is empty" << endl;
            return;
        }
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << top->data << endl;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.peek();
    s.display();
    return 0;
}