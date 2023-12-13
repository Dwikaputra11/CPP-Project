#include <iostream>
#include <cstdlib>
using namespace std;

bool checkPrime (int n){
    // cout << "Check Prime\n";
    int m = n/2;
    bool flag = true;
    if (m == 1) return flag;
    else {
         for(int i = 2; i <= m; i++){
            // cout << "loop\n";
            if(n%i == 0){
                flag = false;
                break;
            }
        }
         return flag;
    }
}

int main(){
    int n,m,i = 0;
    cin >> n >> m;
    if (n < 2){
        n = 2;
    }
    int count = 0;
    while(n <= (m - 2)){
        if(checkPrime(n) && checkPrime(n + 2)){
           count++;
        }
        n++;
    }
    
    cout << count;
    return 0;
}