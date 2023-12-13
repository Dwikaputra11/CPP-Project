#include <iostream>
using namespace std;

int digitSum(int n){
    int res = 0;
    // menghilangkan angka nol dibelakang
    while (n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(){
    int n,a,num; 
    cin >> n;
    int result[101] = {0};
    
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> num;
            result[i] += digitSum(num);
        }
    }
    
    for(int i = 0; i < n;i++){
        if(result[i]%3 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}