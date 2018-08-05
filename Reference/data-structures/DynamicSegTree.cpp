#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    int x, y;
    Node *left, *right;
    Node(int _value, int _x, int _y)
    {
        value = _value, x = _x, y = _y;
    }
    Node(){}
};

int n, arr[10000];

Node* build(Node *node)
{
    int l = node->x, r = node->y;
    if(l == r)
        node->value = arr[l];
    else
    {
        int mid = (l + r) / 2;
        node->left = build(new Node(0, l, mid));
        node->right = build(new Node(0, mid + 1, r));
        node->value = node->left->value + node->right->value;
    }
    return node;
}

int query(Node *node, int x, int y)
{
    int l = node->x, r = node->y;
    if(l > y or r < x) 
        return 0;
    if(x <= l and r <= y)
        return node->value;
    int mid = (l + r) / 2;
    return query(node->left, x, y) + query(node->right, x, y);
}

Node* update(Node *node, int idx, int value)
{
    int l = node->x, r = node->y;
    if(l == r)
        node->value = arr[idx] = value;
    else
    {
        int mid = (l + r) / 2;
        if(l <= idx and idx <= mid)
            node->left = update(node->left, idx, value);
        else
            node->right = update(node->right, idx, value);
        node->value = node->left->value + node->right->value;
    }
    return node;
}

int main()
{
    Node *root = nullptr;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    root = new Node(0, 0, n-1);
    root = build(root);
    
    int o, x, y;
    while(cin >> o >> x >> y)
        if(o == 1)
            root = update(root, x-1, y);
        else
            cout << query(root, x-1, y-1) << '\n';

    return 0;
} 