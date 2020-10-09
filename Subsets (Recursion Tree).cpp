#include <bits/stdc++.h>
using namespace std;

void generateSubsetsHelper(set<string> source, set<string> curr) {                   //helper function to get empty current set

     if (source.empty()) {
          for (set<string>::iterator it = curr.begin(); it != curr.end(); it++) {
               cout<<*it<<" ";
          }
          cout<<endl;
     }
     else {

          set<string>::iterator it = source.begin();
          string choice = *it;
          source.erase(choice);

          generateSubsetsHelper(source, curr);                                       //branch 1

          curr.insert(choice);
          generateSubsetsHelper(source, curr);                                       //branch 2

     }
}


void generateSubsets(set<string> source) {                                 //generates all subsets in no particular order
     set<string> curr;
     generateSubsetsHelper(source, curr);
}

int main() {

	set<string> a;                                                        //driver set
	a.insert("a");
	a.insert("b");
	a.insert("c");
	a.insert("d");

	generateSubsets(a);
}
