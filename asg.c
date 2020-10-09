#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int file_size(FILE *ab);
char **read_words(FILE *bc);
void printwords( char **ar );
int alphabetical_word_count(char **ar);
char* substr(const char *src, int m, int n);
void print_alphabetical_word_count(int *ar);
   int word_count[25];

int main (){
  int j=10;
  int i = 0;
 int t=0;
 int count;

  FILE *fp;
  char **names1;


  if ((fp = fopen("a1_words.txt","r")) == NULL) {
    printf("Error couldnt open file\n");
    j= file_size(fp);
  } else {
    printf("File Opened\n");
  }
  names1 = read_words(fp);


printwords(names1);
alphabetical_word_count(names1);
print_alphabetical_word_count(word_count);

return(0);
}

int file_size(FILE *ab){
 int sz=0;
 fseek(ab, 0L, SEEK_END);
 sz = ftell(ab);
 rewind(ab);
 return sz;
}

char **read_words(FILE *fp){

  char **wordArray;
  char word1[45];
  int i = 0;
  int t = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  int o = 0;
  int j =0;
  int bytes = ((file_size(fp)/2));
  wordArray = malloc(sizeof(char *) * (file_size(fp)/2));
  while (fscanf(fp,"%s",word1)!= EOF) {

    wordArray[i] = malloc(sizeof(char) * strlen(word1));

    strcpy(wordArray[i],word1);


    i++;
  }


wordArray[i] = NULL;
return wordArray;

}

void printwords( char **ar ){

int i=0;
  for (i=0;i<1000000;i++){
  if (ar[i]==NULL){
    break;
  }
printf("%s\n",ar[i]);

}
printf("%d\n",i);
i=0;
}

char* substr(const char *src, int m, int n) {
   int i;
	int len = n - m;


	char *dest = (char*)malloc(sizeof(char) * (len + 1));


	for ( i = m; i < n && (*src != '\0'); i++)
	{
		*dest = *(src + i);
		dest++;
	}


	*dest = '\0';


	return dest - len;
}

int alphabetical_word_count(char **ar){
int i=0;
int j=0;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
int count6=0;
int count7=0;
int count8=0;
int count9=0;
int count10=0;
int count11=0;
int count12=0;
int count13=0;
int count14=0;
int count15=0;
int count16=0;
int count17=0;
int count18=0;
int count19=0;
int count20=0;
int count21=0;
int count22=0;
int count23=0;
int count24=0;
int count25=0;
int count26=0;
char words[1];
char *dest;
int t;
FILE *fp;

printf("\n\n\n");

while(1){



if (ar[i]== NULL){

   break;
  }
  strcpy(words,ar[i]);

  dest=substr(words,0,1);


  if (*dest == 'a'|| *dest =='A'){

       count1++;
}
  if (*dest == 'b'|| *dest =='B')
  {
       count2++;

 }
  if (*dest == 'c'|| *dest =='C')
  {
       count3++;

  }
  if (*dest == 'd'||*dest =='D')
  {
       count4++;

  }
  if (*dest == 'e'||*dest =='E')
  {
       count5++;

  }
  if (*dest == 'f'||*dest =='F')
  {
       count6++;

  }
  if (*dest == 'g'||*dest =='G')
  {
       count7++;

  }
  if (*dest == 'h'||*dest =='H')
  {
       count8++;

  }
  if (*dest == 'i'||*dest =='I')
  {
       count9++;

  }
  if (*dest == 'j'||*dest =='J')
  {
       count10++;

  }if (*dest == 'k'||*dest =='K')
  {
       count11++;

  }if (*dest == 'l'||*dest =='L')
  {
       count12++;

  }if (*dest == 'm'||*dest =='M')
  {
       count13++;

  }if (*dest == 'n'||*dest =='N')
  {
       count14++;

  }if (*dest == 'o'||*dest =='O')
  {
       count15++;

  }if (*dest == 'p'||*dest =='P')
  {
       count16++;

  }if (*dest == 'q'||*dest =='Q')
  {
       count17++;

  }if (*dest == 'r'||*dest =='R')
  {
       count18++;

  }if (*dest == 's'||*dest =='S')
  {
       count19++;

  }if (*dest == 't'||*dest =='T')
  {
       count20++;

  }if (*dest == 'u'||*dest =='U')
  {
       count21++;

  }if (*dest == 'v'||*dest =='V')
  {
       count22++;

  }if (*dest == 'w'||*dest =='W')
  {
       count23++;

  }if (*dest == 'x'||*dest =='X')
  {
       count24++;

  }if (*dest == 'y'||*dest =='Y')
  {
       count25++;

  }
  if (*dest == 'z'||*dest =='Z')
  {
       count26++;

  }
i++;

}


word_count[0] = count1;
word_count[1] = count2;
word_count[2] = count3;
word_count[3] = count4;
word_count[4] = count5;
word_count[5] = count6;word_count[6] = count7;

word_count[7] = count8;
word_count[8] = count9;
word_count[9] = count10;
word_count[10] = count11;
word_count[11] = count12;
word_count[12] = count13;
word_count[13] = count14;word_count[14] = count15;word_count[15] = count16;
word_count[16] = count17;word_count[17] = count18;word_count[18] = count19;
word_count[19] = count20;word_count[20] = count21;word_count[21] = count22;word_count[22] = count23;
word_count[23] = count24;word_count[24] = count25;word_count[25] = count26;
return word_count[0];

}

void print_alphabetical_word_count(int *ar){
int i;
  for(i=0;i<26;i++){
    printf("%d\n",*(word_count + i));

  }


}
