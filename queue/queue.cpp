#include <iostream>

using namespace std;

class Queue {
private:
	int front;
	int rear;
	int size;
	int *Q;

public:
	Queue() {
		front = rear = -1;
		size = 10;
		Q = new int[size];
	}

	Queue(int size) {
		front = rear = -1;
		this->size = size;
		Q = new int[this->size];
	}

	void enqueue(int x);
	int dequeue();
	void display();
	bool isFull();
	bool isEmpty();
};

bool Queue::isFull() {
	return rear == size-1;
}

bool Queue::isEmpty() {
	return front == rear;
}

void Queue::enqueue(int x) {
	if (isFull()) {
		cout<<"Queue is full"<<endl;
		exit(1);
	} else {
		rear++;

		Q[rear] = x;
	}
} 

int Queue::dequeue() {
	if (isEmpty())
		return -1;
	int x = Q[front];
	front++;
	return x;
}

void Queue::display() {
	for(int i=front+1; i<=rear; i++)
		cout<<Q[i]<<" ";
	cout<<endl;
}

int main() {
	Queue q(5);
	q.enqueue(10);
	q.enqueue(15);
	q.display();
	q.dequeue();
	q.display();
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
}





