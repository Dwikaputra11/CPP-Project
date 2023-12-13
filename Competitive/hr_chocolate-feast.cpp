#include <bits/stdc++.h>
using namespace std;

// link : https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

void solve() {
    int m,n,c,b,w;
    cin >> n >> c >> m;
    w = n/c;
    // cout << "w : " << w << "\n";
    b = w;
    // cout << "b : " << b << "\n";
    while(w >= m){
        b += w/m;
        // cout << "b : " << b << "\n";
        w = w/m + w%m;
        // cout << "w : " << w << "\n";
    }
    cout << b << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    
}
