#include <iostream>
using namespace std;

int subbaris(int arr[], int n){
	int counter = 0; 
	int a,b,c;
	//cara 1
	for(int i = 0; i < n ; i++){
		 a = arr[i];
		for (int j = i + 1; j < n;j++){
			b = arr[j];
			if(a > b){
				for(int k = j + 1; k < n; k++){
					 c = arr[k];
           if(b < c) counter++;
				}
			} else if(a < b){
          for(int k = j + 1; k < n; k++){
            c = arr[k];
            if(b > c) counter++;
				  }
        }
      }
		}
	// // cara 2
	// for(int i = 0; i < n ; i++){
	// 	 a = arr[i];
	// 	for (int j = i + 1; j < n;j++){
	// 		b = arr[j];
	// 		if(a < b){
	// 			for(int k = j + 1; k < n; k++){
	// 				 c = arr[k];
	// 				if(b > c) counter++;
	// 			}
	// 		}
	// 	}
	// }
	return counter;
}


int main(){
  int n, a;
  cin >> n;
  int sum[n + 5];

  for (int i=0; i<n; i++){
    cin >> a;
    int arr[a+5];	
    for (int i=0; i<a; i++){
      cin >> arr[i];
    }
    sum[i] = subbaris(arr,a);
  }

  for(int i = 0; i < n; i++){
    cout << sum[i] << endl;
  }

  return 0;
}