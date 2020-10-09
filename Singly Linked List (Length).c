#include <stdio.h>
#include <stdlib.h>

struct node {                                                              //Basic building block
     int data;
     struct node *next;
};

void push (struct node **head, int new_data) {                             //Add new node to first position (to head of linked list)

     struct node *newnode = (struct node *)malloc(sizeof(struct node));

     newnode->data = new_data;
     newnode->next = *head;

     *head = newnode;
}

int getLength(struct node *head) {                                         //iterative method to get length of linked list

     int i = 0;
     struct node *current = head;

     while (current != NULL) {                                             //same as printList()
          current = current->next;
          i++;
     }

     return i;
}

int getCount(struct node *n) {                                             //recursive method to get length of linked list

     if (n == NULL) {                                                      //end condition
          return 0;
     }

     return 1+getCount(n->next);                                           //keeps adding 1 on each node
}

void printList(struct node *n) {                                           //print linked list

     while(n!=NULL) {
          printf("%d\n", n->data);
          n = n->next;
     }

}

int main() {

	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	head->data = 1;

	push(&head, 6);
	push(&head, 3);
	push(&head, 2);
	push(&head, 7);

	printList(head);
	printf("length = %d\n", getCount(head));

}
