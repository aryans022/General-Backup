#include <bits/stdc++.h>
using namespace std;

set<string> uniqueWords(vector<string> lines) {

     set<string> uw;
     string word;

     for (string line : lines) {
          stringstream ss(line);
          while (ss>>word) {
               uw.insert(word);
          }
     }

     return uw;
}

set<string> generateNeighbouringWords(const set<string>& dictionary, string currentWord) {

     set<string> neighbouringWords;

     for (int i = 0; i < currentWord.length(); i++) {
          for (char ch = 'a'; ch <= 'z'; ch++) {
               string newWord = currentWord;
               newWord[i] = ch;
               if (dictionary.find(newWord) != dictionary.end()) {
                    neighbouringWords.insert(newWord);
               }
          }
     }

     return neighbouringWords;

}

stack<string> findWordLadder(string startingWord, string endingWord, set<string>& dictionary) {

     queue<stack<string>> partLadders;
     set<string> usedWords;

     stack<string> currentLadder;
     currentLadder.push(startingWord);
     partLadders.push(currentLadder);
     usedWords.insert(startingWord);

     while (!partLadders.empty()) {

          currentLadder = partLadders.front();
          string currentWord = currentLadder.top();

          set<string> newWords = generateNeighbouringWords(dictionary, currentWord);

          for (string newWord : newWords) {

               if (newWord == endingWord) {
                    currentLadder.push(newWord);
                    return currentLadder;
               }

               if (usedWords.find(newWord) == usedWords.end()) {
                    currentLadder.push(newWord);
                    usedWords.insert(newWord);

                    partLadders.push(currentLadder);
                    currentLadder.pop();
               }
          }

          partLadders.pop();
     }

     stack<string> emptyReturn;
     cout<<"No possible ladder"<<endl;
     return emptyReturn;

}

int main() {

     string startingWord = "write", endingWord = "might";

     string fname = "res/EnglishWords.txt";
     ifstream dictionary(fname);

     vector<string> lines;
     string temp;

     while (getline(dictionary, temp)) {
          lines.push_back(temp);
     }

     set<string> validWords = uniqueWords(lines);
     cout<<validWords.size()<<endl;

     stack<string> ladder = findWordLadder(startingWord, endingWord, validWords);

     while(!ladder.empty()) {
          cout<<ladder.top()<<endl;
          ladder.pop();
     }
}
