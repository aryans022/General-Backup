#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
#define EMP -9999

struct queue {
     int arr[MAX];
     int front;
     int rear;
};

void addq(struct queue *q, int elem) {

     if ((q->rear == MAX-1 && q->front == 0) || (q->rear+1 == q->front)) {
          printf("Queue is full\n\n");
          return;
     }

     if (q->rear == MAX-1) {
          q->rear = -1;
     }
     if (q->front == -1) {
          q->front = 0;
     }

     q->rear++;
     q->arr[q->rear] = elem;

     printf("Added %d\n\n", elem);
}

int delq(struct queue *q) {

     if ((q->front == -1 && q->rear == -1)) {
          printf("Queue is empty\n\n");
          return EMP;
     }

     if (q->front == MAX) {
          q->front = 0;
     }

     int d = q->arr[q->front];

     if (q->front == q->rear) {
          q->front = -1;
          q->rear = -1;
     }
     else {
          q->front++;
     }
     printf("removed %d\n\n", d);
     return d;
}

void display(int *arr) {
     for (int i = 0; i < MAX; i++) {
          printf("%d ",arr[i]);
     }
     printf("\n");
}

int main() {

     char check = 'y';
     int curr;
     struct queue q;
     q.front = -1;
     q.rear = -1;

     printf("Enter\n1 to enqueue\n2 to dequeue\n\n");

     do {
          printf("Enter current operation: ");
          scanf("%d", &curr);

          if (curr == 1) {
               int x;
               printf("Enter number to push: ");
               scanf("%d", &x);
               addq(&q, x);
          }
          else if (curr == 2) {
               delq(&q);
          }

          printf("Enter n to exit loop and y to do more operations: ");
          getc(stdin);
          scanf("%c", &check);
          printf("\n");

     }
     while (check == 'y');

}
