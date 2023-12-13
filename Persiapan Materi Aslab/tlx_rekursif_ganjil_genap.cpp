#include <iostream>
using namespace std;

int ans(int n){
    if(n == 0){
        return 1;
    }else if(n%2 == 0){
        return (n/2)*ans(n - 1);
    }else{
        return n*ans(n - 1);
    }
} 

int main(int argc, char const *argv[])
{   
    int n;
    cin >> n;

    cout << ans(n);
    
    return 0;
}
