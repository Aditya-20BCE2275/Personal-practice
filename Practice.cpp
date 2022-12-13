#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertattail(int data, node *&head)
{
    node *n = new node(data);
    if (head == nullptr)
    {
        head = n;
        cout << "new node is inserted at the head coz it was empty lol" << endl;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    cout << "A new node is inserted at the tail" << endl;
}

void deletenode(node *&head, int val)
{
    if (val == head->data)
    {
        node *todel = head;
        head = head->next;
        delete todel;
        cout << "the head node deleted" << endl;
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
    cout << "node deleted" << endl;
}

void display(node *head)
{
    cout << endl;
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *oddEvenList(node *head)
{
    queue<node *> q;
    node *s = head;
    while (s->next->next != NULL && s->next != NULL)
    {
        cout << "entered while" << endl;
        if (s->next)
        {
            q.push(s->next);
        }
        s->next = s->next->next;
        if (s->next != NULL)
        {
            s = s->next;
        }
    }
    cout << "while ended";
    // s.next = NULL;
    while (!q.empty())
    {
        s->next = q.front();
        s = s->next;
        q.pop();
    }
    s->next = NULL;
    return head;
    // delete q;
}

int main()
{
    node *head = nullptr;
    // insertattail(1, head);
    // insertattail(2, head);
    // insertattail(3, head);
    // insertattail(4, head);
    // insertattail(5, head);
    // display(head);
    // deletenode(head, 4);
    // display(head);
    insertattail(1, head);
    insertattail(2, head);
    insertattail(3, head);
    insertattail(4, head);
    insertattail(5, head);
    display(head);
    node *temp = oddEvenList(head);
    display(temp);
    return 0;
}