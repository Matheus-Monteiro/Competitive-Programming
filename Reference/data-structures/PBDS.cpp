#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ordered_set X;
    X.insert(2);
    X.insert(13);
    X.insert(5);
    X.insert(2);
    cout << *X.find_by_order(0) << '\n';
    cout << X.order_of_key(1) << '\n';

    return 0;
}