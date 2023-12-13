#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,x,min = 9999999,temp,index,ans;
	cin >> n >> x;
	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		temp = abs(arr[i] - x);
		if(temp <= min){
			if(temp == min) ans = (arr[i] < arr[index]) ? arr[i] : arr[index];
			else{
				min = temp;
				index = i;
				ans = arr[i];
			}
		}
	}

	cout << ans; 



	return 0;
}
