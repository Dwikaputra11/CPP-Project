#include <iostream>
#include <vector>
using namespace std;

void ans(int n){
    vector<int> v;
    if(n == 3){
        v.push_back(n);
    }
    for(int i = 4; i <= n/2; i++){
        if((n%i == 0)&& (i&1)){
            v.push_back(i);
        }
    }

    if(v.size() != 0){
        cout << "ADA\n";
        cout << "Nomor: ";
        for(int i: v){
            cout << i << " ";
        }
    }else{
        cout << "TIDAK ADA";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int t,n;
    bool a = 3&1;
    cin >> t;
    while(t--){
        cin >> n;
        ans(n);
    }
    
    return 0;
}
