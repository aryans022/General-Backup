#include <bits/stdc++.h>
using namespace std;

int main() {

     string initial, required;
     cout<<"Enter string to be edited: ";
     cin>>initial;

     for (int i = 0; i < initial.length(); i++) {
          if (initial[i] >= 65 && initial[i] <= 90)
               required += initial[i];
          else if (initial[i] >= 97 && initial[i] <= 122)
               required += initial[i];
     }
     initial = required;

     cout<<"Edited String is: "<<initial<<endl;
}
