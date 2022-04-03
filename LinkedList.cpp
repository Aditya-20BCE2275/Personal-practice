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
    while (temp->next != NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    insertatatil(head, 1);
    insertatatil(head, 2);
    insertatatil(head, 3);
    display(head);
    insertathead(head, 4);
    display(head);
    cout<<search(head,2)<<endl;
    return 0;
}