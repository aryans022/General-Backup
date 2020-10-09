#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node *next;
};

void printList(struct node *n) {
     while (n!=NULL) {
          printf("%d\n", n->data);
          n = n->next;
     }
}

int main() {

     struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));

	head->data = 24;
	head->next = second;

	second->data = 42;
	second->next = third;

	third->data = 242;
	third->next = NULL;

	printList(head);

	return 0;
}
