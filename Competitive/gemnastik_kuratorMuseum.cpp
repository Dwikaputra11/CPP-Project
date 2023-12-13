#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	
  int n,minMAx,index;
  cin >> n;
  int arr[n];
  int temp[10000] = {0};

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < n; i++){
    minMAx = 0;
    bool found = false; 
    for(int j = i + 1; j < n; j++){
      int dif = abs(arr[i] - arr[j]);
      if(dif > minMAx) {
        if(temp[j] == 0 && temp[i] == 0){
          minMAx = dif;
          index = j;
          found = true; 
        }
      }
    }
    if(found){
      swap(arr[i],arr[index]);
    }
    
    // cout << "index i = " << arr[i] << endl;
    // cout << "index j = " << arr[index] << endl;
    temp[index]++; // 1
  }

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  // 1 3 2 4
  // i = 1
  // 1 - 4 = max
  // swap
  // 4 3 2 1
  // i = 2
  // 3 - 2 

	return 0;
}
