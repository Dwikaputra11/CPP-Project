#include <bits/stdc++.h>
using namespace std;

bool reflect(string s, int a, int b){
	string kar = "AEHIJMOSTUVWXYZ12358";
	string ref = "A3HILMO2TUVWXY51SEZ8";
	int n = kar.length() - 1;

	if(b == a || b < a){
		return true;
	}
	else{
		for(int i = 0; i < n; i++){
			if((s[a] == kar[i] && s[b] == ref[i]) || (s[a] == ref[i] && s[b] == kar[i]))
			return reflect(s, a + 1, b - 1);
		}
	}
	return false;
}

bool palindrom(string s,int a, int b){
	if(b == a || b < a){
		return true;
	}
	else{
		if(s[a] != s[b]) return false;
		else return palindrom(s, a + 1, b - 1);
	}
}


int main()
{
	string str;int a,b;
	while(cin >> str){
		a = 0;b = str.length() - 1;
		if(palindrom(str,a,b) && reflect(str,a,b)) cout << str << " -- palindrom refleksi\n";
		else if(palindrom(str,a,b)) cout << str << " -- palindrom biasa\n";
		else if(reflect(str,a,b)) cout << str << " -- string refleksi\n";
		else cout << str << " -- bukan palindrom\n";
	}


	return 0;
}