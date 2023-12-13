#include <iostream>
#include <string>

using namespace std;

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
	string s;bool ans;
	getline(cin,s);
	int a = 0, b = s.length() - 1;
	
	ans = palindrom(s,a,b);
	s = (ans) ? "YA\n" : "BUKAN\n";
	cout << s;
	return 0;
}