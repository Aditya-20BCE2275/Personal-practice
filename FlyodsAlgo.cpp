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

void insertAtend(node *&head, int val)
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

void makeLoop(node *&head, int pos)
{
    node *temp = head;
    node *startnode;
    int cnt = 1;
    while (temp->next != NULL)
    {
        if (cnt == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        cnt++;
    }
    temp->next = startnode;
}

bool detectCycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    node *temp = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    while (temp->next != slow->next)
    {
        temp = temp->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main()
{
    node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
    insertAtend(head, 5);
    insertAtend(head, 6);
    makeLoop(head, 3);
    // display(head);
    cout << "if the cycle is detected the output is 1 else 0" << endl;
    cout << detectCycle(head) << endl;
    cout << "when the cycle is detected we try to remove the cycle by removeCycle and then if the cycle is removed the output becomes 0 and the list is printed" << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;
    display(head);

    return 0;
}