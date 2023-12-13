#include <iostream>
using namespace std;

bool isPrimeSqrt(int n){
	int num = 1; 
	int i = 2;
	if(n == 1){
		return true;
	}else{
		while(i*i <= n){
			if(n%i == 0){
				num *= 2;
				if(num > 2)
					return false;	
			}	
			i += 1;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
 	int n; 
 	cin >> n;

 	int temp;
 	string ans;
 	for(int i = 0; i < n; i++){
 		cin >> temp;
 		ans = (isPrimeSqrt(temp))? "YA" : "BUKAN";
 		cout << ans << endl;
 	}


	return 0;
}
