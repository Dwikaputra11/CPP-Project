#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n; 
	cin >> n;
	int b;
	int mas[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> b;
        mas[b] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << mas[i] << " ";
    }
	return 0;
}
