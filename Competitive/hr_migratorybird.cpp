#include <iostream>
using namespace std;
// link : https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true


int main(){
    int num,ans = 1,x;
    cin >> num;
    int a[10] = {0};
    for (int i = 0; i < num; i++){
        cin >> x; a[x]++;
    }
    for(int i = 2; i <= 5; i++){
        if(a[i] > a[ans]) ans = i ;
    }
    cout << ans;
    
    return 0;
}
