#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;

	int arr[n];

	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}

	int* max;
	max = max_element(arr,arr + n,comp);

	int res;
	res = *max + n-1;

	cout << res << endl;


	return 0;
}
