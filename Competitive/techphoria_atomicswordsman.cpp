#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned long long int m,split = 1;
    int n;
    cin >> n >> m;
    if(n == 64 || n == 63) cout << "menang";
    else{
        split = (long long int) pow(2,n);
        if(split <= m) cout << "kalah";
        else cout << "menang";
    }

    return 0;
}
