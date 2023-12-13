#include <iostream>
using namespace std;

#define FAST std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int factorial(int i){
    if(i == 1 || i == 0) return 1;
    else return i*factorial(i - 1);
}

int main(int argc, char const *argv[])
{
    FAST
    int n, m;
    cin >> n >> m;
    cout << factorial(n)/(factorial(n - m)*factorial(m));

    return 0;
}
