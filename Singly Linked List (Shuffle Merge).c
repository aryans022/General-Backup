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

struct node* shuffleMerge(struct node *a, struct node *b) {

     struct node *head, *current;

     if (a == NULL) {
          head = b;
          return head;
     }
     else {

          head = a;
          a = a->next;
          current = head;

          int count = 2;

          while (a!=NULL && b!=NULL) {
               if (count%2 == 1) {
                    current->next = a;
                    a = a->next;
                    current = current->next;
                    count++;
               }
               else {
                    current->next = b;
                    b = b->next;
                    current = current->next;
                    count++;
               }
          }

          if (a == NULL) {
               current->next = b;
          }
          else if (b == NULL){
               current->next = a;
          }

          return head;
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

     struct node *x = shuffleMerge(head1, head2);

     printf("x\n");
     printList(x);

}
