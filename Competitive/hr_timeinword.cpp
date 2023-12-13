#include <bits/stdc++.h>

using namespace std;
// link : https://www.hackerrank.com/challenges/the-time-in-words/problem?isFullScreen=false

string minutes[30] = {"one","two","three","four","five","six","seven","eight","nine","ten", "eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eightteen", "nineteen","twenty","twenty one", "twenty two", "twenty three", "twenty four","twenty five","twenty six", "twenty seven", "twenty eight", "twenty nine", "half"};
string hour[12] = {
    "one","two","three","four", "five", "six","seven", "eight","nine","ten","eleven","twelve"
};

int main(){
    int h,m;
    cin >> h >> m;
    if(m == 0){
        cout << hour[h - 1] << " o' clock";
    }else if(m > 30){
        m = 60 - m;
        if(m == 1){
            cout << minutes[m - 1] << " minute to " << hour[h];
        }else if(m == 15){
            cout << minutes[m - 1] << " to " << hour[h];
        }else{
            cout << minutes[m - 1] << " minutes to " << hour[h];
        }
        
    }else{
        if(m == 1){
            cout << minutes[m - 1] << " minute past " << hour[h - 1];
        }else if(m == 15 || m == 30){
            cout << minutes[m - 1] << " past " << hour[h - 1];
        }else{
            cout << minutes[m - 1] << " minutes past " << hour[h - 1];
        }
        
    }
}

