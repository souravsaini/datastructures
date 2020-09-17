#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
}*head = NULL;

void insert(struct Node *ptr, int index, int item) {
	struct Node *temp;
	
	if(index == 0) {
		temp = (struct Node*) malloc(sizeof(struct Node));
		temp->data = item;
		temp->prev = NULL;
		temp->next = ptr;
		ptr->prev = temp;
		ptr = temp;
	} else {
		for(int i=0; i<index-1; i++)
			ptr = ptr->next;
		temp = (struct Node*) malloc(sizeof(struct Node));
		temp->data = item;
		temp->prev = ptr;
		temp->next = ptr->next;
		if(ptr->next)
			(ptr->next)->prev = temp;
		ptr->next = temp;
	}
}

void display(struct Node *ptr) {
	while(ptr!=NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}

int main() {
	insert(head, 0, 10);
	//insert(head, 0, 20);
	//insert(head, 2, 30);
	display(head);
}