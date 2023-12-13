#include <bits/stdc++.h>
using namespace std;

int arr[1101];

int main(int argc, char const *argv[])
{
	int n,k,j, temp;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
		k = arr[0];
	for(int i = 0; i < n; i++){
		j = arr[i+1] - arr[i];
		if(j > 2) {cout << "Panggil Ambulans"; break;}
		else{
			if(arr[i+1] == (arr[i] + k - 1)) k -= 1;
			else if(arr[i+1] == (arr[i] + k)) k -= 0;
			else if(arr[i+1] == (arr[i] + k + 1)) k+=1;
		}
	}	


	return 0;
}
