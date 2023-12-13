#include <bits/stdc++.h>

using namespace std;

#define ll long long int

// link : https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

void solve(ll a,ll b) {
    ll ans = 0;
    float r = sqrt(a);
    ll sqr = ceil(r);
    // cout << sqr << endl;
    while(sqr*sqr <= b){
        ans++;
        sqr++;
        // cout << ans << endl;
    }
    
    cout << ans << endl;
    
}

int main(){
    ll t,b,a;
    cin >> t;
    while(t--){
        cin >> a >> b;
        solve(a,b);
    }
}

