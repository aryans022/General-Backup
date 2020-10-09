#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

struct queue {
     int arr[MAX];
     int front;
     int rear;
};

void begq(struct queue *q, int elem) {

     if (q->rear == MAX-1 && q->front == -1) {
          printf("Queue is full\n");
          return;
     }

     if (q->front == -1 && q->rear == -1){
          q->front = 0;
          q->rear = 0;
          q->arr[q->front] = elem;
     }
     else if (q->front != 0) {
          q->front--;
          q->arr[q->front] = elem;
     }
     else {
          for (int i = q->rear; i >= 0; i++) {
               q->arr[i+1] = q->rear[i];
          }
          q->arr[q->front] = elem;
     }

}

int delqbeg(struct queue *q) {

     q->front += 1;

     if (q->front >= q->rear) {
          printf("Queue is empty\n");
          q->rear = -1;
          q->front = -1;
          return 0;
     }

     int x = q->arr[q->front];
     return x;
}

int main() {

     struct queue q;
     q.front = -1;
     q.rear = -1;

     endq(&q, 1);
     begq(&q, 3);
     begq(&q, 4);
     begq(&q, 2);
     begq(&q, 7);
     endq(&q, 6);

     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));
     printf("%d\n", delqbeg(&q));

}
