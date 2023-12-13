#include <iostream>
#include <vector>

using namespace std;

vector<long long> num;
long long X,Y;

long long findX(long long find, long long n){
	long long low = 0;
	long long up = n - 1;
	while(low <= up){
		long long mid = (up + low)/2;
		// cout << "mid in X: " << mid << endl;
		if(find < num[0]) return 0;
		else if(num[mid] == find) return mid;
		else if(num[mid] > find && num[mid - 1] < find) return mid;
		else if(num[mid] < find) low = mid + 1;
		else if(num[mid] > find) up = mid - 1;
	}
	return -1;
}
long long findY(long long find, long long n){
	long long low = 0;
	long long up = n - 1;
	while(low <= up){
		long long mid = (up + low)/2;
		// cout << "mid in Y: " << mid << endl;
		if(find >= num[n - 1]) return n - 2;
		else if(find == num[mid]) return mid - 1;
		else if(num[mid] <= find && num[mid + 1] > find) return mid;
		else if(num[mid] < find) low = mid + 1; 
		else if(num[mid] > find) up = mid - 1;
	}
	return -1;
}

int main()
{
	int n,a;
	cin >> n;
	while(n--){
		cin >> a;
		num.push_back(a);
	}
	int x,y,q;
	cin >> q;
	while(q--){
		cin >> x >> y;
		X = findX(x,num.size());
		Y = findY(y,num.size());
		// cout << "X : " << X << " Y: " << Y << " --> " << Y - X  + 1<< endl;
		cout << Y - X + 1 << endl;
	}	

	return 0;
}
