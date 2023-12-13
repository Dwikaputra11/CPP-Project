#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t,maxTim = -999999, maxName = -999999,nTeam,temp;
	string team, member;
	cin >> t;
	while(t--){
		cin >> team;
		cin >> nTeam;
		while(nTeam--){
			cin >> member;
			temp = member.length();
			if(temp > maxName) maxName = temp;
		}
		temp = team.length();
		if(temp > maxTim) maxTim = temp;
	}

	cout << maxTim << " " << maxName; 
	return 0;
}