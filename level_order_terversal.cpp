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

void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Thre is no tree";
        return;
    }
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        // 1.ber kore ana
        Node *f = q.front();
        q.pop();

        // 2.oi node niye kaj kora
        cout << f->value << " ";

        // 3.children push kora
        if (f->left != NULL)
            q.push(f->left);
        if (f->rignt != NULL)
            q.push(f->rignt);
    }
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

    level_order(root);

    return 0;
}