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

void insertatail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *appendLastk(node *&head, int k)
{
    node *newtail;
    node *newhead;
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout<<cnt<<endl;
    temp = head;

    int cnt1 = 1;
    while (temp->next != NULL)
    {
        if (cnt1 == cnt - k)
        {
            newtail = temp;
        }
        temp = temp->next;
        cnt1++;
    }
    temp->next = head;
    newhead = newtail->next;
    newtail->next = NULL;
    cout<<"the function will return now"<<endl;
    return newhead;
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

int main()
{
    node *head = NULL;
    insertatail(head,1);
    insertatail(head,2);
    insertatail(head,3);
    insertatail(head,4);
    insertatail(head,5);
    insertatail(head,6);
    insertatail(head,7);
    display(head);
    head = appendLastk(head,3);
    display(head);
    
    return 0;
}