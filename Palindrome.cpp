#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string toCheck) {

     int l = toCheck.length();

     if (l < 2) {
          return true;
     }

     if (toCheck[0] == toCheck[l-1]) {
          return (isPalindrome(toCheck.substr(1, l-2)));
     }
     else {
          return false;
     }
}

int main() {

	string check = "aryan";
	cout<<"Enter a String: ";
	cin>>check;

     transform(check.begin(), check.end(), check.begin(), ::tolower);
     bool ans = isPalindrome(check);

	if (ans) {cout<<"Yes\n";}
	else {cout<<"No\n";}
}
