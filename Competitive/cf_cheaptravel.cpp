#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,n,m;
	cin >> n >> m >> a >> b;
	int answer;

	if(m*a <= b){
		answer = a*n;
	}else{
		answer = (n/m)*b + min((n%m)*a,b);
	}

	cout << answer;
	return 0;
}