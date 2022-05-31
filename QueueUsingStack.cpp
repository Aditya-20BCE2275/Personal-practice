#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1, s2;
    public:
    void enqueue(int data)
    {
        s1.push(data);
    }

    void dequeue()
    {
        if(s1.empty())
        {
            cout<<"The Queue is empty "<<endl;
            return;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void peek()
    {
        if(s1.empty())
        {
            cout<<"The Queue is empty "<<endl;
            return;
        }   
        cout<<"The topmost element is being displayed now"<<endl;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        cout << s2.top() << endl;
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void display()
    {
        if(s1.empty())
        {
            cout<<"The Queue is empty "<<endl;
            return;
        }
        cout << "the whole stack is being displayed now" << endl;
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        cout<<endl;
    }
};

int main()
{
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.display();
    q1.dequeue();
    q1.display();
    q1.peek();
    return 0;
}