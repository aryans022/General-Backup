#include<bits/stdc++.h>
using namespace std;

void generateCombinationsHelper(set<string>& choices, int rem, set<string>& current, set<set<string>>& all) {

     if (rem == 0) {
          all.insert(current);
     }
     else if (choices.size()<rem) {
          ;
     }
     else {
          set<string>::iterator it = choices.begin();
          string currChoice = *it;
          choices.erase(currChoice);

          generateCombinationsHelper(choices, rem, current, all);

          current.insert(currChoice);
          generateCombinationsHelper(choices, rem-1, current, all);

          choices.insert(currChoice);
          current.erase(currChoice);
     }

}

set<set<string>> generateCombinations(set<string> choices, int rem) {
     set<set<string>> all;
     set<string> current;
     generateCombinationsHelper(choices, rem, current, all);
     return all;
}

int main() {

	set<string> original = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"};
	set<set<string>> combinations;

	combinations = generateCombinations(original, 7);

	int i = 0;
	for (set<string> comb : combinations) {
          for (string a : comb) {
               cout<<a<<" ";
          }
          i++;
          cout<<endl;
	}
	cout<<i;

}
