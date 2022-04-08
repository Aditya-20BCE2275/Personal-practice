#include <iostream>
using namespace std;


// the checkinstersectioon func is working
// check the instersection function which makes the list intersect


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
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp = head1;
    // pos--;
    while (pos != 0)
    {
        pos--;
        temp = temp->next;
    }
    node *temp1 = head2;
    while (temp1->next != NULL)
    {
        temp = temp->next;
    }
    temp1->next = temp;
    cout<<"okk";
}

int length(node* head)
{
    int cnt;
    while(head!=NULL)
    {
        cnt++;
    }
    return cnt;
}

node *intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d != 0)
    {
        if (ptr1 == NULL)
        {
            // return -1;
            break;
        }
        ptr1 = ptr1->next;
        d--;
    }

    while (ptr1 != ptr2 && ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        return ptr1;
    }
    // return -1;
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

int main()
{
    int pos;
    node *head1 = NULL;
    node *head2 = NULL;
    insertatend(head1, 1);
    insertatend(head1, 2);
    insertatend(head1, 3);
    insertatend(head1, 4);
    insertatend(head1, 5);
    insertatend(head1, 6);
    insertatend(head1, 7);
    insertatend(head2, 8);
    insertatend(head2, 9);
    intersect(head1, head2, 5);
    node* show = intersection(head1,head2);
    display(head1);
    display(head2);
    cout<<"INtersection point is = "<<show->data<<endl;
    return 0;
}