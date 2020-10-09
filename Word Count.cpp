#include <bits/stdc++.h>
using namespace std;

int uniqueWordCount(const vector<string>& lines) {
     string word;
	set<string> uniqueWords;

	for (string line : lines) {
          stringstream ss(line);
          while(ss>>word) {
               uniqueWords.insert(word);
          }
	}

	return uniqueWords.size();
}

map<string, int> freqMap(const vector<string> lines) {

     string word;
     map<string, int> freqs;

     for (string line : lines) {
          stringstream ss(line);
          while (ss>>word) {
               freqs[word]++;
          }
     }

     return freqs;
}

void printMap(map<string, int> freqs) {

	for (pair<string, int> w : freqs) {
          cout<<w.first<<" : "<<w.second<<"\n";
	}

}

int main() {

	string fname = "res/mlk-dream.txt";

	if (fname == "") {
          return 0;
	}

	ifstream myFile(fname);
	string temp;
	vector<string> lines;

	while (getline(myFile, temp)) {
          lines.push_back(temp);
	}

	int uwc = uniqueWordCount(lines);
	map<string, int> allWords = freqMap(lines);

	cout<<uwc<<"\n";

     printMap(allWords);
}
