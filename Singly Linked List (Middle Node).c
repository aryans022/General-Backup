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

int getMidNode(struct node *head) {                                 //returns data at node at nth node from end

     struct node *ref = head->next;

     while (ref != NULL) {
          ref = ref->next;
          if(ref!=NULL) {
               ref = ref->next;
          }
          head = head->next;
     }
     return head->data;

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

     printList(head);
     printf("%d\n", getMidNode(head));

}
