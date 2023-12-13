#include <iostream>
#include <algorithm>
using namespace std;

void urut(int arr[], int n){
  int satuan, puluhan;
  for (int gap = n/2; gap > 0; gap /= 2)
    {
      // satuan
        for (int i = gap; i < n; i += 1)
        {
          satuan = arr[i]%10;
            int j;
            for (j = i; j >= gap && (arr[j - gap]%10 > satuan) ; j -= gap){
             swap(arr[j],arr[j-gap]);
            }
        }
      for(int i = 0 ; i < n - 1 ; i++){
        for(int k = 0; k < n - i - 1; k++){
          if(arr[k]%10 == arr[k + 1]%10){
            if(arr[k] > arr[k + 1]){
              swap(arr[k],arr[k+1]);
            }
          }
        }
      }

    }
}

int main() {
  int n, arr[100];
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  urut(arr, n);
  for (int i=0; i<n; i++){
    cout << arr[i] << endl;
  }

  return 0;
}

/*link : https://gist.github.com/willnode/1eb1b5da4e19735bea598d4c2bc27f59*/