#include <iostream>
using namespace std;

/*link: https://tlx.toki.id/courses/basic/chapters/13/problems/D*/

int n,k;
int num[9] = {0};
void ans(int kedalaman){
	if(kedalaman >= n){
		for(int i = 0; i < n; i++) cout << num[i] << " ";
		cout << endl;
	}else{
		for(int i = num[kedalaman - 1] + 1; i <= k; i++){
			num[kedalaman] = i;
			ans(kedalaman + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> k >> n;
	ans(0);
	

	return 0;
}
