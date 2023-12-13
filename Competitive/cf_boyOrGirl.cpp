#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// link : https://codeforces.com/problemset/problem/236/A

int main()
{
	string s;
	cin >> s;

	int n = s.length();

	char c[n + 1];

	strcpy(c,s.c_str());

	int a[27] = {0};
	int temp;
	for(int i = 0; i < s.length(); i++){
		temp = c[i] - 97;
		// cout << temp << " ";
		a[temp]++;
	}
	// cout << "\n";

	int count = 0;

	for(int i = 0; i < 27; i++){
		// cout << a[i] << endl;
		if(a[i] >= 1){
			count++;
		}
	}

	if(count&1){
		cout << "IGNORE HIM!";
	}else if(count%2 == 0){
		cout << "CHAT WITH HER!";
	}

	return 0;
}