#include <bits/stdc++.h>
using namespace std;

void convertLowUp(string &s){
	int len = s.length();

	for(int i = 0; i < len; i++){
		int c = s[i];
		if(islower(c))
			s[i] = toupper(c);
		else
			s[i] = tolower(c);
	}
}

int main()
{
	string s;
	cin >> s;
	convertLowUp(s);
	cout << s;

	return 0;
}
