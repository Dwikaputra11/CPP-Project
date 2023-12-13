#include <iostream>
using namespace std;

int main()
{
	
	// while(syarat){aksi}


	int a = 5; //kalo gk ada pembatasnya dia akan ngulang terus
	while(a < 10){
		cout << "hore";
		cout << a << endl;
		a += 1; //ini supaya tidak berulang terus makanya diisi nilai yang salah
	}

	cin.get();
	cin.get();
	return 0;
}
