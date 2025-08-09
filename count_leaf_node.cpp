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

int count_leaf_node(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->rignt == NULL)
        return 1;

    int l = count_leaf_node(root->left);
    int r = count_leaf_node(root->rignt);

    return l + r;
}
int main()
{
    Node *root = input_tree();
    cout << count_leaf_node(root);
    return 0;
}