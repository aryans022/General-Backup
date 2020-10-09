#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define EMP -9182

struct node {
     int data;
     struct node *next;
};

void push(struct node **head, int elem) {

     printf("pushed %d\n", elem);

     struct node *temp = (struct node*)malloc(sizeof(struct node));
     temp->data = elem;

     temp->next = *head;
     *head = temp;

}

int pop(struct node **head) {

     if (*head == NULL) {
          printf("Stack is empty\n");
          return EMP;
     }

     printf("popping element\n");
     struct node *temp = *head;
     int data = temp->data;
     *head = (*head)->next;

     free(temp);
     return data;

}

int main() {

     struct node *head = NULL;
     int i;

     push(&head, 5);
     push(&head, 3);
     push(&head, 6);
     push(&head, 2);
     printf("\n");

     i = pop(&head);
     if (i != EMP) {
          printf("%d\n\n", i);
     }

     i = pop(&head);
     if (i != EMP) {
          printf("%d\n\n", i);
     }

     i = pop(&head);
     if (i != EMP) {
          printf("%d\n\n", i);
     }

     i = pop(&head);
     if (i != EMP) {
          printf("%d\n\n", i);
     }

     i = pop(&head);
     if (i != EMP) {
          printf("%d\n\n", i);
     }
}
