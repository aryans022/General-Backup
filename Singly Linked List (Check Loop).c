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

int checkLoop(struct node *head) {                                         //checks if a loop is present in the linked list

     struct node *fast = head, *slow = head;                               //fast travels 2 nodes, slow 1 node

     while (slow != NULL && fast != NULL && fast->next != NULL) {          //while all can travel
          slow = slow->next;                                               //move slow
          fast = fast->next->next;                                         //move fast 2 spaces
          if (slow == fast) {                                              //slow and fast will meet if there is a loop
               return 1;
          }
     }

     return 0;
}

void printList(struct node *n) {                                           //print linked list (can't print list cuz loop)

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
     head->next->next = head;

     printf("%d\n", checkLoop(head));

}
