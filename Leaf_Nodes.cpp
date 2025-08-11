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

void collectLeafNodes(Node *root, vector<int> &result)
{
    if (!root)
        return;

    if (!root->left && !root->rignt)
    {
        result.push_back(root->value);
        return;
    }
    collectLeafNodes(root->left, result);
    collectLeafNodes(root->rignt, result);
}

int main()
{
    Node *root = input_tree();

    vector<int> result;
    collectLeafNodes(root, result);

    sort(result.begin(), result.end(), greater<int>());

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
