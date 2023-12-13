#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int *a, *b,*c;
	a = (int*) malloc(sizeof(int));
	c = (int*) malloc(sizeof(int));
	int p = 100,q = 50;
	*a = 2*q;
	b = &p;
	*c = 2*(*b + 25);
	p = q + 100;
	b = a;
	// *b = p;
	// a = &p;
	int *d;
	// int *e;
	// e = (int*) malloc(sizeof(int));


	cout << "Nilai p = " << p << endl;
	cout << "Nilai q = " << q << endl;
	cout << "Nilai *a = " << *a << endl;
	cout << "Nilai *b = " << *b << endl;
	cout << "Nilai *c = " << *c << endl;
	cout << "Nilai *d = " << *d << endl;
	// if(e) cout << "ada" << endl;
	// cout << "Nilai *e = " << *e << endl;


	// *b = 10;
	cout << "Nilai &a = " << &a << endl;
	cout << "Nilai a = " << a << endl;
	cout << "Nilai *a = " << *a << endl;
	cout << "Nilai &b = " << &b << endl;
	cout << "Nilai b = " << b << endl;
	cout << "Nilai *b = " << *b << endl;
	cout << "Nilai p = " << p << endl;
	cout << "Nilai &p = " << &p << endl;
	cout << "Nilai q = " << q << endl;
	cout << "Nilai &q = " << &q << endl;


	return 0;
}
