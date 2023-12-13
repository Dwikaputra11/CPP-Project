#include <iostream>
using namespace std;
/*https://tlx.toki.id/problems/troc-26/B*/

int main(int argc, char const *argv[])
{
	long long n,m, odd = 0, even = 0,a;
	bool white = false;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a;

			if((i + j) % 2 == 0){
				even += a;
				if(a == -1)
					white = true;
			}else{
				odd += a;
			}
		}
	}

	if(white == true && even < odd){
		cout << "YES\n" << odd - even - 1; 
	}else if(white == false && odd < even){
		cout << "YES\n" << even - odd - 1;
	}else{
		cout << "NO";
	}



	return 0;
}
