#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "masukkan angka : ";
	cin >> a ;

	// if statement
	// kondisi dalam bentuk boolean
	if (a > 3) // kondisi : perintah harus dipenuhi
	{
		cout << "nilai ini lebih dari 3" << endl;
	} //body : output jika sudah melaksanakan/angka yang dimasukkan true
	else if (a == 3){
		cout << "nilai ini sama dengan 3" << endl;
	}
	else if (a == 5){
		cout << "nilai ini 5 dan lebih dari 3" << endl; 
	}

	else {
		cout << "nilai ini kurang dari 3" << endl;
	}
	
	cout << "Done" << endl;

	

	cin.get();
	cin.get();
	return 0;
}
