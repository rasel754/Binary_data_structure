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

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root != NULL)
        q.push(root);

    while (!q.empty())
    {
        // 1.ber kore ana
        Node *p = q.front();
        q.pop();

        // 2.oi node niye kaj kora
        int l, r;
        cin >> l >> r;

        Node *myLeft, *myRight;

        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->rignt = myRight;

        // 3.children push kora
        if (p->left)
            q.push(p->left);
        if (p->rignt)
            q.push(p->rignt);
    }
    return root;
}

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
    Node *root = input_tree();
    level_order(root);
    return 0;
}