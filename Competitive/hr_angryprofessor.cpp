#include <bits/stdc++.h>
using namespace std;

// link : https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

void solve(){
    int k, n,a,att;
    cin >> n >> k;
    att = n;
    for(int i = 0; i < n ; i++){
        cin >> a;
        if(a > 0) --att;
    }
    
    if (att >= k) cout << "NO\n";
    else cout << "YES\n";
    
}


int main(){
   int t;
   cin >> t;
   while(t--){
       solve();
   }
}

