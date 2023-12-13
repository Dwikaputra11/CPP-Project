#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
	return (a < b);
}


int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;

	int f,t;
	int sum,max = -999999999;


	for(int i = 0; i < n; i++){
		cin >> f >> t;
		if(t > k){
			sum = f - (t - k);
		}else{
			sum = f;
		}
		if(sum > max){
			max = sum;
		}
	}

	// int* max;

	// max = max_element(sum, sum + n, comp);

	cout << max << endl;

	return 0;
}
