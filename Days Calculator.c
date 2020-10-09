#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define today "12-12-2019"

struct date {                                                                                  //date format
     int day;
     int month;
     int year;
};

int montherr(int sm, int em, int sy, int ey) {                                                 //number of days to be subtracted for each month
     int err = 0, s=sm, e=em;
     for (; sy<ey; sm++) {                                                                     //for years between the start and end year
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
     for (; s<e; s++) {                                                                        //for current year
         if (s==4 || s==6 || s==9 || s==11)
               err-=1;
          if (s==2)
               err-=3;
     }
     return err;
}

int main() {
     struct date start, end;                                                                   //variable declaration
     int days, lastday, months, years, monerr, numdays = 0;
     char e[7];
     char  startdate[10] = "03-10-2005";                                                       //enter dates here
     char enddate[10] = today;
     char a[3], b[5];

     printf("type \"include\" if you want to include last day\n");
     scanf("%s", e);                                                                           //to include last day or not
     lastday = strcmp("include", e);
     if(lastday == 0) {
          numdays += 1 ;
     }

     start.day = atoi(strncpy(a, startdate, 2));                                               //dates to integers that can be worked upon
     start.month = atoi(strncpy(a, startdate+3, 2));
     start.year = atoi(strncpy(b, startdate+6, 4));
     printf("\nStarting Date: %d/%d/%d\n\n", start.day, start.month, start.year);

     end.day = atoi(strncpy(a, enddate, 2));
     end.month = atoi(strncpy(a, enddate+3, 2));
     end.year = atoi(strncpy(b, enddate+6, 4));
     printf("Ending Date: %d/%d/%d\n\n", end.day, end.month, end.year);

     if(start.year>end.year || (start.year==end.year && start.month>end.month)                 //error check
         || (start.year==end.year && start.month==end.month && start.day>end.day)) {
          printf("Wrong dates have been entered. Malfunction! Malfunction!\n");
          exit(0);
     }
     monerr = montherr(start.month, end.month, start.year, end.year);                          //actual answer
     days = end.day - start.day;
     years = end.year - start.year;
     months = (end.month+years*12) - start.month;
     numdays += days + months*31 + monerr;

     printf("The number of days between the given dates: %d days\n", numdays);
}
