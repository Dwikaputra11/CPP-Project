#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//link : https://www.hackerrank.com/contests/code-cpp-3/challenges/variable-sized-arrays

int main() { 
    int n;
    int q;
    cin >> n >> q;
    vector<int> a[n];
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        int o;
        for(int j = 0; j < m; j++){
            cin >> o;
            a[i].push_back(o);
        }
    }
    
    int r, s;
    for(int k = 1; k <= q; k++){
        cin >> r >> s;
        cout << a[r][s] << endl;
    }
    return 0;
}



  // int m = 2, n = 4;
  //   //Grow rows by m
  //   a.resize(m);
  //   for(int i = 0 ; i < m ; ++i)
  //   {
  //       //Grow Columns by n
  //       a[i].resize(n);
  //   }<=