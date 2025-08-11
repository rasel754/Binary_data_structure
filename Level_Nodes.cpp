#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            f->left = new Node(l);
            q.push(f->left);
        }
        if (r != -1)
        {
            f->right = new Node(r);
            q.push(f->right);
        }
    }
    return root;
}

void print_level(Node *root, int X)
{
    if (!root)
    {
        cout << "Invalid";
        return;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    bool found = false;

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();

        Node *node = p.first;
        int level = p.second;

        if (level == X)
        {
            cout << node->val << " ";
            found = true;
        }

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }

    if (!found)
        cout << "Invalid";
}

int main()
{
    Node *root = input_tree();
    int X;
    cin >> X;
    print_level(root, X);
    return 0;
}
