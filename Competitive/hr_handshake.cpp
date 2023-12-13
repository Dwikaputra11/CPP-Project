#include <iostream>
#include <exception>

/*
LINK : https://www.hackerrank.com/challenges/handshake/problem
Try this reasoning:

I (PersonA) am one out of N people, so I need to shake hands with (N-1) people. 
This reasoning holds true for all of the N people, so the number of hand shakes is N * (N-1). 
Now that PersonA and PersonB shook hands, PersonB and PersonA (same people, 
but from PersonB's perspective) don't need to shake anymore. 
So we initially counted each combination TWICE. 
Therefore, the number of hand shakes is

nShakes = (N * (N-1)) / 2

*/

using namespace std;

int factorial(int x){
    return (x * (x - 1))/2;
}

int main(){
    int n;
    int a; 
    cin >> n;
    int hasil[n];
    
    for(int i = 0; i < n; i++){
        cin >> a;
        hasil[i] = factorial(a);
    }
    
    for(int i = 0; i < n;i++){
        cout << hasil[i] << endl;
    }
}
