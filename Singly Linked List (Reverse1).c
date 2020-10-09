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

void reverse(struct node **head) {                                         //reverses given list

     struct node *back = NULL;
     struct node *curr = *head;
     struct node *front = curr->next;

     while (front != NULL) {
          curr->next = back;
          back = curr;
          curr = front;
          front = front->next;
     }

     curr->next = back;
     *head = curr;
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
     head->next = NULL;
     head->data = 7;

     push(&head, 1);
     push(&head, 5);
     push(&head, 3);
     push(&head, 2);
     push(&head, 4);
     push(&head, 6);
     push(&head, 7);
     push(&head, 8);

     printList(head);

     reverse(&head);

     printList(head);

}
