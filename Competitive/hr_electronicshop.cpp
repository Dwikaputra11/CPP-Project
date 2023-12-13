#include <bits/stdc++.h>

using namespace std;

// link : https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=false

int main()
{
    int b,n,m,sum,ans = -1;
    cin >> b >> n >> m;
    int kb[n],d[m];
    for(int i = 0; i < n; i ++) cin >> kb[i];
    for(int i = 0; i < m; i ++) cin >> d[i];
    sort(kb,kb+n);
    sort(d,d+m);
    int x = m;
    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            if(kb[i] + d[j]<= b) ans = max(ans,kb[i] + d[j]);
        }
    }
    cout << ans;
    
}
