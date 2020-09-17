#ifndef queue_h
#define queue_h

#include <iostream>
using namespace std;

class Node {
public:
	Node *lchild;
	int data;
	Node *rchild;
};



class QueueNode {
public:
	Node *data;
	QueueNode *next;

	QueueNode(Node* data) {
		this->data = data;
		next = NULL;
	} 
};


class Queue {
private:
	QueueNode *front;
	QueueNode *rear;
public:
	Queue() {
		front = rear = NULL;
	}

	void enqueue(Node*);

	Node* dequeue();
	bool isEmpty();
	void display();
};

bool Queue::isEmpty() {
	return front == NULL;
}

void Queue::display() {
	QueueNode *temp = front;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


void Queue::enqueue(Node* data) {
	QueueNode *temp = new QueueNode(data);

	if(rear == NULL) {
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

Node* Queue::dequeue() {
	if(isEmpty()) 
		return NULL;

	QueueNode *temp = front;
	Node *data = temp->data;
	front = front->next;
	if(front == NULL)
		rear = NULL;
	delete(temp);
	return data;
}


#endif /* queue_h */