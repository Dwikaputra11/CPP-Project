#include <iostream>
using namespace std;

int main()
{
	char jnsKelamin;
	string pddk;
	int umur;
	int prog = 0, opt = 0, sekre = 0, mnjr = 0;
	cout << "Jenis Kelamin L/P : "; cin >> jnsKelamin;
	if(jnsKelamin == 'L'){
		prog++; 
		mnjr++;
		opt++;
	}else{
		sekre++; 
		prog++; 
		mnjr++; 
	}
	cout << "Umur : "; cin >> umur;
	if(umur >= 17 && umur <= 25){ 
		opt++; 
		sekre++; 
		prog++; 
	}else if(umur > 25 && umur <= 35){
		opt++;
		sekre++;
		prog++;
		mnjr++;
	}else if(umur > 35 && umur <= 40){
		prog++;
		mnjr++;
	}
	cout << "Tingkat Pendidikan : "; cin >> pddk;
	if(pddk == "SMA"){
		opt++;
		sekre++;
	}else if(pddk == "D3"){
		opt++; 
		sekre++; 
		prog++; 
	}else if(pddk == "S1"){
		sekre++;
		prog++; 
		mnjr++;
	}else if(pddk == "S2"){
		mnjr++;
	}

	cout << "Pekerjaraan yang Dapat Ditawarkan : ";
	if(opt == 3 || sekre == 3 || prog  == 3 || mnjr == 3){
		if(opt == 3) cout << "Operator ";
		if(sekre == 3) cout << "Sekretaris ";
		if(prog == 3) cout << "Programmer ";
		if(mnjr == 3) cout << "Manajer ";
	}else cout << "Tidak Ada";




	return 0;
}
