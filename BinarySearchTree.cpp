#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

class BinarySearchtree
{
    node *root;

public:
    BinarySearchtree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        node *n = new node(val);
        node *temp = root;
        node *follow = NULL;
        if (root == NULL)
        {
            root = n;
            return;
        }
        while (temp != NULL)
        {
            follow = temp;
            if (val < temp->data)
            {
                temp = temp->left;
            }
            else if (val >= temp->data)
            {
                temp = temp->right;
            }
        }
        if (follow->data > val)
        {
            follow->left = n;
            cout << "node added" << endl;
        }
        else
        {
            follow->right = n;
            cout << "node added" << endl;
        }
    }

    void display()
    {
        cout << "     " << root->data << endl;
        cout << root->left->data << "               " << root->right->data << endl;
        cout << root->left->left->data << endl;
    }

    bool search(int data)
    {
        if (root == NULL)
        {
            return false;
        }
        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return true;
            }
            else if (temp->data > data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }

    void deleteNode(int data)
    {
        node *temp = root;
        if (root == NULL)
        {
            cout << "the Tree is empty" << endl;
            return;
        }
        node *follow = NULL;
        int f = 0;
        while (temp != NULL)
        {
            follow = temp;
            if (data == temp->data)
            {
                f = 1;
                break;
            }
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (f == 1)
        {
            node *todel = temp;
            if (temp->left == NULL && temp->right == NULL)
            {
                cout << "Deleting Node with no children" << endl;
                if (follow->left == temp)
                {
                    follow->left = NULL;
                    delete todel;
                }
                else
                {
                    follow->right == NULL;
                    delete todel;
                }
                return;
            }

            else if (temp->left == NULL || temp->right == NULL)
            {
                cout << "Deleting Nodes with a single child node" << endl;
                if (temp->left != NULL && data < follow->data)
                {
                    follow->left = temp->left;
                }
                else if (temp->right != NULL && data < follow->data)
                {
                    follow->left = temp->right;
                }
                else if (temp->left != NULL && data > follow->data)
                {
                    follow->right = temp->left;
                }
                else
                {
                    follow->right = temp->right;
                }
                delete todel;
                return;
            }
            else
            {
                // replace the maximum node in the left subtree or minimum in the right subtree with the node to be deleted.
                cout << "Deleting a node with 2 children" << endl;
                node *change = temp;
                change = change->right;
                while (change->left != NULL)
                {
                    change = change->left;
                }
                follow->right = change;
                change->left = temp->left;
                if (temp->right != change)
                {
                    change->right = temp->right;
                    change->left = temp->left;
                    follow->right = change;
                    free(temp);
                }
                else
                {
                    change->left = temp->left;
                    follow->right = change;
                    free(temp);
                }
            }
        }
        else
        {
            cout << "Node not found in the tree" << endl;
            return;
        }
    }
};

int main()
{
    BinarySearchtree bst;
    bst.insert(9);
    bst.insert(4);
    bst.insert(20);
    bst.insert(1);
    bst.display();
    cout << "the result of find in the bst is " << bst.search(9) << endl;
    return 0;
}