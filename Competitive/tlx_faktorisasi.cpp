#include <iostream>
#include <cmath>
#include <vector>

/*link : https://tlx.toki.id/courses/basic/chapters/10/problems/D*/

using namespace std;

int n;

void faktorisasi(){
	int temp = n;
	int i = 2;
	while(i <= temp){
		int pangkat = 0;
		if(temp%i == 0){
			while(temp%i == 0){
				temp /= i;
				pangkat++;
			}
			cout << i;
			if(pangkat > 1) cout << "^" << pangkat;
			if(temp > 1) cout << " x "; 
		}
		i++;
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	faktorisasi();	

	return 0;
}