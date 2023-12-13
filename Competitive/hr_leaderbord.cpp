#include <iostream>
using namespace std;

#define ll long long int
// link : https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

int main(){
    ll i,j,n,m,an[20005],am[20005],r[20005];
    cin >> n;
    for(i = 0; i < n; i++) cin >> an[i];
    r[0] = 1;
    for(i = 1; i < n; i++){
        if(an[i] == an[i - 1])
            r[i] = r[i - 1];
        else
            r[i] = r[i - 1] + 1;
    }
    r[n] = r[n - 1] + 1;
    cin >> m;
    for(i = 0; i < m; i++) 
        cin >>am[i];
    
    i = n - 1, j = 0; 
    
    while(j < m){
        while(an[i] < am[j] && i > 0) i--;
        // cout << "i : " << i << endl;
        if(an[i] == am[j]) 
            cout << r[i] << "\n";
        else if(an[i] > am[j])
            cout << r[i] + 1 << "\n";
        else{
            if(r[i] == 1)
                cout << "1\n";
            else
                cout << r[i] - 1 << "\n";
        }
        j++;
    }
}

//  dengan menggunakan c lebih efektif dalam menampung kerja yang berat seperti data yang lebih banyak
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <limits.h>
// #include <stdbool.h>
// #define ll long long int
// int main(){
//     ll n,m,i,j,an[200006],am[200005],ar[200005];
//     scanf("%lld",&n);
//     for(i=0;i<n;i++)
//         {
//         scanf("%lld",an+i);
//     }
//     ar[0]=1;
//     for(i=1;i<n;i++)
//         {
//         if(an[i]==an[i-1])
//             ar[i]=ar[i-1];
//         else
//             ar[i]=ar[i-1]+1;
//     }
//     ar[n]=ar[n-1]+1;
//     scanf("%lld",&m);
//     for(i=0;i<m;i++)
//         {
//         scanf("%lld",am+i);
        
//     }
//     i=n-1;j=0;
//     while(j<m)
//         {
//         while(an[i]<am[j] && i>0)
//             i--;
//         if(an[i]==am[j])
//         printf("%lld\n",ar[i]);
//         else if(an[i]>am[j])
//             printf("%lld\n",ar[i]+1);
//             else{
//             if(ar[i]==1)
//               printf("1\n");
//             else
//                 printf("%lld\n",ar[i]-1);}  
//         j++;
//     }
//     return 0;
// }