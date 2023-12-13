#include <bits/stdc++.h>
using namespace std;

#define FAST std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){ 
    int n;
    cin >> n;
    int a[n][2];   

    for(int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }

    double x,y;
    double maxN[n];
    double max = -1;
    double s;
    int ans[1][1];
    for(int i = 0; i < n; i++){
        double max = -1;
        for(int j = 0; j < n - 1; j ++){
            if(j + 1 == i) continue;
            else{
                x = a[i][0] + a[j + 1][0];
                y = a[i][1] + a[j + 1][1];
                s = (double) sqrt(x*x / y*y);
                if(max < s){
                    max = s;
                }
            }
        }   
        maxN[i] = max;
    }
    max = -1;
    int idx;
    for(int i = 0; i < n; i++){
        if(maxN[i] > max){
            max = maxN[i];
            idx = i;
        }
    }

    cout << a[idx][0] << " " << a[idx][1];
}