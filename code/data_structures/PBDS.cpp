#include <bits/stdc++.h>
// Common file
#include <ext/pb_ds/assoc_container.hpp> 
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp> 
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


///////////////////////////////////////////////////////


#include <bits/stdc++.h>
// Common file
#include <ext/pb_ds/assoc_container.hpp> 
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define var pair<int,int>
#define ordered_multiset tree<var, null_type, less<var>
	, rb_tree_tag, tree_order_statistics_node_update>

int id = 0; map<int,vi> ids;

void insere(ordered_multiset &s, int x)
{
    s.insert({x, ++id});
    ids[x].push_back(id);
}

void apaga(ordered_multiset &s, int x)
{
	if(ids[x].empty()) return;
    s.erase({x, ids[x].back()});
    ids[x].pop_back();
}

int kth(ordered_multiset &s, int x)
{
    return s.find_by_order(x)->first;
}

int smallerCount(ordered_multiset &s, int x)
{
    return s.order_of_key({x, 0});
}

int count(ordered_multiset &s, int x)
{
    return smallerCount(s, x + 1) - smallerCount(s, x);
}

ordered_multiset::iterator find(ordered_multiset &s, int x)
{
	if(ids[x].empty())
		return s.end();
    return s.find({x, ids[x].back()});
}

int main()
{
    ordered_multiset X;
    
   	// usar funcoes ...

    return 0;
}
