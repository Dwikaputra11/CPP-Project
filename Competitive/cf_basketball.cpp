#include <bits/stdc++.h>
#include <vector>
using namespace std;
// link: http://codeforces.com/problemset/problem/493/C
vector <long long int> first;
vector <long long int> second;

int main() {
  // int n, m,min = 999999;
  // int val,d;
  // int score1, score2 = 0;
  // cin >> n >> m;

  // for(int i = 0; i < n; i++){
  //   cin >> val;
  //     if(val < min) min = val;
  // }
  // score1 = n*3;
  // for(int i = 0; i < m; i++){
  //   cin >> val;
  //   if(val <= min){
  //     score2 +=2;
  //   }else{
  //     score2 +=3;
  //   }
  // }

  // cout << score1 << ":" << score2 << endl;

 	int n, m;
	long long int a, b, scoreA, scoreB, maxA = 0, maxB = 0, maxDiff;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		first.push_back(a);
	}
  first.push_back(2087654321);

	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> b;
		second.push_back(b);
	}
  second.push_back(2087654321);

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	maxA = scoreA = 3 * n;
	maxB = scoreB = 3 * m;
	maxDiff = scoreA - scoreB;
	for(int i = 0, j = 0; i < n || j < m; ) {
		if(first[i] < second[j]) {
			scoreA -= 1;
			i++;
		}else if(first[i] > second[j]) {
			scoreB -= 1;
			j++;
		}else {
			scoreA -= 1;
			scoreB -= 1;
			i++;
			j++;
		}
		if(scoreA - scoreB > maxDiff) {
			maxDiff = scoreA - scoreB;
			maxA = scoreA;
			maxB = scoreB;
		}
	}
	cout << maxA << ':' << maxB << endl;
	return 0;
}