#include <stdio.h>

int main() {

     char str[10000];
     scanf("%[^.]", str);

     int line = 0, word = 0, index = 0, wordline[1000] = {0};

     if (str[0] > 32) {                                     //for first word of first line
          wordline[0] = 1;
     }

     if (str[0] > 32) {                                     //for first word
          word++;
     }

     for (int i = 0; ; i++) {

          if (str[i] == '\n') {                             //for number of lines
               line++;
          }

          if ((str[i] == ' ' || str[i] == '\t') && str[i+1] > 32) {             //for number of words
               word++;
          }
          else if (str[i] == '\n' && str[i+1] > 32) {
               word++;
          }

          if (str[i] == '\n') {                             //for number of words per line
               index++;
          }
          if ((str[i] == ' ' || str[i] == '\t' ) && str[i+1] > 32) {
               wordline[index] += 1;
          }
          else if (str[i] == '\n' && str[i+1] > 32) {
               wordline[index] += 1;
          }


          if (str[i] == '.') {                              //loop exit condition
               break;
          }
     }

     printf("\n\n\nNumber of lines = %d Number of words = %d\n", line, word);
     for (int i = 0; i < line; i++) {
          printf("%d ", wordline[i]);
     }
}
