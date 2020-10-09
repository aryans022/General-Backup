#include <stdio.h>
#include <stdlib.h>
int single(int one) {                                       //function to write one digit numbers.
    switch (one) {
        case 0: printf("");
        break;
        case 1: printf("One");
        break;
        case 2: printf("Two");
        break;
        case 3: printf("Three");
        break;
        case 4: printf("Four");
        break;
        case 5: printf("Five");
        break;
        case 6: printf("Six");
        break;
        case 7: printf("Seven");
        break;
        case 8: printf("Eight");
        break;
        case 9: printf("Nine");
        break;
    }
}
int doub(int ten, int one) {                                //function to write tens place of two digit numbers.
    switch (ten) {
        case 0: printf("");
        break;
        case 1:
        {
            switch (one) {
                case 0: printf("Ten");
                break;
                case 1: printf("Eleven");
                break;
                case 2: printf("Twelve");
                break;
                case 3: printf("Thirteen");
                break;
                case 4: printf("Fourteen");
                break;
                case 5: printf("Fifteen");
                break;
                case 6: printf("Sixteen");
                break;
                case 7: printf("Seventeen");
                break;
                case 8: printf("Eighteen");
                break;
                case 9: printf("Nineteen");
                break;
            }
        }
        break;
        case 2: printf("Twenty ");
        break;
        case 3: printf("Thirty ");
        break;
        case 4: printf("Forty ");
        break;
        case 5: printf("Fifty ");
        break;
        case 6: printf("Sixty ");
        break;
        case 7: printf("Seventy ");
        break;
        case 8: printf("Eighty ");
        break;
        case 9: printf("Ninety ");
        break;
    }
}
int hund (int h, int t, int o) {                            //function to print entire three digit number using single and doub. This function can thus help us to write a number upto infinity.
    single(h);
    if(h != 0)
        printf(" Hundred ");
    if(t != 1) {
        doub (t, o);
        single(o);
    }
    else
        doub (t, o);
        }
int main() {                                                //program to print a number (until a billion) into words.
    int copy;
    float num;
    int digits[] = {0, 0, 0, 0, 0, 0, 0};
    printf("Enter a Number (less than 100,000)\n");
    scanf("%f", &num);
    if (num >= 100000 || num < 0) {                                  //error check.
        printf("Number Not in Range..");
        exit(0);
    }
    copy = num*100;                                         //to get the 2 decimal digits into int.
    for (int i = 0; copy > 0; i++) {                        //separate the digits of a number. (can be used to separate int only)
        digits[i] = copy % 10;
        copy = copy / 10;
    }
    hund (0, digits[6], digits[5]);                         //main statements to print the number in the required format.
    if (num > 999)
        printf(" Thousand ");
    hund (digits[4], digits[3], digits[2]);
    if (num != 0 && num > 1)
        printf(" Rupees");
    if (num > 0 && (digits[1] != 0 || digits[0] != 0) && num > 1)
        printf(" and ");
    hund (0, digits[1], digits[0]);
    if (num > 0 && (digits[1] != 0 || digits[0] != 0))
        printf(" Paise ");
}
