#include <bits/stdc++.h>
// link : https://www.hackerrank.com/challenges/day-of-the-programmer/problem?h_r=next-challenge&h_v=zen&isFullScreen=false
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y == 1918) cout << "26.09." << y;
    else if(y%4 == 0){
        if(y < 1918) cout << "12.09." << y;
        else if (y == 2000 || y == 2400) cout << "12.09." << y;
        else if(y == 2200) cout << "13.09." << y;
        else if(y%4 == 0 && y%100 == 0) cout << "13.09." << y;
        else cout << "12.09." << y;
    }
    else cout << "13.09." << y;
}

