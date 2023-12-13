#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        for(int j= 0; j < n - i; j++){
            cout << " ";
        }
        for(int k = 0; k < i + 1; k++){
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n\n";
    for(int i = 0; i < n; i++){
        for(int j = n; j > i; j--) cout << "*";
            cout << endl;
    }
    
    return 0;
}

