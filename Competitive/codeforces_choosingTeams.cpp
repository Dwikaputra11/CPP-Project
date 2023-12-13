#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
	int n,k,t = 0,sum = 0;

	cin >> n >> k;
	int a[n];
	int team = 3;
	int limit = 5;

	for(int i = 0; i < n;i++){
		cin >> a[i];
		if(a[i] + k <= limit){
			t++;
			if(t == team){
				sum++;
				t = 0;
			}
		}
	}

	cout << sum << endl;


	return 0;
}
