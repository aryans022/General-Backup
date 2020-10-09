#include <bits/stdc++.h>
using namespace std;

void generateSequencesHelper(string current, int n) {

     if (n == 0) {
          cout<<current<<endl;
     }
     else {
          generateSequencesHelper(current+'H', n-1);
          generateSequencesHelper(current+'T', n-1);
     }
}

void generateSequences(int n) {
     generateSequencesHelper("", n);
}

int main() {

	int n;
	cin>>n;

	if (n > 20) {
          cout<<"Nahi.";
	}
	else {
          generateSequences(n);
	}

}
