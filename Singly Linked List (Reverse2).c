#include <stdio.h>
#include <assert.h>
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

void moveNode(struct node **dest, struct node **source) {

     struct node *current = *source;
     assert(current != NULL);                                              //library macro that checks statement and displays error on stderr
     *source = current->next;

     current->next = *dest;
     *dest = current;

}

void reverse(struct node **head) {                                         //reverses given list

     struct node *curr = NULL;

     while (*head!=NULL) {
          moveNode(&curr, head);
     }

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
