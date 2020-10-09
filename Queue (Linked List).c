#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define EMP -9182

struct node {
     int data;
     struct node *next;
};

struct queue {
     struct node *head;
     struct node *rear;
};

void addq(struct queue *q, int elem) {
     printf("adding %d\n", elem);

     struct node *temp = (struct node*)malloc(sizeof(struct node));
     temp->data = elem;
     temp->next = NULL;

     if (q->rear == NULL) {
          q->rear = temp;
          q->head = temp;
          return;
     }

     q->rear->next = temp;
     q->rear = q->rear->next;

}

int delq(struct queue *q) {

     if (q->head == NULL) {
          printf("Queue is empty\n");
          return EMP;
     }
     printf("deleting element\n");

     struct node *temp = q->head;
     q->head = q->head->next;

     int elem = temp->data;
     free(temp);
     return elem;
}

int main() {

     struct queue q;
     q.rear = NULL;
     q.head = NULL;
     int i;

     addq(&q, 1);
     addq(&q, 3);
     addq(&q, 4);
     addq(&q, 2);
     addq(&q, 7);
     addq(&q, 6);
     printf("\n");

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);

     i = delq(&q);
     if (i != EMP)
          printf("%d\n\n", i);
}
