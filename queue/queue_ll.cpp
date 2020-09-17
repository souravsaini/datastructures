#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		next = NULL;
	} 
};

class Queue {
private:
	Node *front;
	Node *rear;
public:
	Queue() {
		front = rear = NULL;
	}

	void enqueue(int);
	int dequeue();
	void display();
	bool isEmpty();
};

bool Queue::isEmpty() {
	return front == NULL;
}

void Queue::enqueue(int data) {
	Node *temp = new Node(data);

	if(rear == NULL) {
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

int Queue::dequeue() {
	if(isEmpty()) 
		return -1;

	Node *temp = front;
	int data = temp->data;
	front = front->next;
	if(front == NULL)
		rear = NULL;
	delete(temp);
	return data;
}

void Queue::display() {
	Node *temp = front;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Queue q;
	// q.enqueue(10);
	// q.enqueue(20);
	// q.enqueue(30);
	// q.enqueue(40);
	// //q.enqueue(50);
	// q.display();
	// cout<<q.dequeue()<<endl;
	// cout<<q.dequeue()<<endl;
	// cout<<q.dequeue()<<endl;
	// cout<<q.dequeue()<<endl;
	// cout<<q.dequeue()<<endl;
	q.enqueue(10);
	cout<<q.dequeue()<<endl;
	q.enqueue(20);
	q.enqueue(30);
	q.display();
	return 0;
}

