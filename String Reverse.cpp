#include <bits/stdc++.h>
using namespace std;

void strReverse(string& str) {                                            //recursive function

     if (str == "") {                                                     //start adding str[0] when we have emptied string
          return;
     }

     char rem = str[0];                                                   //storing char to be added on return
     str = str.substr(1);                                                 //for next recursive call

     strReverse(str);                                                     //to empty string

     str += rem;
}

int main() {

	string str;
	cin>>str;

	strReverse(str);
	cout<<str<<"\n";
}
