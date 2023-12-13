#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct contoh{
	int b;
	string a;
};

// jadi gk perlu void swap lagi hehe
/*void Swap(int *a,int *b){
	// cout <<"a : "<< a << "b : " << b << endl;
	int *temp;
	*temp = *a;
	*a = *b;
	*b = *a;
}*/
/*void swap(string *a,string *b){
	cout << "Ini Swap String\n";
	cout <<"a : "<< *a << "b : " << *b << endl;
	string *temp;
	*temp = *a;
	*a = *b;
	*b = *a;
}*/


void prosesB(contoh c[],int n){
	for(int gap = n/2; gap > 0; gap/=2){
		for(int i = gap; i < n; i++){
			for(int j = i; j >= gap && c[j - gap].b > c[j].b; j-=gap){
				swap(c[j-gap].b,c[j].b);
			}
		}
	}
}

void prosesA(contoh c[],int n){
	for(int gap = n/2; gap > 0; gap/=2){
		for(int i = gap; i < n; i++){
			for(int j = i; j >= gap && c[j-gap].a > c[j].a; j-=gap){
				swap(c[j-gap].a,c[j].a);
				// swap diatas merupakan suatu fungsi pada c++/sublime yang otomatis menukar variabel biarpun pada string
				// menukarkan huruf yang beda ketika huruf depannya sama
			} 
		}
	}
}


int main()
{
	int n;
	cout << "Masukkan banyak : "; cin >> n;
	contoh c[n];
	for(int i = 0; i < n; i++){
		cout << "integer b : "; cin >> c[i].b;cin.ignore();
		cout << "String a : "; getline(cin,c[i].a);
	}
	prosesB(c,n);
	prosesA(c,n);

	cout << "sort b\n";
	for(int i = 0; i < n; i++){
		if(i == n-1) cout << c[i].b << endl<<endl;
		else cout << c[i].b << ",";
	}
	cout << "sort a\n";
	for(int i = 0; i < n; i++){
		if(i == n-1) cout << c[i].a << endl<<endl;
		else cout << c[i].a << ",";
	}
	

	return 0;
}