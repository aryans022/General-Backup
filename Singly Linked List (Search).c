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

int iterSearch(struct node *head, int key) {                                        //iterative method to search for given number

     while (head!=NULL) {
          if (head->data == key)
               return 1;
          else {
               head = head->next;
          }
     }

     return 0;

}

int recurSearch(struct node *head, int key) {

     if (head == NULL) {
          return 0;
     }
     if (head->data == key) {
          return 1;
     }

     return recurSearch(head->next, key);
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
	printf("length = %d\n", recurSearch(head, 3));

}
