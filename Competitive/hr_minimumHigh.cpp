#include <iostream>
#include <cmath>
using namespace std;


/* link : https://www.hackerrank.com/challenges/lowest-triangle/problem?h_r=next-challenge&h_v=zen*/


int main(){
    double b,a;
    cin >> b >> a;
    //inget casting kalo perlu
    cout << (int)ceil((2*a/b));
}
