#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool angka[990000];
vector<int> primeNumbers;
int findNextPrime(int num){
	for(int i = num + 1; i < 990000; i++){
		if(angka[i] == true)
			return i;
	}
	return 0;
}
// void findPrimeK(int test){
// 	int k = 0;
// 	for(int num = 2;test > 0; num++)
// 		if(angka[num] == true){
// 			test--;
// 			k = num;
// 		}
// 	cout << k << endl;
// }

void primeK(){
	for(int i = 2; i < 990000; i++){
		if(angka[i]) primeNumbers.push_back(i);
	}
}

int main()
{
	int t;
	cin >> t;

	for(int i = 2; i <= 990000; i++){
		angka[i] = true;
	}

	int prime = 2;
	while(prime <= 990000 && prime != 0){
		for(int num = prime; num <= 990000; num += prime){
			if(num != prime && num%prime == 0) angka[num] = false;
		}
		prime = findNextPrime(prime); 
	}

	primeK();
	int test;
	for(int i = 0; i < t; i++){
		cin >> test;
		cout << primeNumbers[test - 1] << endl;
	}

	// for(int i = 1; i < 77777; i++){
	// 	if(angka[i])
	// 		cout << i << " ";
	// }

	return 0;
}
