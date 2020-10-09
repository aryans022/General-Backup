#include <bits/stdc++.h>
using namespace std;

void solveHanoiHelper(int len, char source, char aux, char dest) {

     if (len == 1) {

          cout<<"Move from "<<source<<" to "<<dest<<endl;

     }
     else {
          solveHanoiHelper(len-1, source, dest, aux);

          cout<<"Move from "<<source<<" to "<<dest<<endl;

          solveHanoiHelper(len-1, aux, source, dest);
     }
}

void solveHanoi(int a) {

     solveHanoiHelper(a, 'a', 'b', 'c');
}


int main() {

     int a = 1;
     cin>>a;

     solveHanoi(a);

}
