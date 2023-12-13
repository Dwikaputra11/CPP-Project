#include <iostream>
#include <cmath> 
using namespace std;

int main(){
    double harga, jCicil,uang;
    cin >> harga >> jCicil >> uang;
    double cicil = harga - uang;
    cicil /= jCicil;
    cicil += (cicil * 10)/floor(100);
    cicil = floor(cicil);
    cout << cicil;
}