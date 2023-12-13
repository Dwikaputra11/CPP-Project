#include <iostream>
#include <string>

using namespace std; 
// link : https://codeforces.com/problemset/problem/266/B

// string convertToString(char* a, int size)
// {
//     int i;
//     string s = "";
//     for (i = 0; i < size; i++) {
//         s = s + a[i];
//     }
//     return s;
// }

int main(int argc, char const *argv[])
{
	int n,t;

	cin >> n >> t;

	string s;
	cin >> s;

	for(int k = 0; k < t; k++){
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'B' && s[i + 1] == 'G'){
				swap(s[i],s[i + 1]);
				i++;
			}
		}
	}

	// length of char
	/*
	int n = sizeof(c)/sizeof(char)
	*/

	cout << s;
	return 0;
}