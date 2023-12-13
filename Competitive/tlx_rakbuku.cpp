#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,b;
    cin >> n >> b;
    int h[n + 1];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h + n, greater<int>());
    int sum = 0, i = 0;
    while(sum < b){
        sum+=h[i];
        i++;
    }
    cout << i;    
    return 0;
}