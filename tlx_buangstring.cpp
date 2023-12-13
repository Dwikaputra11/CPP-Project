#include <bits/stdc++.h>
using namespace std;

void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
    size_t pos = string::npos;
    // Search for the substring in string in a loop untill nothing is found
    while ((pos  = mainStr.find(toErase) )!= string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

int main()
{
	string str,toErase;
	cin >> str >> toErase;
	eraseAllSubStr(str,toErase);
	cout << str;

	return 0;
}
