#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
	if(a > b) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int n; 
	cin >> n;
	int arr[n];
	int mySum = 0,myBroSum = 0,counter = 0;
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
		myBroSum += arr[i];
	}
	sort(arr,arr+n,compare);

	for(int i = 0; i < n; i++){
		mySum += arr[i];
		myBroSum -= arr[i];
		counter++;
		if(mySum > myBroSum){
			break;
		}
	}

	cout << counter;

	return 0;
}
