//============================================================================
// Name        : oop-3s-3kr.cpp
// Author      : Alexey Suslov
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int value;
	int count;
	Node *left, *right;
};

class Tree {
public:
	Node *root;
	Tree() {
		root = 0;
	}
	Tree(int);
	Tree(const Tree&ob);
	void copyTree(Node *&rootNew, Node *rootOld);
	void delTree(Node *wer);
	~Tree() {
		delTree(root);
	}
	void push(Node *&wer, int data);
	void look(Node *wer);
	int findLeaves(Node *wer, int count);
};

Tree::Tree(int t) {
	root = 0;
	for (int i = 0; i < t; i++)
		push(root, rand() % 10 - 5);
}

void Tree::copyTree(Node *&rootNew, Node *rootOld)
{
	if(rootOld->left != 0) {
		for(int i = 0; i < (rootOld->left)->count; i++)
			push(rootNew, (rootOld->left)->value);
		copyTree(rootNew, rootOld->left);
	}
	if(rootOld->right != 0) {
		for(int i = 0; i < (rootOld->right)->count; i++)
			push(rootNew,(rootOld->right)->value);
		copyTree(rootNew, rootOld->right);
	}
}

Tree::Tree(const Tree &ob) {
	if(ob.root == 0) root = 0;
	else {
		root = new Node;
		root->value = ob.root->value;
		root->count = 1;
		root->left = 0;
		root->right = 0;
		copyTree(root, ob.root);
	}
}

void Tree::push(Node *&wer, int data) {
	if(wer == 0) {
		wer = new Node;
		wer->value = data;
		wer->left = 0;
		wer->right = 0;
		wer->count = 1;
	}
	else if(data < wer->value) push(wer->left, data);
	else if(data > wer->value) push(wer->right, data);
	else wer->count++;
}

void Tree::delTree(Node *wer) {
	if(wer->left !=0 ) delTree(wer->left);
	if(wer->right != 0) delTree(wer->right);
	delete wer;
}

void Tree::look(Node *wer) {
	if(wer != 0) {
		look(wer -> left);
		cout << "�����: " << wer->value << " - " << wer->count;
		cout << " ����" << endl;
		look(wer->right);
	}
}

int Tree::findLeaves(Node *wer, int count) {
	int nodeCount = count;
	if(wer == 0) return nodeCount;
	else if(wer->left == 0 && wer->right == 0) nodeCount++;
	else {
		nodeCount = findLeaves(wer->left, findLeaves(wer->right, nodeCount));
	}
	return nodeCount;
}

int main() {
	srand(3);
	Tree myTree(20);
	myTree.look(myTree.root);
	Tree secondTree(myTree);
	secondTree.look(secondTree.root);
	cout << secondTree.findLeaves(secondTree.root, 0) << endl;
	return 0;
}
