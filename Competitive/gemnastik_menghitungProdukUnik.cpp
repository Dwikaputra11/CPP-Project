#include <iostream>
using namespace std;

int main()
{
	unsigned long min,max;

	unsigned long a,b,c,count = 0;

	cin >> min >> max;
	cin >> a >> b >> c;

	if(min == 0) count++;
	while(min <= max){
		if((min%a == 0) && (min%b != 0) && (min%c != 0)) count++;
		else if((min%a != 0) && (min%b == 0) && (min%c != 0)) count++;
		else if((min%a != 0) && (min%b != 0) && (min%c == 0)) count++;
		++min;
	}

	cout << count << endl;



	return 0;
}