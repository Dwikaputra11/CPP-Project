#include <bits/stdc++.h>
using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    int start = a.back(), end = b.back();
    int count = 0;
    for(int i = start; i <= end; i++){
        bool aPass = true, bPass = true;
        for(const auto &ai : a){
            if(i % ai != 0){
                aPass = false;
                break;
            }
        }
        if(!aPass) continue;
        
        for(const auto &bi : b){
            if(bi % i != 0){
                bPass = false;
                break;
            }
        }
        
        if(aPass && bPass) count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
	vector<int> a , b;
	int n,m,temp;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> temp;
		a.push_back(temp);
	}
	for(int i = 0; i < m; i++){
		cin >> temp;
		b.push_back(temp);
	}

	getTotalX(a,b);

	return 0;
}
