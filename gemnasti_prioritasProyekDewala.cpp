#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate distance
int distance(int x1, int y1, int x2, int y2)
{
    int x, y;
    x = x2 - x1;
    y = y2 - y1;
    return sqrt(pow(x,2) + pow(y,2));
}
 
// Drivers Code
int main()
{
    int n, x[100000][2], y[100000][2], r[100000][2], a[100000];
    string nama[101][2];
    cin >> n;
    
    for (int i=0; i<n; i++){
      for (int j=0; j<2; j++){
          cin >> nama[i][j];  
          cin >> x[i][j];
          cin >> y[i][j];
          cin >> r[i][j];
        }
      }

    for (int i=0; i<n; i++){
      a[i] = distance(x[i][0], y[i][0],x[i][1],y[i][1]);
      // cout << a[i];
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n - i; j++){
        if(a[j] < a[j + 1]){
          swap(nama[j][0],nama[j+1][0]);
          swap(nama[j][1],nama[j+1][1]);
          swap(a[j],a[j+1]);
        }
      }
    } 

    for(int i = 0; i < n; i++){
      for(int j = 0; j < 2;j++){
        cout << nama[i][j] << " ";
      }
      cout << a[i] << endl;
    }
    
    return 0;
}