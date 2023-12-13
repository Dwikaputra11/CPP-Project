#include <iostream>
using namespace std;

int main(){
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    ((s3 == 1 && s2 == 0 && s1 == 0) || (s1 == 0 && s2 == 1 && s3 == 1) || (s2 == 0 && s1 == 1 && s3 == 1)) ? cout << 0 : cout << 1;

    return 0;
}