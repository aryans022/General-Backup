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

void removeDuplicates(struct node *n) {

     struct node *prev = n;
     n = n->next;

     while (n!= NULL) {
          if (prev->data == n->data) {
               prev->next = n->next;
               n = n->next;
          }
          else {
               prev = n;
               n = n->next;
          }
     }

}

void printList(struct node *n) {                                           //print linked list

     while(n!=NULL) {
          printf("%d\n", n->data);
          n = n->next;
     }
     printf("\n");

}

int main() {

     struct node *head = (struct node *)malloc(sizeof(struct node));
     struct node *front;
     struct node *back;
     head->next = NULL;
     head->data = 3;

     push(&head, 3);
     push(&head, 3);
     push(&head, 3);
     push(&head, 5);
     push(&head, 5);
     push(&head, 5);
     push(&head, 5);
     push(&head, 5);
     push(&head, 5);

     printList(head);
     removeDuplicates(head);
     printList(head);

}
