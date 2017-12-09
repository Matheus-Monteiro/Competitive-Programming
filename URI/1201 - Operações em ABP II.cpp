// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Operações em ABP II
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1201

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;
	Node(int _key)
	{
		key = _key;
		left = right = nullptr;
	}
};

Node* insert(Node *root, int key)
{
	if(root == nullptr)
		return new Node(key);
	else
	{
		if(root->key > key)
			root->left = insert(root->left, key);
		else
			root->right = insert(root->right, key);
		return root;
	}
}

Node* maxValueNode(Node *root)
{
	Node *aux = root;
	while(aux->right != nullptr)
		aux = aux->right;
	return aux;
}

Node* deleteNode(Node *root, int key)
{
	if(root == nullptr)
		return root;
	if(root->key > key)
		root->left = deleteNode(root->left, key);
	else if(root->key < key)
		root->right = deleteNode(root->right, key);
	else
	{
		if(root->left == nullptr)
		{
			Node *tmp = root->right;
			delete root;
			return tmp;
		}
		if(root->right == nullptr)
		{
			Node *tmp = root->left;
			delete root;
			return tmp;
		}
		Node *tmp = maxValueNode(root->left);
		root->key = tmp->key;
		root->left = deleteNode(root->left, tmp->key);
	}
	return root;
}

bool search(Node *root, int key)
{
	if(root == nullptr)
		return false;
	if(root->key > key)
		return search(root->left, key);
	else if(root->key < key)
		return search(root->right, key);
	else
		return true;
}

bool fl;

void inOrder(Node *root)
{
	if(root != nullptr)
	{
		inOrder(root->left);
		if(fl) printf(" "); else fl = 1;
		printf("%d", root->key);
		inOrder(root->right);
	}
}

void preOrder(Node *root)
{
	if(root != nullptr)
	{
		if(fl) printf(" "); else fl = 1;
		printf("%d", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void posOrder(Node *root)
{
	if(root != nullptr)
	{
		posOrder(root->left);
		posOrder(root->right);
		if(fl) printf(" "); else fl = 1;
		printf("%d", root->key);
	}
}

int main()
{
	string s;
	Node *root = nullptr;

	while(getline(cin, s))
	{
		int p = s.find(" ");
		string aux = s.substr(0, p);
		int num;
		if(aux.size() != s.size())
			num = stoi(s.substr(p+1));
		if(aux == "I")
			root = insert(root, num);
		else if(aux == "P")
			printf("%d ", num), printf(search(root, num) ? "existe\n" : "nao existe\n");
		else if(aux == "R")
			root = deleteNode(root, num);
		else if(aux == "INFIXA")
			fl = 0, inOrder(root), printf("\n");
		else if(aux == "PREFIXA")
			fl = 0, preOrder(root), printf("\n");
		else if(aux == "POSFIXA")
			fl = 0, posOrder(root), printf("\n");
	}

	return 0;
}
