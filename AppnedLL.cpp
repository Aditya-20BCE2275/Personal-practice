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

void Append(node *&head, int data)
{
    node *n = new node(data);
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
    cout << "NULL"<<endl;
}

void Preapppend(node *&head, int data)
{
    node *n = new node(data);
    n->next = head;
    head = n;
}

void insert(node *&head, int data, int index)
{
    node *n = new node(data);
    node *temp = head;
    int cnt = 0;
    if (index == 0)
    {
        Preapppend(head, data);
    }
    while (cnt != index - 1)
    {
        temp = temp->next;
        cnt++;
    }
    n->next = temp->next;
    temp->next = n;
}

void deleteattail(node *&head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

void deleteatindex(node *&head, int index)
{
    if(index == 0)
    {
        node* del = head;
        head = head->next;
        delete del;
        return;
    }
    int cnt = 0;
    node *temp = head;
    while (cnt != index - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next->next == NULL)
    {
        deleteattail(head);
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    cout<<endl<<endl;
    node *head = NULL;
    Append(head, 10);
    Append(head, 11);
    Append(head, 12);
    Preapppend(head, 9);
    Append(head, 13);
    insert(head, 100, 2);
    cout<<"Here all the append and insert functions are tested and used to make a linked list"<<endl;
    display(head);
    deleteatindex(head, 2);
    cout<<"here the we have deleted the node at the 2nd index"<<endl;
    display(head);
    deleteattail(head);
    cout<<"here we have deleted the element at the end of the linked list"<<endl;
    display(head);
    deleteatindex(head,0);
    cout<<"Here we have deleted the element at the start of the linked list"<<endl;
    display(head);
    cout<<endl;
    return 0;
}