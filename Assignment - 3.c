 #include <stdio.h>

//part1
int letter_count(char *a) {                                          //return number of alphabets in the string

     int counter = 0;

     for (int i = 0; a[i] != '\0'; i++){

          if (a[i] >= 65 && a[i] <= 90) {
               counter++;
          }

          if (a[i] >= 97 && a[i] <= 122) {
               counter++;
          }

     }
     return counter;
}

//part1
int * frequency_table(char *a) {                                     //return array of frequencies of alphabets

     static int freq[26];

     for (int i = 0; i < 26; i++) {
          for (int j = 0; a[j] != '\0'; j++) {
               if (a[j] == (65+i) || a[j] == (97+i))
                    freq[i]++;
          }
     }
     return freq;
}

//part2
int offset(char c) {                                                 //letter number with a being 0
     if (c >= 65 && c <= 90) {
          return (c - 65);
     }

     if (c >= 97 && c <= 122) {
          return (c - 97);
     }

}

int main() {

     const float EF[26] = {
          0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
          0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
          0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987,
          0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
          0.01974, 0.00074
          };
	char test[1000];
	int lettercount;
     int *text_freq;

	fgets(test, 1000, stdin);

     lettercount = letter_count(test);
     text_freq = frequency_table(test);

     printf("Number of Letter = %d\n", lettercount);

     for (int i = 0; i < 26; i++) {
          printf("%c = %d\n", 65+i, frequency[i]);
     }
}
