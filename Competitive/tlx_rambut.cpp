#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,d,p;

	cin >> n >> d;
	int j = 2;
	bool f = false;
	while(!f){
		// cout << "j = " << j << endl;
		p = pow(d,j);
		// cout << p << endl;
		if(n < p){
			cout << "YES";
			f = true;
			break;
		}
		if(p == d) break;
		j++;
	}

	if(!f) cout << "NO";


	return 0;
}
