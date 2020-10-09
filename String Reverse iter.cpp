#include <bits/stdc++.h>
using namespace std;

void strReverse(string& str) {                                             //iterative function
     int n = str.length();
     char temp;                                                            //temp char for swapping
     for (int i = 0; i < n/2; i++) {                                       //swap each element up to i = n/2
          temp = str[i];
          str[i] = str[n-i-1];
          str[n-i-1] = temp;
     }
}

int main() {

	string str;
	cout<<"Enter String to be reversed"<<endl;
	cin>>str;

	strReverse(str);
	cout<<"Reversed string is "+str<<endl;
}
