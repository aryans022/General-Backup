#include <bits/stdc++.h>
using namespace std;

int fibonacci(int len) {
     if (len <= 1) {
          return len;
     }
     return fibonacci(len-2)+fibonacci(len-1);
}

int main() {

     int n, a = 0, b = 1, temp;
     cin>>n;
     for (int i = 0; i < n; i++)
          cout<<fibonacci(i)<<" ";
}
