#include <bits/stdc++.h>
using namespace std;

int main() {

     enum days {Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
     int dayNum;

     cout<<"Enter day of the week (1-7)"<<endl;
     cin>>dayNum;
     cout<<"Day "<<dayNum<<" is ";

     switch(dayNum) {
          case Monday: cout<<"Monday"<<endl; break;
          case Tuesday: cout<<"Tuesday"<<endl; break;
          case Wednesday: cout<<"Wednesday"<<endl; break;
          case Thursday: cout<<"Thursday"<<endl; break;
          case Friday: cout<<"Friday"<<endl; break;
          case Saturday: cout<<"Saturday"<<endl; break;
          case Sunday: cout<<"Sunday"<<endl; break;
     }
}
