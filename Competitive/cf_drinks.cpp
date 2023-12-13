#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	double sum = 0.0;
	int n;
	cin >> n;
	double arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i] /= 100;
		// cout << arr[i] << " ";
	}

	// cout << "\n";

	for(int i = 0; i < n; i++){
		sum += arr[i];
	}

	// cout << sum << endl;
	double val;
	val = (double) (sum/n)*100;

	cout << val;

	return 0;
}
