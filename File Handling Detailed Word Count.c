#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filesize(FILE *fp) {                                        //function to compute file size.
     int sz = 0;
     fseek(fp, 0L, SEEK_END);
     sz = ftell(fp);
     rewind(fp);
     return sz;
}

char **readwords(FILE *fp) {                                    //function to read individual words.

     int size = 0;
     int i = 0;
     size = filesize(fp)/2;                                     //max number of words.

     char **w;                                                  //pointer to the array
     w = malloc( size * sizeof(int *));
     for (int i = 0; i < size; i++) {
          w[i] = malloc(45);                                    //word strings
     }

     while (fscanf(fp, "%s", w[i]) != EOF) {                    //loop to read all words
          i++;
     }

     w[i] = NULL;

     return w;
}

void printwords(char **toprint) {                               //function to print individual words.
     for (int i = 0; toprint[i] != NULL ; i++) {
          printf("%s\n", toprint[i]);
     }
}

int *alphabeticalwordcount(char **wc) {                         //function to count number of words starting with each alphabet
     int *awc;
     awc = calloc(26, sizeof(int *));
     int x;

     for (int i = 0; wc[i] != NULL; i++) {
          if (wc[i][0] >= 65 && wc[i][0] <= 90) {
               x = wc[i][0] - 65;
               awc[x]++;
          }
          else if(wc[i][0] >= 97 && wc[i][0] <= 122) {
               x = wc[i][0] - 97;
               awc[x]++;
          }
     }

     return awc;
}

void printalphabeticalwordcount(int *awc) {                     //function to print number of words starting with each alphabet
     for (int z = 0; z < 26; z++) {
          printf("%c=%d ", z + 65, awc[z]);
     }
}

char ***alphabeticalarray(char **w, int *acount) {              //function to sort words according to starting letter

     char ***sortedwords;                                       //array of array of words starting from a particular letter
     int count[26] = {0};
     int x, c = 0;

     sortedwords = calloc(26, sizeof(int **));                  //for 26 letters

     for (int i = 0; i < 26; i++) {
          sortedwords[i] = calloc(acount[i] + 1, sizeof(int *)); //for acount words + NULL character
          for (int j = 0; j < acount[i]; j++) {
               sortedwords[i][j] = calloc(45, sizeof(char));     //for max 45 char limit
          }
     }

     for (int i = 0; w[i] != NULL; i++) {                       //sorting loops

          if (w[i][0] >= 65 && w[i][0] <= 90) {
               x = w[i][0] - 65;
               c = count[x];
               strcpy(sortedwords[x][c], w[i]);
               count[x]++;
          }

          else if(w[i][0] >= 97 && w[i][0] <= 122) {
               x = w[i][0] - 97;
               c = count[x];
               strcpy(sortedwords[x][c], w[i]);
               count[x]++;
          }
     }

     for (int i = 0; i < 26; i++) {
          c = count[i];
          sortedwords[i][c] = NULL;
     }


     return sortedwords;
}

void print_words_alphabetically(char ***a) {                    //function to print sorted words

     for (int i = 0; i < 26; i++) {
          if(a[i][0] != NULL) {
               printf("%c\n", 65+i);
          }

          for (int j = 0; a[i][j] != NULL; j++) {
               printf("%s\n", a[i][j]);
          }

          if(a[i][0] != NULL) {
               printf("\n");
          }
     }
}

int main() {

     FILE *f1;
     int *a;
     char **word;
     char ***sortedw;

     f1 = fopen("test.txt", "r+");

     if (f1 == NULL) {                                          //file validation
          printf("Couldn't open file.\n\n");
     }
     else {
          printf("File Opened.\n\n");
     }

     word = readwords(f1);
     printwords(word);
     printf("\n");

     a = alphabeticalwordcount(word);
     printalphabeticalwordcount(a);
     printf("\n\n");

     sortedw = alphabeticalarray(word, a);
     print_words_alphabetically(sortedw);

}
