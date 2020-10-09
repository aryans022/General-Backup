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

int getNode(struct node *head, int pos) {                                  //returns data at node at required position

     for (int i = 1; i < pos; i++) {                                       //head = 1
          if (head == NULL) {
               break;
          }
          head = head->next;
     }

     if (head != NULL) {
          return head->data;
     }
     else {
          return -1;                                                       //-1 if node not present
     }
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
     printf("%d\n", getNode(head, 5));

}
