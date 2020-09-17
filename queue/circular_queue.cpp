#include <iostream>

using namespace std;

class CircularQueue {
private:
	int front;
	int rear;
	int size;
	int *Q;

public:
	CircularQueue() {
		front = rear = 0;
		size = 10;
		Q = new int[size];
	}

	CircularQueue(int size) {
		front = rear = 0;
		this->size = size;
		Q = new int[this->size];
	}

	void enqueue(int x);
	int dequeue();
	void display();
	bool isFull();
	bool isEmpty();
};

bool CircularQueue::isFull() {
	return (rear+1) % size == front % size;
}

bool CircularQueue::isEmpty() {
	return rear == front;
}

void CircularQueue::enqueue(int x) {
	if (isFull()) {
		cout<<"Queue is full"<<endl;
		exit(1);
	} else {
		rear = (rear+1) % size;
		Q[rear] = x;
	}
}

int CircularQueue::dequeue() {
	if (isEmpty()) 
		return -1;

	front = (front+1) % size;
	return Q[front];
}

void CircularQueue::display() {
	int i = front+1;

	do {
		cout<<Q[i]<<" ";
		i = (i+1) % size;
	}while(i != (rear+1) % size);
	cout<<endl;
}

int main() {
	CircularQueue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	//q.enqueue(50);
	q.display();
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
}