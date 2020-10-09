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

void moveNode(struct node **dest, struct node **source) {                  //Move node from head of list 2 to head of list 1

     struct node *current = *source;
     assert(current != NULL);                                              //library macro that checks statement and displays error on stderr
     *source = current->next;

     current->next = *dest;
     *dest = current;

}

struct node* sortedIntersect(struct node *a, struct node *b) {                 //gives a list of all common elements if supplied with two lists sorted in ascending order

     struct node *head = NULL;

     while (a!=NULL && b!=NULL) {
          if (a->data == b->data && (head==NULL || head->data != a->data)) {
               push(&head, a->data);
               a = a->next;
          }
          else if (a->data > b->data) {
               b = b->next;
          }
          else if (a->data < b->data) {
               a = a->next;
          }
     }

     return head;

}

void printList(struct node *n) {                                           //print linked list

     while(n!=NULL) {
          printf("%d\n", n->data);
          n = n->next;
     }
     printf("\n");

}

int main() {

     struct node *head1 = (struct node *)malloc(sizeof(struct node));
     struct node *head2 = (struct node *)malloc(sizeof(struct node));

     head1->next = NULL;
     head1->data = 7;
     push(&head1, 5);
     push(&head1, 3);
     push(&head1, 2);
     push(&head1, 0);


     head2->next = NULL;
     head2->data = 8;
     push(&head2, 7);
     push(&head2, 5);
     push(&head2, 3);
     push(&head2, 1);

     printf("list1\n");
     printList(head1);

     printf("\nlist2\n");
     printList(head2);

     struct node *x = sortedIntersect(head1, head2);

     printf("x\n");
     printList(x);

}
