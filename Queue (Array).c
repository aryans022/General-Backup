#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

struct queue {
     int arr[MAX];
     int front;
     int rear;
};

void addq(struct queue *q, int elem) {

     if (q->rear == MAX) {
          printf("Queue is full\n");
          return;
     }

     q->arr[q->rear] = elem;
     q->rear += 1;

}

int delq(struct queue *q) {

     q->front += 1;

     if (q->front >= q->rear) {
          printf("Queue is empty\n");
          q->rear = 0;
          q->front = -1;
          return 0;
     }

     int x = q->arr[q->front];
     return x;
}

int main() {

     struct queue q;
     q.front = -1;
     q.rear = 0;

     addq(&q, 1);
     addq(&q, 3);
     addq(&q, 4);
     addq(&q, 2);
     addq(&q, 7);
     addq(&q, 6);

     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));
     printf("%d\n", delq(&q));

}
