#include <bits/stdc++.h>

using namespace std;
// link : https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

void solve(int a){
    int p = 1, h = 1;
    if(a == 0) cout << "1\n";
    else{
        while(p <= a){
            if(p&1) h*=2;
            else h+=1;
            p++;
        }
        cout << h << "\n";   
    }
}

int main(){
    int t,a; 
    cin >> t;
    while(t--){
        cin >> a;
        solve(a);
    }
    
}

