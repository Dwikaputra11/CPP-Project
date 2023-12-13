#include <iostream>

using namespace std;

int main()
{
	/*for (inisialisasi; loop kondisi; increment){
	statement
	} */

	cout << "awal for loop" << endl;

	cout << "Loop 1\n";
	for (int i = 1; i<=10 ;i++ ){
		cout << i << endl;
	}
	cout << endl;

	cout << "Loop 2\n";
	for (int i = 1; i<=10 ;i+=2 ){
		cout << i << endl;
	}
	cout << endl;

	cout << "Loop 3\n";
	for (int i = 1; i>=-10 ;i-- ){
		cout << i << endl;
	}
	cout << endl; 

	int total = 0;
	cout << "Loop 4\n";
	for (int i = 1; i<=10 ;i++ ,total += i  ){
		cout << i << "||" << total << endl;
	}
	cout << endl;

	/* cout << "Loop 5\n";
	for (int i = 1; i<=10 ;total += i, i++ ){
		cout << i << "||" << total << endl;
	}
	cout << endl;

	cout << "Loop 6\n";
	for (int i = 1; i<=10 ;i++ ){
		total += i;
		cout << i << "||" << total << endl;
	} */



	cout << "akhir dari program " << endl;

	cin.get();
	cin.get();
	return 0;
}
