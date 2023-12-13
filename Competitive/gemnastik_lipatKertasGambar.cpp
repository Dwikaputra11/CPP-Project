#include <iostream>
using namespace std;


int main() {
  int n, p, l, t,res;
  int min, max;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> p >> l >> t;
    while(t--){
      if(p > l) p /= 2;
      else l /= 2;
    }
    min = (p < l) ? (p):(l);
    max = (p > l) ? (p):(l);
    cout << max << " " <<  min << endl;
  }
  

  return 0;
}