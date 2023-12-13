#include <iostream>
#include <string>

using namespace std;

string clue, suggest; int lc, ls; bool ok;
string wrong = "Wah, tidak bisa :(";
string correct = "Tentu saja bisa!";

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	getline(cin,clue); 
	lc = clue.length();
	getline(cin,suggest);
	ls = suggest.length();
	int check;
	if(lc-ls != 1) cout << wrong;
	else{
		int i = 0;
		int x = 0, y = 0;
		while(x < lc && y < ls && i < 2){
			if(suggest[y] != clue[x]){
				i++;
				x++; 
			}else{
				x++;
				y++;
			}
		}
		string ans = (i < 2) ? correct : wrong;
		cout << ans;
	}


	return 0;
}
