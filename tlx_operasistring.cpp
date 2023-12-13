#include <bits/stdc++.h>
using namespace std;

// char s1[111],s2[111],s3[111],s4[111];
void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
    size_t pos = mainStr.find(toErase);
    // Search for the substring in string in a loop untill nothing is found
    if(pos != string::npos) mainStr.erase(pos,toErase.length());
}
string s1,s2,s3,s4;

int main()
{
	cin >> s1 >> s2 >> s3 >> s4;

	eraseSubStr(s1,s2);
	int l3 = s3.length();
	int i3 = s1.find(s3) + l3;
	int l4 = s4.length();
	s1.insert(i3,s4);
	cout << s1;

	int a = 4;
	
	cout << "pre increment : " << ++a << "\n";
	cout << "post increment : " << a++ << "\n";
	cout << "nilai a : " << a;


	return 0;
}
