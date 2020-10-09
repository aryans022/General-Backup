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

void alternatingSplit(struct node *head, struct node **odd, struct node **even) {

     struct node *toMove = head;

     if (head == NULL) {
          *odd = NULL;
          *even = NULL;
          return;
     }

     for (int i = 1; head != NULL; i++) {
          if (i%2 == 1)
               moveNode(odd, &head);
          else
               moveNode(even, &head);
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
     struct node *odd = NULL;
     struct node *even = NULL;
     head->next = NULL;
     head->data = 7;

     push(&head, 1);
     push(&head, 5);
     push(&head, 3);

     printList(head);

     alternatingSplit(head, &odd, &even);
     printList(odd);
     printList(even);

}
