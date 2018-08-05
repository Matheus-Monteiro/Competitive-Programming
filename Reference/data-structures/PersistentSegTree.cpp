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
        left = right = nullptr;
    }
    Node(){}
};
 
int n, arr[10000];
Node* version[10000];
 
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
 
Node* update(Node* nodeAnt, Node *node, int idx, int value)
{
    int l = nodeAnt->x, r = nodeAnt->y;
    node->x = l, node->y = r;
    
    if(l == r)
        node->value = value;
    else
    {
        int mid = (l + r) / 2;
        if(l <= idx and idx <= mid)
        {
            node->left = update(nodeAnt->left, new Node(0, l, mid), idx, value);
            node->right = nodeAnt->right;
        }
        else
        {
            node->left = nodeAnt->right;
            node->right = update(nodeAnt->right, new Node(0, mid + 1, r), idx, value);
        }
        node->value = node->left->value + node->right->value;
    }
    return node;
}
 
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
 
    Node *root = new Node(0, 0, n-1);
    root = build(root);
    version[0] = root;
    int ver = 1;

    int v, o, x, y;
    while(cin >> o >> x >> y)
    {
        if(o == 1)
        {
            version[ver] = update(version[ver-1], new Node(), x-1, y);
            ver++;
        }
        else
        {
            cin >> v;// versão da segment tree
            cout << query(version[v], x-1, y-1) << '\n';
        }
    }
    
    return 0;
} 