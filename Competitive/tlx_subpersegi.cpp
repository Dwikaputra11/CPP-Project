#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,sum = 0;
	cin >> n;

	for(int i = 1; i <= n; i++){
		// cout << sum << endl;
		sum += pow(i,2);
	}

	cout << sum;
	return 0;
}