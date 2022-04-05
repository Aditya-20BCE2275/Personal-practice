#include <iostream>
using namespace std;

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

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    if (head != NULL)
    {
        n->next = head;
        head->prev = n;
    }
    head = n;
}

void insertAttail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;

    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}


void display(node* head)
{
    node* temp = head;
    cout<<"NULL <-- ";
    while(temp!=NULL)
    {
        cout<<temp->data;
        if(temp->next!=NULL)
        {
        cout<<" < - > ";
        }
        temp=temp->next;
    }
    cout<<" --> NULL"<<endl;
}

void deleteAthead(node* &head)
{
    node* todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
}

void deletepos(node* &head,int pos)
{
    if(pos == 1)
    {
        deleteAthead(head);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(temp!=NULL && cnt!=pos)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;
    }
    temp->prev->next=temp->next;
}

void deleteAtend(node* &head)
{
    node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=NULL;
    delete temp->next;

}

int main()
{
    node* head = NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    display(head);
    deleteAtend(head);
    display(head);
    deletepos(head,2);
    display(head);
    deleteAthead(head);
    display(head);

    return 0;
}