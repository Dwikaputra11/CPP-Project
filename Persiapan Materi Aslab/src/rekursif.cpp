#include <iostream>
using namespace std;

void fibbonaci(int n){
    static int n1 = 0,n2 = 1,n3;
    if(n > 0){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
        fibbonaci(n-1);
    }   

}

int main(int argc, char const *argv[])
{
    
    // cout << "test" << endl;
    int n;

    cin >> n;

    fibbonaci(n);

    cout << "\nSelesai";
    
    return 0;
}
