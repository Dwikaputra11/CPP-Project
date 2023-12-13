#include <iostream>

using namespace std;

long faktorial(int n) {
  long z = 1;
  int i = 1;
  while (i <= n) {
    z = z * i;
    i++;
  }
  return z;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, i, j, awal;
  cin >> awal >> a;
  a += 1;
  for (i = awal; i < a; i++) {
    for (j = 0; j < a - i - 1; j++) {
      cout << " ";
    }
    for (j = 0; j <= i; j++) {
      cout << faktorial(i) / (faktorial(j) * faktorial(i - j)) << " ";
    }
    cout << endl;
  }
  return 0;
}