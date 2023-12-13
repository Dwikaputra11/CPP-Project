#include <bits/stdc++.h>
using namespace std;

char word[111];
int n;

int main()
{
	cin >> word;
	cin >> n;

	int len = strlen(word);
	for(int i = 0; i < len; i++){
		int ord = word[i] - 'a' + n;
		int encrypted = (ord)%26;
		if(encrypted > 26){
			encrypted -= 26;
		}
		word[i] = encrypted + 'a';
	}

	cout << word;

	return 0;
}
