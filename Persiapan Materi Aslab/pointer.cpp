#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int *p, *q, a = 0;
	p = (int*) malloc(sizeof(int));
	*p = a;
	cout << &a <<  endl;
	cout << p << " " << q << "\n";


	return 0;
}