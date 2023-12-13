#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int *ptr;
	ptr = (int*) malloc(5*sizeof(int));
	cout << "Enter 5 integers" << endl;

	for (int i=0; i<5; i++)
	{
	// *(ptr+i) can be replaced by ptr[i]
		cin >> *(ptr+i);
	}
	cout << endl << "User entered value"<< endl;

	for (int i=0; i<5; i++)
	{
		cout << "Address : " << ptr + i << endl;
		cout << "Value : " << *(ptr + i) << endl;
	}
	free(ptr);

	/* prints a garbage value after ptr is free */
	cout << "\n\nGarbage Value" << endl;

	for (int i=0; i<5; i++)
	{
		cout << "Address : " << ptr + i << endl;
		cout << "Value : " << *(ptr + i) << endl;

	}
	return 0;
}