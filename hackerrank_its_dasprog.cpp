// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int ans(int arr[], int arrMiss[], int n){
//     int i = 0;
//     while(arr[i] == arrMiss[i]){
//         cout << "a : \n";
//         i++;
//     }
//     return arr[i];
// }


// int main() {
//     int i,n;
//     cin >> i; 
//     while(i--){
//         cin >> n;
//         int arr[n], arrMiss[n - 1];
//         for(int i = 0; i < n; i++) 
//             cin >> arr[i];
//         for(int i = 0; i < n - 1; i++)
//             cin >> arrMiss[i];
//         cout << ans(arr,arrMiss, n);
//     }
    
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void ans(string s){
    sort(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    
    string s = " ";
    while(s != "exit"){
        getline(cin, s);
        if(s != "exit"){
            s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
            // iterator end = remove(s.begin(), s.end(), ' ');
            // s.erase(end,s.end());
            ans(s);
        }
    }
    return 0;
}
