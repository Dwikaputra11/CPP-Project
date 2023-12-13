#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	bool found = false;
	while(!found){
		if(n == 0){
			break;
		}else if(n%10 == 0){
			found =true;
		}
		n = n/10;
	}

	if(found) cout << "YES";
	else cout << "NO";


	return 0;
}	