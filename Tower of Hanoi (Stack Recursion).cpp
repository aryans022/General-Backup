#include <bits/stdc++.h>
using namespace std;

void solveHanoi(int n, stack<int>& source, stack<int>& aux, stack<int>& dest) {

     if (n == 1) {

          int temp = source.top();
          source.pop();
          dest.push(temp);

     }
     else {
          solveHanoi(n-1, source, dest, aux);

          int temp = source.top();
          source.pop();
          dest.push(temp);

          solveHanoi(n-1, aux, source, dest);
     }
}


int main() {

     int n = 1;
     cin>>n;

     stack<int> source, aux, dest;
     for (int i = n; i > 0; i--) {
          source.push(i);
     }

     solveHanoi(n, source, aux, dest);
     for (int i = n; i > 0; i--) {
          cout<<dest.top()<<" ";
          dest.pop();
     }

}
