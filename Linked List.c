#include <stdio.h>
#include <stdlib.h>

struct node {
     int val;
     struct node *next;
};

void printer(struct node *n) {
     while(n != NULL) {
          printf("%d\n", n->val);
          n = n->next;
     }
}

int main() {

     struct node *n1 = NULL, *n2 = NULL, *n3 = NULL;

     n1 = (struct node*)malloc(sizeof(struct node));
     n2 = (struct node*)malloc(sizeof(struct node));
     n3 = (struct node*)malloc(sizeof(struct node));

     n1->val = 10;
     n2->val = 20;
     n3->val = 30;

     n1->next = n2;
     n2->next = n3;
     n3->next = NULL;

     printer(n1);
}
