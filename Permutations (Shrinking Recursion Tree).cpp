#include <bits/stdc++.h>
using namespace std;

void findPermutationsHelper(string rem, string soFar) {

     if (rem == "") {
          cout<<soFar<<endl;
     }

     for (int i = 0; i < rem.length(); i++) {
          char add = rem[i];
          string rest = rem.substr(0, i) + rem.substr(i+1);
          findPermutationsHelper(rest, soFar+add);
     }

}

void findPermutations(string word) {
     findPermutationsHelper(word, "");
}

int main() {

	string word;
	cin>>word;

	findPermutations(word);
}
