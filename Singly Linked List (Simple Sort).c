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

void sortedInsert (struct node **head, int new_data) {                     //insert new node with data at sorted position in sorted list

     struct node *newnode = (struct node *)malloc(sizeof(struct node));    //create new node
     struct node *current = *head;

     newnode->data = new_data;

     if (current == NULL || new_data <= current->data) {                   //if no nodes initially or key<head_data, head = new node
          newnode->next = current;
          *head = newnode;
          return;
     }

     struct node *prev = *head;                                            //previous node
     current = current->next;

     while (current != NULL) {
          if (new_data <= current->data) {                                 //if condition satisfied, insert node at this position
               prev->next = newnode;
               newnode->next = current;
               return;
          }
          prev = current;                                                  //increment prev and current otherwise
          current = current->next;
     }

     if (current == NULL) {                                                //if current is null, it means that key>all elements
          prev->next = newnode;                                            //thus, insert new node at the end of linked list
          newnode->next = NULL;
     }
}

void insertSort (struct node **head) {                                     //sort the linked list by creating a new one and using sorted insert for each value of key

     struct node *new_head = NULL;                                         //head of new linked list
     struct node *current = *head;                                         //current node
     struct node *prev = *head;                                            //previous node(to free memory)

     while (current != NULL) {
          sortedInsert(&new_head, current->data);                          //insert new node at correct position
          prev = current;
          current = current->next;
          free(prev);
     }

     *head = new_head;                                                     //change original head to new head
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
     head->data = 7;

     push(&head, 1);
     push(&head, 5);
     push(&head, 3);
     push(&head, 2);
     push(&head, 4);
     push(&head, 6);
     push(&head, 7);
     push(&head, 8);

     insertSort(&head);

     printList(head);

}
