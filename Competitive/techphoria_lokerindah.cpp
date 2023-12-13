#include <bits/stdc++.h>
using namespace std;

char in[1000], out[1000];
bool check[3];
void chekck3(int index){
	int temp1,temp;
	int a = 0;
	for(int i = index; i < index + 3; i++){
		if(in[i] < out[i])
			temp = out[i]-in[i];
		else 
			temp = in[i] - out[i];
		temp1 = 10 - temp;
		if(temp1 < temp) check[a] = true;
		else check[a] = false;
		a++;
	}
}


int main()
{	
	cin >> in >> out;
	int size = sizeof(in)/sizeof(in[0]) - 1;
	for(int i = 0; i < size; i++){
		
	}
	// char a = '1' - '3';
	// int b = a;
	// cout <<"\'" << a <<" \'" ;


	return 0;
}
