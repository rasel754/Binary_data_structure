#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *rignt;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->rignt = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->rignt);
}

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    root->left = a;
    root->rignt = b;
    a->left = c;
    b->left = d;
    b->rignt = e;

    inorder(root);
    return 0;
}