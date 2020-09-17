#include <iostream>

using namespace std;

class Node {
public:
	Node *lchild;
	int data;
	Node *rchild;

	Node(int data) {
		this->data = data;
	}
};

class BST {
private:
	Node *root;
public:
	BST() {
		root = NULL;
	}
	Node* getRoot(){ return root; }
	void insert(int);
	void inOrder(Node*);
};

void BST::insert(int data) {
	Node *p = root;
	Node *r, *t;
	if(root == NULL) {
		t = new Node(data);
		t->lchild = NULL;
		t->rchild = NULL;
		root = t;
		return;
	}
	while(p!=NULL) {
		r = p;
		if(data < p->data)
			p = p->lchild;
		else if(data > p->data)
			p = p->rchild;
		else
			return;
	}
	t = new Node(data);
	t->lchild = NULL;
	t->rchild = NULL;

	if(data < r->data)
		r->lchild = t;
	else
		r->rchild = t;
}

void BST::inOrder(Node* p) {
	if(p) {
		inOrder(p->lchild);
		cout<<p->data<<" ";
		inOrder(p->rchild);
	}
}


int main() {
	BST bst;
	bst.insert(20);
	bst.insert(15);
	bst.insert(25);
	bst.insert(10);
	bst.insert(12);
	bst.insert(22);
	bst.inOrder(bst.getRoot());
}


