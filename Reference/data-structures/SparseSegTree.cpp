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
 
int query(Node *node, int x, int y)
{
    int l = node->x, r = node->y;
    if(l > y or r < x) 
        return 0;
    if(x <= l and r <= y)
        return node->value;
    int mid = (l + r) / 2;
    int ans = (node->left == nullptr ? 0 : query(node->left, x, y));
    ans += (node->right == nullptr ? 0 : query(node->right, x, y));
    return ans;     
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
        {
            if(node->left == nullptr)
                node->left = update(new Node(0, l, mid), idx, value);
            else    
                node->left = update(node->left, idx, value);
        }
        else
        {
            if(node->right == nullptr)
                node->right = update(new Node(0, mid + 1, r), idx, value);
            else
                node->right = update(node->right, idx, value);
        }
        node->value = (node->left == nullptr ? 0 : node->left->value);
        node->value += (node->right == nullptr ? 0 : node->right->value);
    }
    return node;
}
 
int main()
{
    cin >> n;
    Node *root = new Node(0, 0, n-1);
    int o, x, y;
    while(cin >> o >> x >> y)
        if(o == 1)
            root = update(root, x-1, y);
        else
            cout << query(root, x-1, y-1) << '\n';
    return 0;
} 
