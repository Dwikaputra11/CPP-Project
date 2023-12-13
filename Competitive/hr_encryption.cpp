#include <bits/stdc++.h>
// link : https://www.hackerrank.com/challenges/encryption/problem?isFullScreen=false
using namespace std;

int main(){
   string s;
   getline(cin,s);
   int c,l;
   l = s.length();
   c = count(s.begin(),s.end(),' ');
   remove(s.begin(),s.end(),' ');
   s.resize(l-c);
   l = s.length();
   int r,cl;
   r = floor(sqrt(l));
   cl = ceil(sqrt(l));
   if(r*cl < l) r = cl;
   for(int i = 0; i < cl; i++){
       for(int j = i; j < s.length(); j+=cl){
           if(j+cl > s.length() - 1)
            cout << s[j] << " ";
            else
            cout << s[j];
       }
   }
   
}
