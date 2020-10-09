#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct node {                                                             /* node structure */
     int value;
     double key1;
     double key2;
     struct node *next;
     struct node *sort1;
     struct node *sort2;
};
struct node *head = NULL;                                                /* head node */
struct node *sort1_head = NULL;
struct node *sort2_head = NULL;

void input(int num) {                                                     /* creates the linked list */

     int count = 0;                                                       /* number of elements */

     while (count < num) {
          struct node *newnode, *temp;
          newnode = (struct node *)malloc(sizeof(struct node));
          newnode->value = (rand () % (10 -1 + 1)+1 );
          newnode->key1 = ((double) rand() / (double) RAND_MAX)*(50 - 10) + 10.0;
          newnode->key2 = ((double) rand() / (double) RAND_MAX)*(90 - 50) + 50.0;
          newnode->sort1 = NULL;
          newnode->sort2 = NULL;

          if (head == NULL) {                                            /* define head node */
               head = newnode;
               head->next = NULL;
          }

          temp = head;
          while (temp->next != NULL) {                                    /* get to last complete node */
               temp = temp->next;
          }
          temp->next = newnode;                                           /* assign address to last complete node */
          newnode->next = NULL;

          count++;
     }
}

void sort1(int num) {
     struct node *temp, *s1 = NULL, *t1 = NULL;
     temp = head;
     double min = 200, check = 0;

     for (int i = 0; i < num; i++) {
          temp = head;
          min = 200;
          s1 = NULL;

          if (i == 0) {
               while (temp != NULL) {
                    if (min > temp->key1) {
                         s1 = temp;
                         min = temp->key1;
                    }
                    temp = temp->next;
               }
               check = min;
          }
          else {
               while (temp != NULL) {
                    if (min > temp->key1) {
                         if (temp->key1 > check) {
                         s1 = temp;
                         min = temp->key1;
                         }
                    }
                    temp = temp->next;
               }
               check = min;
          }

          if (sort1_head == NULL) {
               sort1_head = s1;
               sort1_head->sort1 = NULL;
          }
          else {
               t1 = sort1_head;

               while (t1->sort1 != NULL) {
                    t1 = t1->sort1;
               }

               t1->sort1 = s1;
          }
     }
}

void sort2(int num) {
     struct node *temp, *s1 = NULL, *t1 = NULL;
     temp = head;
     double min = 200, check = 0;

     for (int i = 0; i < num; i++) {
          temp = head;
          min = 200;
          s1 = NULL;

          if (i == 0) {
               while (temp != NULL) {
                    if (min > temp->key2) {
                         s1 = temp;
                         min = temp->key2;
                    }
                    temp = temp->next;
               }
               check = min;
          }
          else {
               while (temp != NULL) {
                    if (min > temp->key2) {
                         if (temp->key2 > check) {
                         s1 = temp;
                         min = temp->key2;
                         }
                    }
                    temp = temp->next;
               }
               check = min;
          }

          if (sort2_head == NULL) {
               sort2_head = s1;
               sort2_head->sort1 = NULL;
          }
          else {
               t1 = sort2_head;

               while (t1->sort2 != NULL) {
                    t1 = t1->sort2;
               }

               t1->sort2 = s1;
          }
     }
}

void normal(struct node *n) {                                            /* prints the linked list */
     while (n != NULL) {
          printf("<%d, %lf, %lf>\n", n->value, n->key1, n->key2);
          n = n->next;
     }
     printf("\n");
}

void printsort1(struct node *n) {                                            /* prints the linked list */
     while (n != NULL) {
            printf("<%d, %lf, %lf>\n", n->value, n->key1, n->key2);
          n = n->sort1;
     }
     printf("\n");
}

void printsort2(struct node *n) {                                            /*prints the linked list */
     while (n != NULL) {
          printf("<%d, %lf, %lf>\n", n->value, n->key1, n->key2);
          n = n->sort2;
     }
     printf("\n");
}
void change (){
  struct node *temp = head;
  int i = 1;
  while(temp != NULL){
      if ((i%3)==0){
        temp->value = temp->value *10;
      }
    temp = temp->next;
    i++;
  }
}
int main() {

  int b;
     scanf("%d", &b);
printf("\n");

     input(b);


        normal(head);
printf("Now ascending order according to Key1:\n");
        sort1(b);
        printsort1(sort1_head);
printf("Now ascending order according to Key2:\n");
        sort2(b);
        printsort2(sort2_head);
  printf("Now changing every third row value:\n");
  change();
  normal(head);
  printf("Now ascending order according to Key1:\n");
        printsort1(sort1_head);
  printf("Now ascending order according to Key2:\n");
        printsort2(sort2_head);

}
