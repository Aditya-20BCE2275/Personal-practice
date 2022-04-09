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

void insertatend(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        head->next = head;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

// why doesnt this func work
// void deletion (node *&head, int pos)
// {
//     node *temp = head;
//     int cnt = 1;
//     node *todel;
//     do
//     {
//         if (pos == cnt + 1)
//         {
//             temp->next = temp->next->next;
//             todel = temp->next;
//             break;
//         }
//         temp = temp->next;
//         cnt++;
//     } while (temp != head);
//     delete todel;
// }

void deletion(node *&head, int pos)
{
    node *temp = head;
    int cnt =1;
    while(cnt!=pos-1)
    {
        temp=temp->next;
        cnt++;
    }

    node* todel = temp->next;
    temp->next=temp->next->next;
    delete todel;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "here the linked list will point again at head" << endl;
}

int main()
{
    node *head = NULL;
    insertatend(head, 1);
    insertatend(head, 2);
    insertatend(head, 3);
    insertatend(head, 4);
    display(head);
    deletion(head, 3);
    display(head);

    return 0;
}