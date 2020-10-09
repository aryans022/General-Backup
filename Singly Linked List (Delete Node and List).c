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

void deleteKey(struct node **head, int key) {                              //delete node with given key

     struct node *current = *head;                                         //current node

     if (current->data == key) {                                           //check if we have to delete node 1
          *head = current->next;                                           //change new head to second node
          free(current);                                                   //free old head
          return;
     }

     struct node *prev = *head;                                            //previous node
     current = current->next;                                              //move current to node 2

     while (current!=NULL) {                                               //loop to find key
          if (current->data == key) {
               prev->next = current->next;                                 //unlink node to be deleted
               free(current);                                              //free memory space of deleted node
               return;
          }
          prev = current;                                                  //if key not found, change prev and current
          current = current->next;
     }

}

void deletePos(struct node **head, int pos) {                              //delete node at given position (head = 1)

     struct node *current = *head;                                         //current node

     if (pos == 1) {                                                       //check if node to be deleted = head
          *head = current->next;                                           //change head to second node
          free(current);                                                   //free old head
          return;
     }

     struct node *prev = *head;                                            //previous node

     for (int i = 1; i < pos-1; i++) {                                     //loop to get to (pos-1)th node

          prev = prev->next;

          if (prev->next == NULL) {                                        //break if linked list is over
               return;
          }
     }

     current = prev->next;                                                 //fetch node to be deleted
     prev->next = current->next;                                           //unlink current
     free(current);                                                        //free memory from unlinked node

}

void deleteList(struct node **head) {

     struct node *current = *head;
     struct node *next = current->next;

     while (next!=NULL) {
          free(current);
          current = next;
          next = current->next;
     }

     *head = NULL;
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
	deleteList(&head);

	printList(head);

}
