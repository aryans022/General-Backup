#include <bits/stdc++.h>
using namespace std;

void generateDictionary(set<string>& dictionary) {

     string fname = "res/EnglishWords.txt";
	ifstream dict(fname);

	vector<string> lines;
	string temp;

	while (getline(dict, temp)) {
          lines.push_back(temp);
     }

     string word;

     for (string line : lines) {
          stringstream ss(line);
          while (ss>>word) {
               dictionary.insert(word);
          }
     }
}

bool isShrinkable(string rem, const set<string>& dictionary) {

     if (rem == "a" || rem == "i" || rem == "o") {
          return true;
     }

     for (int i = 0; i < rem.length(); i++) {

          string left = rem.substr(0, i) + rem.substr(i+1);

          if (dictionary.find(left) != dictionary.end()) {
               if(isShrinkable(left, dictionary)) {
                    cout<<left<<endl;
                    return true;
               }
          }

     }

     return false;

}

int main() {

     set<string> dictionary;
     generateDictionary(dictionary);

     string word;
     cin>>word;

     cout<<boolalpha<<isShrinkable(word, dictionary)<<noboolalpha<<endl;

}
