#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s,t;

	cin >> s >> t;
	int sl, tl,max,min;
	sl = s.length();
	tl = t.length();

	max = (sl > tl) ? sl : tl;
	min = (sl < tl) ? sl : tl;

	int startIndex = 0;
	for(int i = 0; i < min;i++){
		for(int j = 0; j < max; j++){
			if(s[j] == t[i] && s[j + 1] == t[i + 1] && s[j + 2] == t[i + 2] && s[j + 3] == t[i + 3]){
				startIndex = j;
			}
		}
	}

	string str = s.substr(0,startIndex) + t;
	
	// cout << str << endl;
	cout << str.length();
	return 0;
}
