#include <bits/stdc++.h>
using namespace std;

void toh3(stack<int>& dest) {

     stack<int> source;
     source.push(3);
     source.push(2);
     source.push(1);

     stack<int> aux;

     dest.push(source.top());
     source.pop();

     aux.push(source.top());
     source.pop();

     aux.push(dest.top());
     dest.pop();

     dest.push(source.top());
     source.pop();

     source.push(aux.top());
     aux.pop();

     dest.push(aux.top());
     aux.pop();

     dest.push(source.top());
     source.pop();

     while (!source.empty()) {
          cout<<source.top()<<" ";
          source.pop();
     }
     while (!aux.empty()) {
          cout<<aux.top()<<" ";
          aux.pop();
     }
}

int main() {

     stack<int> dest;

	toh3(dest) ;

     while (!dest.empty()) {
          cout<<dest.top()<<" ";
          dest.pop();
     }
}
