#include <bits/stdc++.h>
using namespace std;

int a[50];
int n = 0;
void ans(){
    for(int i = 0; i < n; i++){
        for(int y = i + 1; y < n; y++){
            if(i == y) continue;
            else {
                for(int j = y + 1; j < n; j++){
                    if(j == y) continue;
                    else if(a[i] - (a[y] + a[j]) == 10){
                        cout << a[i] << " " << a[y] << " " << a[j] << endl;
                    }
                }
            }
        }
    }
}

int main(){
    int i = 0;
    try{
        while(cin >> a[i]){
            if(i == 50){
                break;
            }
            i++;
            n++;
        }
        // ans();
        if(cin.fail() && !cin.eof()){
            throw "invalid input";
        }else{
            ans();
        }   
    }catch(const char* msg){
        cout << msg;
    }
}