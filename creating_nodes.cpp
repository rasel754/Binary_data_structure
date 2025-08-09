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

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(10);
    Node *b = new Node(10);
    Node *c = new Node(10);
    Node *d = new Node(10);
    Node *e = new Node(10);

    root->left = a;
    root->rignt = b;
    a->left = c;
    b->left = d;
    b->rignt = e;

    return 0;
}