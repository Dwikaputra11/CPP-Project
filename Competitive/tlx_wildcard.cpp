#include <iostream>
#include <string>

using namespace std;

// link : https://tlx.toki.id/courses/competitive/chapters/01/problems/C

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string clue;
  cin >> clue; 
  int find = clue.find("*");
  int lc = clue.length();

  int t;
  cin >> t;

  string suggest;

  while(t--){
    bool ok = true;
    cin >> suggest;
    int ls = suggest.length();
    if(ls < lc - 1) continue; 
    for(int i = lc - 1; i > find; i--) ok &= (clue[i] == suggest[ls - lc + i]);
    for(int i = 0; i < find; i++) ok&=(clue[i] == suggest[i]);
    if(ok) cout << suggest << "\n";
  }

	return 0;	
}