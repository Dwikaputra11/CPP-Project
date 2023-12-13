#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	getline(cin,s);
	bool isLowercaseVowel,isUppercaseVowel;
	int l = s.length();
	
	for(int i = 0; i < l; i++){
		  isLowercaseVowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y');
		  isUppercaseVowel = (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y');
		if(!(isLowercaseVowel || isUppercaseVowel)){
			char c = tolower(s[i]);
			cout << "." << c;
		}
	}


	return 0;
}