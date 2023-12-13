#include <iostream>
using namespace std;

// link : https://tlx.toki.id/courses/competitive/chapters/03/problems/B
int n,m,k;
int board[101][101];
int uniqueValue[100][100];

int columnNeighbor(int row, int column){
	if(row == 1)
		return board[row + 1][column];
	else if(row == n)
		return board[row - 1][column];
	else 
		return board[row - 1][column] * board[row + 1][column];
}
int rowNeighbor(int row, int column){
	if(column == 1)
		return board[row][column + 1];
	else if(column == m)
		return board[row][column - 1];
	else
		return board[row][column + 1] * board[row][column - 1];
}

void findSameWithK(int k){
	int r = 0,c = 0;
	bool isFound = false;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(uniqueValue[i][j] == k){
				// cout <<  "index --> i: " << i << " j: " << j << endl;
				if(!isFound){
					r = i;
					c = j;
					isFound = true;
				}else{
					if(j <= c){
						if(j == c){
							if(i < r) 
								r = i;
						}else{
							c = j;
							r = i;
						}	
					}
				}
				// cout <<  "r: " << r << " c: " << c << endl;
			}
		}
	}
	// cout << "isFound: " << isFound << endl;
	if(isFound)
		cout << r << " "<< c;
	else
		cout << 0 << " " << 0; 
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) 
			cin >> board[i][j];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) 
			uniqueValue[i][j] = columnNeighbor(i,j) * rowNeighbor(i,j);
	}

	findSameWithK(k);


	return 0;
}
