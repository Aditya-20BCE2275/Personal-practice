#include <iostream>
using namespace std;

// reversing a linked list can be done using 3 pointers current,previous and next.

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

void Insertattail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node* reverselist(node* &head)
{
    node* previous = NULL;
    node* curr = head;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=previous;
        previous=curr;
        curr=next;
    }
    return previous;
}

void display(node* head)
{
    node* temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
main()
{
    node *head = NULL;
    Insertattail(head, 1);
    Insertattail(head, 2);
    Insertattail(head, 3);
    Insertattail(head, 4);
    display(head);
    node* newhead = reverselist(head);
    display(newhead);
    return 0;
}