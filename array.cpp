#include <iostream>
#include <array>
#include <string>

using namespace std;


int main()
{
	int arr[5] = {2,3,1,5,4};

	qsort(arr);
	for(int i = 0; i < 5; i++){
		cout << arr[i] << ", ";
	}


	return 0;
}
