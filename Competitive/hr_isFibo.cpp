#include <iostream>
using namespace std;

bool isFibo(long n ){
    long temp = 0;
    long temp1 = 1;
    long result = 0;
    bool isFibo;
    for (long i = 0 ; result <= n; i++){
        result = temp + temp1;
        temp1 = temp;
        temp = result;
        if(result == n) return true;
        else if (result > n) return false;
    }
    return 0; 
}

int main(){
    
    long t;
    long n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(isFibo(n)) cout << "isFibo" << endl;
        else cout << "isNotFibo" << endl;
    }
    
}