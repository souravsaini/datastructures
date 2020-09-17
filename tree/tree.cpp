#include <iostream>
#include "queue.h"

using namespace std;

class Tree {
public:
	Node *root;

	Tree() {
		root = NULL;
	}
	void createTree();
	void preOrder(Node *p);
	void postOrder(Node *p);
	void inOrder(Node *p);
	void levelOrder(Node *p);
	int height(Node *p);
	int count(Node *p);
	int countNodesWithDegree2(Node *p);
	int sum(Node *p);
	int countLeafNodes(Node *p);
};

void Tree::createTree() {
	Node *p, *t;
	int x;
	Queue q;

	cout<<"Enter root value"<<endl;
	cin>>x;

	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;

	q.enqueue(root);

	while(!q.isEmpty()) {
		

		p = q.dequeue();
		cout<<"Enter left child of "<< p->data<<endl;
		cin>>x;

		if (x != -1) {
			t = new Node;
			t->data = x;

			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}

		cout<<"Enter right child of "<< p->data<<endl;
		cin>>x;

		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
		q.display();
	}
}

void Tree::preOrder(Node *p) {
	if(p) {
		cout<<p->data<<" ";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

void Tree::inOrder(Node *p) {
	if(p) {
		inOrder(p->lchild);
		cout<<p->data<<" ";
		inOrder(p->rchild);
	}
}

void Tree::postOrder(Node *p) {
	postOrder(p->lchild);
	postOrder(p->rchild);
	cout<<p->data<<" ";
}

void Tree::levelOrder(Node *p) {
	Queue q;

	cout<<p->data<<" ";
	q.enqueue(p);

	while(!q.isEmpty()) {
		p = q.dequeue();
		if(p->lchild) {
			cout<<p->lchild->data<<" ";
			q.enqueue(p->lchild);
		}
		if(p->rchild) {
			cout<<p->rchild->data<<" ";
			q.enqueue(p->rchild);
		}
	}

}

int Tree::height(Node *p) {
	int x = 0, y = 0;
	if(p) {
		x = count(p->lchild);
		y = count(p->rchild);
		if(x > y)
			return x+1;
		else
			return y+1;
	}
	return 0;
}

int Tree::count(Node *p) {
	int x = 0, y = 0;
	if(p) {
		x = count(p->lchild);
		y = count(p->rchild);
		return x+y+1;
	}
	return 0;
}

/*
int Tree::count(Node *p) {
	if(p == NULL)
		return 0;
	return count(p->lchild) + count(p->rchild) + 1;
}
*/

int Tree::countNodesWithDegree2(Node *p) {
	int x = 0, y = 0;
	if(p) {
		x = count(p->lchild);
		y = count(p->rchild);
		if(p->lchild && p->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int Tree::sum(Node *p) {
	int x = 0, y = 0;
	if(p) {
		x = count(p->lchild);
		y = count(p->rchild);
		return x+y+p->data;
	}
	return 0;
}

int Tree::countLeafNodes(Node *p) {
	int x = 0, y = 0;
	if(p) {
		x = count(p->lchild);
		y = count(p->rchild);
		if(!p->child && !p->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int main() {

	Tree t;
	t.createTree();
	t.preOrder(t.root);
	cout<<endl;
	t.inOrder(t.root);
	cout<<endl;
	t.levelOrder(t.root);
	cout<<endl;
	cout<<t.count(t.root)<<endl;
}






