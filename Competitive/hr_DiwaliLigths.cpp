#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin>>t;
    while(t--)
        {
        long n;  
        cin>>n;
        long r = 1;
        for(long i=1;i<=n;i++){
            r = r*2;
            r = r%100000;
        }
        r= r-1;
        cout << r << endl;
    }
       
    return 0;
}