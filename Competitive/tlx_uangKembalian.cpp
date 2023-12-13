#include <bits/stdc++.h>

using namespace std;


int arr[99999];
int kembalian(int k,int n){
	int best = 9999;
	if(k == 0) return 0;
	else{
		for(int i = 0;i < n; i++){
			if(arr[i] < k)
				best = min(best,kembalian(k-arr[i],n) + 1);
		}
	}
	return best;
}

int main()
{
	int n,k,min = -1;
	cin >> n;
	// int arr[n + 1];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cin >> k; 

	int ans = kembalian(k,n);
	cout << ans << endl;

	return 0;
}
