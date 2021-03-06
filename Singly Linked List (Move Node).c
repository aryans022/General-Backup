#include <assert.h>
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

void moveNode(struct node **dest, struct node **source) {

     struct node *current = *source;
     assert(current != NULL);                                              //library macro that checks statement and displays error on stderr
     *source = current->next;

     current->next = *dest;
     *dest = current;

}

void printList(struct node *n) {                                           //print linked list

     while(n!=NULL) {
          printf("%d\n", n->data);
          n = n->next;
     }

}

int main() {

     struct node *head1 = (struct node *)malloc(sizeof(struct node));
     struct node *head2 = (struct node *)malloc(sizeof(struct node));

     head1->next = NULL;
     head1->data = 7;
     push(&head1, 1);
     push(&head1, 5);
     push(&head1, 3);
     push(&head1, 2);


     head2->next = NULL;
     head2->data = 0;
     push(&head2, 4);
     push(&head2, 6);
     push(&head2, 7);
     push(&head2, 8);

     printf("list1\n");
     printList(head1);

     printf("\nlist2\n");
     printList(head2);

     moveNode(&head1, &head2);

     printf("list1\n");
     printList(head1);

     printf("\nlist2\n");
     printList(head2);

}
