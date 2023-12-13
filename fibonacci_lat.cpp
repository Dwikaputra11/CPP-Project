#include <iostream>
using namespace std;
int main()
{
 int n, a = 0, z = 1, selanjutnya = 0;
 cout << " cari suku ke : "; cin >> n;
 for (int i = 1; i <= n; ++i)
 {
 if(i == 1)
 {
 continue;
 }
 if(i == 2)
 {
 continue;
 }
 selanjutnya = a + z;
 a = z;
 z = selanjutnya;
 system("cls");
 cout << z;
 }
 return 0;
}
