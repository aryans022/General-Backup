#include <bits/stdc++.h>
using namespace std;

int main() {

     int n;
     cout<<"Enter Array Size ";
     cin>>n;

     int* arr = new int[n];
     int* temp = new int[n];
     bool flag = true, f1 = true;
     cout<<"Enter Array Values ";

     for (int i = 0; i < n; i++) {
          cin>>arr[i];
     }

     int index = 0;
     for (int i = 0; i < n; i++) {
          flag = true;
          for (int j = 0; j < n; j++) {
               if (i == j) {
                    continue;
               }
               if (arr[i] == arr[j]) {
                    f1 = true;
                    for (int k = 0; k < index; k++) {
                         if (temp[k] == arr[i]) {
                              f1 = false;
                         }
                    }
                    if (!f1)
                         flag = false;
               }
          }
          if (flag) {
               temp[index] = arr[i];
               index++;
          }
     }

     for (int k = 0; k < index; k++) {
          arr[k] = temp[k];
          cout<<arr[k]<<" ";
     }

}
