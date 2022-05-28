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

void insertatatil(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node* reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *nex;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nex;
    }
    return prev;
}

int main()
{
    node *head = NULL;
    insertatatil(head, 12);
    insertatatil(head, 32);
    insertatatil(head, 43);
    insertatatil(head, 1);
    insertatatil(head, 13);
    display(head);
    node* newhead = reverse(head);
    display(newhead);
    return 0;
}