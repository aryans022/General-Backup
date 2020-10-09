#include <bits/stdc++.h>
using namespace std;

int binarySearchHelper(const vector<int>& a, int bot, int top, int x) {

     int mid = (bot+top)/2;

     if(bot>top) {
          return -1;
     }

     if (x == a[mid]) {
          return mid;
     }
     else if (x > a[mid]) {
          return binarySearchHelper(a, mid+1, top, x);
     }
     else {
          return binarySearchHelper(a, bot, mid-1, x);
     }

}

int binarySearch(const vector<int>& a, int x) {
     return binarySearchHelper(a, 0, a.size()-1, x);
}

int linearSearch(const vector<int>& a, int x) {
     for (int i = 0; i < a.size(); i++) {
          if (a[i] == x) {
               return pos;
          }
     }
     return -1;
}

int main() {

     vector<int> a = {1, 3, 5, 6, 8, 11, 23, 56, 67, 123};

     cout<<binarySearch(a, 0)<<endl;
     for (int i = 0; i < a.size(); i++) {
          cout<<binarySearch(a, a[i])<<endl;
     }
     cout<<binarySearch(a, 130)<<endl;
}
