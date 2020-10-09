#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct date {                                                                   //date format
     int day;
     int month;
     int year;
};

int montherr(int sm, int em, int sy, int ey) {                                                    //number of days to be added for each month
     int err = 0, s=sm, e=em;
     for (; sy<ey; sm++) {
          if (sm>12) {
               sm-=12;
               sy++;
               s=1;
          }
          if (sm==4 || sm==6 || sm==9 || sm==11)
               err-=1;
          else if (sm==2 && sy%4==0)
               err-=2;
          else if (sm==2)
               err-=3;

     }
     for (; s<e; s++) {
         if (s==4 || s==6 || s==9 || s==11)
               err-=1;
          if (s==2)
               err-=3;
     }
     return err;
}
int main() {
     struct date start, end;                                                    //variable declaration
     int days, lastday, months, years, monerr, numdays = 0;
     char e[7];

     printf("type \"include\" if you want to include last day\n");
     scanf("%s", e);                                                            //to include last day or not
     lastday = strcmp("include", e);
     if(lastday == 0) {
          numdays += 1 ;
     }

     start.day = 3;                                                            //entered dates
     start.month = 10;
     start.year = 2005;
     printf("\nStarting Date: %d/%d/%d\n\n", start.day, start.month, start.year);

     end.day = 24;
     end.month = 6;
     end.year = 2021;
     printf("Ending Date: %d/%d/%d\n\n", end.day, end.month, end.year);

     if(start.year>end.year || (start.year==end.year && start.month>end.month)  //error check
         || (start.year==end.year && start.month==end.month && start.day>end.day)) {
          printf("Wrong dates have been entered. Malfunction! Malfunction!\n");
          exit(0);
     }
     monerr = montherr(start.month, end.month, start.year, end.year);                                 //actual answer
     days = end.day - start.day;
     years = end.year - start.year;
     months = (end.month+years*12) - start.month;
     numdays += days + months*31 + monerr;

     printf("The number of days between the given dates: %d\n", numdays);
}
