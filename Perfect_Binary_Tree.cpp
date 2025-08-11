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
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node *> q;
    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

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

        if (p->left)
            q.push(p->left);
        if (p->rignt)
            q.push(p->rignt);
    }
    return root;
}

bool isPerfect(Node *root)
{
    if (!root)
        return false;

    queue<pair<Node *, int>> q;
    q.push({root, 1});

    int level = -1;

    while (!q.empty())
    {
        Node *node = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (!node->left && !node->rignt)
        {
            if (level == -1)
                level = depth;
            else if (level != depth)
                return false;
        }
        else
        {
            if (!node->left || !node->rignt)
                return false;
        }

        if (node->left)
            q.push({node->left, depth + 1});
        if (node->rignt)
            q.push({node->rignt, depth + 1});
    }

    return true;
}
int main()
{
    Node *root = input_tree();
    if (isPerfect(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
