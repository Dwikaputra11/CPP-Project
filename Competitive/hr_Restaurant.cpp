#include<iostream>
using namespace std;
// link : https://www.hackerrank.com/challenges/restaurant/problem 
int main() {
	int T, l, b, n;
	cin >> T;

	for(int i=0 ; i<T ; i++){ 
	    cin >> l >> b;
	
	    for(int i=1 ; i<=l ; i++){
	        if(l%i == 0 && b%i == 0){
	            n=(l*b)/(i*i);
	        }
	    }
	    cout << n << endl; 
	} 
	
	return 0;
}