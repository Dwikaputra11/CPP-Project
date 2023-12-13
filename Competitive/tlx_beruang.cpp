#include <iostream>
using namespace std;


int main()
{
	int n,d,sum = 0;

	cin >> n >> d;

	int a[n + 5];
	int num;
	int k = 0;

	for(int i = 0; i < n; i++){
		cin >> num;
		a[i] = num + d;
		while((k < n) && (num > a[k])){
			k++;
		}
		if(num == a[k]) sum++;
	}

	cout << sum;



	return 0;
}
