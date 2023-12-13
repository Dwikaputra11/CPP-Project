#include <iostream>
#include <algorithm>

#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string guest;
	string host;
	string random;
	string temp;

	cin >> guest;
	cin >> host;
	cin >> random;

	temp = guest + host;

	sort(temp.begin(),temp.end());
	sort(random.begin(),random.end());
	if(temp.compare(random) == 0){
		cout << "YES";
	}else{
		cout << "NO";
	}


	return 0;
}
