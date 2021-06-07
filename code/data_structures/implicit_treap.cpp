#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
	int valor, priority, size, sum;
	Node *l, *r;
	bool rev;
	Node(int _valor) : rev(false), sum(_valor), valor(_valor), 
		priority((rand() << 16) ^ rand()), size(1), l(nullptr), r(nullptr) {}
	~Node() { delete l; delete r; }
 
	void recalc()
	{
		size = 1;
		sum = valor;
		if(l) size += l->size, sum += l->sum;
		if(r) size += r->size, sum += r->sum;
	}
};
 
struct Treap
{
	int size(Node* t) { return t ? t->size : 0; }

	int size() const { return root ? root->size : 0; }

	Node* propagate(Node* t)
	{
		if(t == nullptr) return t;
		if(t->rev)
		{
			swap(t->l, t->r);
			if(t->l != nullptr) t->l->rev ^= 1;
			if(t->r != nullptr) t->r->rev ^= 1;
			t->rev = 0;
		}
		t->recalc();
		return t;
	}
 
	int position(Node *t, int n)
	{
		//nao esta na treap, botar valor que noa esta no array...
		if(t == nullptr) return -1;
		propagate(t);
		if(n == size(t->l) + 1) return t->valor;
		else if(n <= size(t->l)) return position(t->l, n);
		else return position(t->r, n - size(t->l) - 1);
	}
 
	int at(int n)
	{
		return position(root, n);
	}
 
	Node* merge(Node *l, Node *r)
	{
		l = propagate(l);
		r = propagate(r);
		if(!l or !r) return l ? l : r;
		if(l->priority < r->priority)
		{
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else
		{
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}
 
	void split(Node *v, int valor, Node *&l, Node *&r)
	{
		v = propagate(v);
		l = r = nullptr;
		if(!v) return;
		if(size(v->l) < valor)
		{
			split(v->r, valor - size(v->l) - 1, v->r, r);
			l = v;
		}else
		{
			split(v->l, valor, l, v->l);
			r = v;
		}
		v->recalc();
	}
 
	Node * root;
	Treap() : root(nullptr) {}
	~Treap() { delete root; }
 
	void insert(int valor, int pos)
	{
		Node * l, * r;
		split(root, pos - 1, l, r);
		root = merge(merge(l, new Node(valor)), r);
	}
	
	void erase(int valor)
	{
		Node * l, * m, * r;
		split(root, valor - 1, l, m);
		split(m, 1, m, r);
		delete m;
		root = merge(l, r);
	}
	
	void reverse(int l, int r)
	{
		l--; r--;
		if(l > r) swap(l, r);
		Node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r - l + 1, b, c);
		if(b) b->rev ^= 1;
		root = merge(a, merge(b, c));	
	}
	
	int query(int l, int r)
	{
		Node *a, *b, *c, *d;
		split(root, l - 1, a, b);
		split(b, r - l + 1, c, d);
		int ans = c->sum;
		root = merge(a, merge(c, d));
		return ans;
	}	
	
	/*void emOrdem(Node *node)
	{
		if(node == nullptr) return;
		emOrdem(node->l);
		printf("%d ", node->valor);
		emOrdem(node->r);
	}*/
 
}treap;
 
int main()
{
	srand(time(0));
 
	for(int i = 1; i <= 6; i++)
	{
		int x; cin >> x;
		cout << x << ' ';
	 	treap.insert(x, i);
 	}
	return 0;
}
