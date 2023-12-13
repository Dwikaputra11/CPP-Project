#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

//link : https://www.hackerrank.com/contests/code-cpp-3/challenges/overload-operators

int main() { 
    string s1,s2;

    int a,b,c,d;

    getline(cin,s1);
    getline(cin,s2);

    // cout << "s1 -> " << s1 << endl;
    // cout << "s2 -> " << s2 << endl;

    int temp;
    string sTemp1,sTemp2;
    temp = s1.find("+");
    sTemp1 = s1.substr(0,temp);
    // cout << temp << endl;
    // cout << sTemp1 << endl;
    a = stoi(sTemp1);
    sTemp1 = s1.substr(temp+2,s1.length());
    b = stoi(sTemp1);
    temp = s2.find("+");
    sTemp2 = s2.substr(0,temp);
    c = stoi(sTemp2);
    sTemp2 = s2.substr(temp+2,s2.length());
    d = stoi(sTemp2);

    int sum1,sum2;
    // cout << "a -> " << a << endl;
    // cout << "b -> " << b << endl;
    // cout << "c -> " << c << endl;
    // cout << "d -> " << d << endl;
    sum1 = a + c;
    sum2 = b+d;

    cout << sum1 << "+i" << sum2 << endl;

    

    return 0;
}
