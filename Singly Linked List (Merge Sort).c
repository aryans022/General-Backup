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

struct node* sortedMerge(struct node *a, struct node *b) {                 //merge 2 sorted linked lists to give one combined sorted list

     struct node *head = a, *current = a;

     if (current == NULL) {
          return b;
     }

     while (b!=NULL) {
          if (current->next == NULL) {                                     //agar b->data is greater than all data in head
               current->next = b;
               break;
          }
          else if (b->data < head->data) {                                 //agar first element se chhota
               moveNode(&head, &b);
               current = head;
          }
          else if ((current->next)->data > b->data) {                      //actual sorted insert
               moveNode(&(current->next), &b);
          }
          else {                                                           //move to next element if current->data > b->data
               current = current->next;
          }
     }
     return head;

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

void mergeSort(struct node **head) {

     struct node *h = *head;
     struct node *h1, *h2;

     if (h == NULL || h->next == NULL) {
          return;
     }

     frontBackSplit(h, &h1, &h2);

     mergeSort(&h1);
     mergeSort(&h2);

     *head = sortedMerge(h1, h2);

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
     head2->data = 0;
     push(&head2, 4);
     push(&head2, 6);
     push(&head2, 7);
     push(&head2, 8);

     printf("list1\n");
     printList(head1);

     printf("\nlist2\n");
     printList(head2);

     mergeSort(&head2);

     printf("x\n");
     printList(head2);

}
