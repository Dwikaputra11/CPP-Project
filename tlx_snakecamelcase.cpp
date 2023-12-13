#include <bits/stdc++.h>
using namespace std;

void convertToSnake(string &s){
	int len = s.length();

	for(int i = 0; i < len; i++){
		int c = s[i + 1];
		if(isupper(c)){
			s[i + 1] = tolower(c);
			s.insert(i + 1,"_");
			len++;
		}
	}
}
void convertToCamel(string &s){
	int len = s.length();

	for(int i = 0; i < len; i++){
		int c = s[i+1];
		if(s[i] == '_'){
			s[i + 1] = toupper(c);
			s.erase(i,1);
			len--;
		}
	}

}

int main()
{
	string s,snake = "_";
	cin >> s;
	int len = s.length();
	if(s.find(snake) < len) convertToCamel(s);
	else convertToSnake(s); 
	cout << s;

	return 0;
}
