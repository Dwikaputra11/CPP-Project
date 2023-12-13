#include <iostream>
using namespace std;
/*https://tlx.toki.id/problems/troc-26/C*/

int n;
bool pernah[9] = {false};
int num[9];

void zigzag(int kedalaman){
	if(kedalaman >= n){
		bool isZigzag = true;
		for(int i = 1; i < n - 1; i++){
			bool con1 = num[i] > num[i + 1] && num[i] > num[i - 1];
			bool con2 = num[i] < num[i + 1] && num[i] < num[i - 1];
			if(!(con2 || con1)){
				isZigzag = false;
				// cout << "false" <<endl;
			}
		}
		if(isZigzag){
			for(int i = 0; i < n; i++) cout << num[i];
			cout << endl;
		}
	}else{
		for(int i = 0; i < n; i++){
			if(!pernah[i]){
				pernah[i] = true;
				num[kedalaman] = i + 1;
				zigzag(kedalaman + 1);
				pernah[i] = false;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	zigzag(0);
	return 0;
}
