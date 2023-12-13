#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{   
    int n;
    ll d, banyak = 0;

    cin >> n >> d;
    pair<ll,ll> cokelat[n + 1];
    for(int i =0; i < n; i++){
        cin >> cokelat[i].first >> cokelat[i].second;
    }

    sort(cokelat, cokelat + n);

    for(int i = 0; i < n; i++){
        ll nBisaDibeli = d/cokelat[i].first;
        ll nYangDibeli = min(nBisaDibeli, cokelat[i].second);
        banyak += nYangDibeli;
        d -= cokelat[i].first*nYangDibeli;
    }

    cout << banyak;
    return 0;
}
