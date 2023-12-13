#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;cin.ignore();
	string w[n];
	for(int i = 0; i < n; i++){
		getline(cin,w[i]);
	}
	for(int i = 0; i < n; i++){
		if(w[i].length() <= 10){
			cout << w[i] << endl;
		}else{
			cout << w[i].at(0) << w[i].length() - 2 << w[i].at(w[i].length() - 1) << endl;
		}
	}

	return 0;
}
