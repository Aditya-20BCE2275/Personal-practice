#include <iostream>
using namespace std;
// Lets try to make this doubly ll
// NULL <-- 9 <-> 12 <-> 92 <-> 2 <-> 75 --> NULL

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertattail(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        head->next = NULL;
        head->prev = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    cout << "NULL <-- ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " < - > ";
        }
        temp = temp->next;
    }
    cout<<" -->NULL" << endl;
}

int main()
{
    node *head = NULL;
    int data;
    for (int i = 0; i < 5; i++)
    {
        cout << "enter the data " << endl;
        cin >> data;
        insertattail(head, data);
    }
    display(head);
    return 0;
}