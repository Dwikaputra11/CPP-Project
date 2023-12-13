#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,a,b;
	cin >> t;
	for(int i = 0; i < t; i++){
		int sum = 0;
		cin >> a >> b;
		int arr[b] = {0};
		for(int k = 2; k <= a ;k++){
			for(int j = 2; j <= b; j++){
				if(arr[j] == 1){
					continue; 
				}
				else if(j%k == 0){
					arr[j] = 1;
				}else{
					arr[j] = j;
				}
			}
		}
		for(int s = 2; s<= b; s++){
			if(arr[s] > 1) sum++;
		}
		cout << sum << endl;
	}




	return 0;
}
