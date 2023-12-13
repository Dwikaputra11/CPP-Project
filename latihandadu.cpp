#include <iostream>
#include <cstdlib> //mengandung fungsi random
using namespace std;



int main()
{
	//membuat drawing dadu
	/*for(int i = 0; i < 6; i++){
		cout << 1 + (rand() % 6) << endl;
	}*/

	char lanjut;
	while(true){
		cout << "Lempar dadu? (y/n)";
		cin >> lanjut;

		if (lanjut == 'y'){
			cout << 1 + (rand() % 6) << endl;
		}else if ( lanjut == 'n'){
			break;
		} else {
			cout << "WARNING: Ketik yang bener dong!!" << endl;
		}
	}

	cin.get();
	return 0;
}
