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

void frontBackSplit(struct node *head, struct node **front, struct node **back) {

     struct node *slow = head, *fast = head;

     if (head == NULL) {
          *front = NULL;
          *back = NULL;
          return;
     }

     while (slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL) {
          slow = slow->next;
          fast = fast->next->next;
     }

     *back = slow->next;
     slow->next = NULL;
     *front = head;

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
     struct node *front;
     struct node *back;
     head->next = NULL;
     head->data = 7;

     push(&head, 1);
     push(&head, 5);
     push(&head, 3);

     frontBackSplit(head, &front, &back);
     printList(front);
     printList(back);

}
