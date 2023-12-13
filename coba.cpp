#include <iostream>
using namespace std;

int vcon(int x,int y = 5,int z= 0){
	int res = z;
	while(x < 100000){
		if(y%2 != 0){
			res = x + y%2;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = vcon(10,4);

	for(int i = 1; i <999999; i++){
		cout << "p ";
		n = vcon(n);
	}

	cout << n;

	return 0;
}
