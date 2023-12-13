#include <iostream>
#include <cmath>

using namespace std;

/*
libarary cmath : refrensi cppreference.com
ceil(x)			<- pembulatan ke atas
cos(x) 			<- cosinus
exp(x)			<- eksponen
fabs(x)			<- nilai absolut dalam float
floor(x)		<- pembulatan ke bawah
fmod(x)			<- modulus dalam float
log(x)			<- logaritma dengan batas natural
log10(x)		<- logaritma dengan basis 10 
pow(x,y)		<- x pangkat y
sin(x,y)		<- sinus
sqrt(x)			<- akar kuadrat
tan(x)			<- tangen
*/

int main()
{
	int x;

	cout << "Menghitung akar dari x: ";
	cin >> x;

	double y = sqrt(x);
	cout << "akarnya adalah: "<< y << endl;

	cin.get();
	return 0;
}
