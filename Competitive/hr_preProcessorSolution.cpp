#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// link : https://www.hackerrank.com/contests/code-cpp-4/challenges/preprocessor-solution/problem

int main() {
    vector <int> v;

    int n,t;
    cin >> n;

    for(int i = 0; i < n; i++){
      cin >> t;
      v.push_back(t);
    }

    int max, min;

    min = *min_element(v.begin(), v.end());
    max = *max_element(v.begin(), v.end());

    int sum = max - min;

    cout << "Result" << sum;

    return 0;
}