#include <iostream>
#include <array>
using namespace std;

void sort(int a[], int b[],int n, int m){
      for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
          int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j-gap] > temp ; j -= gap){
             swap(a[j],a[j-gap]);
             swap(b[j],b[j-gap]);
            }
      }
    } 
}

int tes(int a[], int b[], int n, int m){
  for (int i=0; i<n; i++){
    if (a[i]<=m){
      m+=b[i];
    }
    else{
      break;
    }
  }
  return m;
}

int main(){

  int N,M,poin;
  cin >> N >> M;
  int a[N + 5];
  int b[N + 5];
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  for(int i = 0 ; i < N; i++){
    cin >> b[i];
  }

  sort(a,b,N,M);
  poin = tes(a,b,N,M);

  cout << poin ;


  return 0;
}

/*link : https://gist.github.com/willnode/1eb1b5da4e19735bea598d4c2bc27f59*/