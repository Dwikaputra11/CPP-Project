#include <iostream>
using namespace std;

int ans(int l){
    if(l == 1 || l == 0){
        return 1;
    }else{
        return l*ans(l-1);
    }
}

int main(){
    string k;
    cin >> k;
    int l = k.length();
    cout << ans(l) - 1;

    return 0;
}