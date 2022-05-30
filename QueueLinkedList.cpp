#include <iostream>
using namespace std;

// Queue = 10 20 30 40 50

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

class queue
{
public:
    node *start, *end;
    queue()
    {
        start = NULL;
        end = NULL;
    }

    void enqueue(int data)
    {
        node *n = new node(data);
        if (start == NULL)
        {
            start = n;
            end = n;
            return;
        }
        n->next = end;
        end = n;
    }

    void dequeue()
    {
        if (start == NULL)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        node* temp = end;
        while(temp->next != start)
        {
            temp = temp->next;
        }
        node* todel = start;
        start = temp;
        delete todel;
    }

    void peek()
    {
        if (start == NULL)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << start->data << endl;
    }

    void display()
    {
        if (start == NULL)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        node *temp = end;
        while (temp != start)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<temp->data;
        cout << endl;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    q.peek();
    return 0;
}