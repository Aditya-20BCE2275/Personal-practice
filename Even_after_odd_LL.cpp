#include <iostream>
using namespace std;

// in linked list we have 2 determiners 1.data 2.pointer to the next node or to null to determine the end of the list;
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

    // we give temp the value of head as we need to shift the itr to the end of the list to ensure that the element gets added at the end and temp is that itr;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
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

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Deletion works as we point the previous node of the node which we wish to delete to the next node of node to be deleted thus getting the node to be deleted out of the list and deleting it by assigning it dynamically to a todelete variable

void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void evenafterodd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = head->next;
    int det;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
}

void deletenode(node *&head, int val)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        deleteathead(head);
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    node *head = NULL;
    insertatatil(head, 1);
    insertatatil(head, 2);
    insertatatil(head, 3);
    insertatatil(head, 4);
    insertatatil(head, 5);
    insertatatil(head, 6);
    display(head);
    // insertathead(head, 4);
    // display(head);
    // cout << search(head, 2) << endl;
    // deletenode(head, 2);
    // display(head);
    // deleteathead(head);
    // display(head);
    evenafterodd(head);
    display(head);
    return 0;
}