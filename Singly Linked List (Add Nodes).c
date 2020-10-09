#include <stdio.h>
#include <stdlib.h>

struct node{
     int data;
     struct node *next;
};

void push (struct node **old_head, int new_data) {

     printf("pushing %d\n", new_data);

     struct node *newnode;
     newnode = (struct node*)malloc(sizeof(struct node));

     newnode->data = new_data;
     newnode->next = *old_head;

     *old_head = newnode;

}

void insertAfter(struct node *head, int pos, int new_data) {     //head = 1

     printf("inserting %d after %d position\n", new_data, pos);

     for (int i = 1; i < pos; i++) {
          if (head != NULL)
               head = head->next;
          else
               break;
     }

     if (head == NULL)  {
          printf("previous node can't be NULL");
          return;
     }

     struct node *newnode = (struct node*)malloc(sizeof(struct node));

     newnode->data = new_data;
     newnode->next = head->next;

     head->next = newnode;

}

void append(struct node *head, int new_data) {

     printf("appending %d at end of list\n", new_data);

     struct node *newnode = (struct node*)malloc(sizeof(struct node));

     newnode->data = new_data;
     newnode->next = NULL;

     struct node *last = head;

     if (head == NULL) {
          head = newnode;
          return;
     }

     while(last->next != NULL) {
          last = last->next;
     }

     last->next = newnode;
}
void deletePos(struct node **head, int pos) { //head = 1

     printf("deleting element at pos %d\n", pos);

     struct node *current = *head;

     if (pos == 1) {
          *head = current->next;
          free(current);
          return;
     }

     struct node *prev = *head;

     for (int i = 1; i < pos-1; i++) {

          prev = prev->next;

          if (prev->next == NULL) {
               return;
          }
     }

     current = prev->next;
     prev->next = current->next;
     free(current);

}

void deleteList(struct node **head) {

     printf("Deleting list\n");

     struct node *current = *head;
     struct node *next = current->next;

     while (next!=NULL) {
          free(current);
          current = next;
          next = current->next;
     }

     *head = NULL;
}

void printList(struct node *n) {
     if (n == NULL) {
          printf("List is empty");
     }
     while (n != NULL) {
          printf("%d ", n->data);
          n = n->next;
     }
     printf("\n\n");
}

int main() {
     struct node *head = NULL;

     push(&head, 2);
     printList(head);

     append(head, 5);
     printList(head);

     insertAfter(head, 1, 4);
     printList(head);

     insertAfter(head, 2, 8);
     printList(head);

     insertAfter(head, 1, 2);
     printList(head);

     deletePos(&head, 3);
     printList(head);

     append(head, 7);
     printList(head);

     deleteList(&head);
     printList(head);
}
