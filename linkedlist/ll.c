#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
  int data;
  struct Node *next;
}*first=NULL;

//create temporary linked list
void create(int A[], int n) {
  struct Node *temp, *last;
  first =(struct Node*) malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for(int i=1; i<n; i++) {
    temp =(struct Node*) malloc(sizeof(struct Node));
    temp->data = A[i];
    temp->next = NULL;
    last->next=temp;
    last = temp;
  }
}

//display linked list
void display(struct Node* ptr) {
  while(ptr!=NULL) {
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

//recursive display
void RDisplay(struct Node* ptr) {
  if(ptr!=NULL) {
    printf("%d ", ptr->data);
    RDisplay(ptr->next);
  }
}

//recursive reverse display
void reverseRDisplay(struct Node* ptr) {
  if(ptr!=NULL) {
    reverseRDisplay(ptr->next);
    printf("%d ", ptr->data);
  }
}

//count no. of nodes
int countNodes(struct Node* ptr) {
  int count = 0;
  while(ptr!=NULL) {
    count++;
    ptr = ptr->next;
  }
  return count;
}

//count no. of nodes recursively
int RCountNodes(struct Node* ptr) {
  if(ptr == NULL)
    return 0;
  return RCountNodes(ptr->next) +1;
}

//sum of all elements
int sum(struct Node* ptr) {
  int sum = 0;
  while(ptr!=NULL) {
    sum += ptr->data;
    ptr = ptr->next;
  }
  return sum;
}

//recursive sum of all elements
int RSum(struct Node* ptr) {
  if(!ptr)
    return 0;
  return RSum(ptr->next) + ptr->data;
}

//find maximum element
int max(struct Node* ptr) {
  int max = INT_MIN;
  while(ptr!=0) {
    if(ptr->data > max)
      max = ptr->data;
    ptr = ptr->next;
  }
  return max;
}

//recursively find maximum element
int RMax(struct Node* ptr) {
  if(ptr == 0)
    return INT_MIN;
  int x = RMax(ptr->next);
  return x > ptr->data ? x : ptr->data;
}

//searching
struct Node* search(struct Node* ptr, int item) {
  while(ptr!=0) {
    if(ptr->data == item)
      return ptr;
    ptr = ptr->next;
  }
  return NULL;
}

//recursive searching
struct Node* RSearch(struct Node* ptr, int item) {
  if(!ptr)
    return NULL;
  if(ptr->data == item)
    return ptr;
  return RSearch(ptr->next, item);
}

//move to head if found
struct Node* improvedSearch(struct Node* ptr, int item) {
  struct Node* prev = NULL;
  while(ptr!=NULL) {
    if(ptr->data == item) {
      prev->next = ptr->next;
      ptr->next = first;
      first = ptr;
      return ptr;
    }
    prev = ptr;
    ptr = ptr->next;
  }
  return NULL;
}

int main() {
  int A[] = {1,2,3,4,5};
  create(A, 5);
  display(first);
  RDisplay(first);
  printf("\n");
  reverseRDisplay(first);
  printf("\n");
  printf("%d\n",countNodes(first));
  printf("%d\n",RCountNodes(first));
  printf("%d\n",sum(first));
  printf("%d\n",RSum(first));
  printf("%d\n",max(first));
  printf("%d\n",RMax(first));
  struct Node* ptr = search(first, 3);
  printf("%d\n",ptr->data);
  ptr = RSearch(first, 3);
  printf("%d\n",ptr->data);
  ptr = improvedSearch(first, 4);
  display(first);
}
