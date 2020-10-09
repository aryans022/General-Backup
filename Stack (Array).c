#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

struct stack {
     int arr[MAX];
     int top;
};

void push(struct stack *s, int elem) {

     if (s->top == MAX-1) {
          printf("Stack is full\n");
          return;
     }

     s->top += 1;
     s->arr[s->top] = elem;
}

int pop(struct stack *s) {

     if (s->top == -1) {
          printf("Stack is empty\n");
          return 0;
     }

     s->top -= 1;
     return s->arr[(s->top)+1];
}

int main() {

     struct stack s;
     s.top = -1;

     push(&s, 5);
     push(&s, 3);
     push(&s, 6);
     push(&s, 2);

     printf("%d\n", pop(&s));
     printf("%d\n", pop(&s));
     printf("%d\n", pop(&s));
     printf("%d\n", pop(&s));
     printf("%d\n", pop(&s));
}
