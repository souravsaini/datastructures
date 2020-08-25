#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
  int data;
  struct Node *next;
}*first=NULL,*last=NULL;

//create temporary linked list
void create(int A[], int n) {
  struct Node *temp;
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

//insertion of node at given position
void insert(int pos, int item) {
  if(first == NULL) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;
    first = last = temp;
  }
  else if(pos == 0) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = first;
    first = temp;
  } else {
    struct Node* ptr = first;
    for(int i=0; i<pos-1 && ptr; i++)
      ptr = ptr->next;
    if(ptr) {
      struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
      temp->data = item;
      temp->next = ptr->next;
      if(ptr->next == NULL)
        last = temp;
      ptr->next = temp;
    }
  }
}

//append the node
void append(int item) {
  if(first == NULL) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;
    first = last = temp;
  } else {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = item;
    last->next = temp;
    temp->next = NULL;
    last = temp;
  }
}

//delete the node for given position
int delete(int pos) {
  if(pos == 0) {
    struct Node* ptr = first;
    first = first->next;
    int item = ptr->data;
    free(ptr);
    return item;
  }
  else {
    struct Node* curr = first;
    struct Node* prev = NULL;
    for(int i=0; i<pos && curr; i++) {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    int item = curr->data;
    free(curr);
    return item;
  }
}

//remove duplicates from the list
void removeDuplicates(struct Node* p) {
  struct Node* q = p->next;
  while(q!=NULL) {
    if(p->data != q->data) {
      p = q;
      q = q->next;
    }
    else {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

//reverse linked list using sliding pointers
void reverseList(struct Node* p) {
  struct Node *q = NULL, *r = NULL;
  while(p!=NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

//recursively reverse linked list
void RReverseList(struct Node* q, struct Node* p) {
  if(p!=NULL) {
    RReverseList(p, p->next);
    p->next = q;
  }
  else
    first = q;
}

//find loop in the list
int isLoop(struct Node* ptr) {
  struct Node *p, *q;
  p = q = ptr;
  do {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while(p && q && p!=q);
  if(p==q)
    return 1;
  return 0;
}

int main() {
  int A[] = {1,2,2,5,5};
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
  if(ptr)
    printf("%d\n",ptr->data);
  ptr = RSearch(first, 3);
  if(ptr)
    printf("%d\n",ptr->data);
  if(ptr)
    ptr = improvedSearch(first, 4);
  display(first);
  insert(0, 6);
  insert(3,6);
  insert(7,9);
  display(first);
  append(9);
  append(9);
  display(first);
  delete(0);
  display(first);
  delete(3);
  display(first);
  delete(7);
  display(first);
  removeDuplicates(first);
  display(first);
  reverseList(first);
  display(first);
  RReverseList(NULL, first);
  display(first);
  printf("%d\n",isLoop(first));
}
