#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string ConvertNineZero(int n){
    // string numString = bitset<8>(n).to_string();
    // unsigned long intNum = bitset<8>(numString).to_ulong();
    string sumString = "9";
    int intNum;
    bool loop = false;
    if(n%2 == 0 | n%5 == 0){
        while(!loop){
            intNum = stoi(sumString);
            if(intNum%n == 0){
                return sumString;
            }else{
                sumString += "0";
            }
        }
    }else{
        while(!loop){
            intNum = stoi(sumString);
            if(intNum%n == 0){
                return sumString;
            }else{
                sumString += "0";
            }
        }
    }
    
    return 0;
}

int main(){
    int t,n;
    cin >> t;
    
    
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << ConvertNineZero(n) << endl;
    }
    return 0;
}


/*#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string ConvertNineZero(int n){
    string numString = bitset<8>(n).to_string();
    int intNum = stoi(numString);
    intNum *= 9;
    cout << intNum << endl;
    if(intNum%n == 0){
        numString = to_string(intNum);
        return numString;
    }
    return 0;
}

int main(){
    int t,n;
    cin >> t;
    
    string number[t];
    for(int i = 0; i < t; i++){
        cin >> n;
        number[i] = ConvertNineZero(n);
        cout << number[i] << endl;
    }
    
    return 0;
}*/
