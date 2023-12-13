#include <iostream>
using namespace std;

// link : https://tlx.toki.id/courses/competitive/chapters/01/problems/B
int r,c;
char arr[21][9]; // jangan make int karena kemungkinan banyak makek memori

int findLastRow(){
	int lastRow = 0;
	for(int row = 1; row <= r; row++){
		bool containAllBlackPixels = true;
		for(int col = 1; col <= c; col++){
			if(arr[row][col] != '1')
				containAllBlackPixels = false;
		}
		if(containAllBlackPixels){
			for(int col = 1; col <= c; col++){
				arr[row][col] = '0';
			}
			lastRow = row;
		}
	}
	return lastRow;
}

int findLastRowToFall(int lastRow, int col){
	for(int row = lastRow; row <= r; row++){
		if(arr[row+1][col] == '1' || row == r)
			return row;
	}
	return 0;
}

int countBlackPixelsAbove(int lastRow, int col){
	int blackPixels = 0;
	for(int row = lastRow; row >= 1; row--){
		if(arr[row][col] == '1')
			blackPixels++;
	}
	return blackPixels;
}

void collapse(int blackPixels, int lastRow, int col){
	for(int row = lastRow; row >= 1; row--){
		if(row > lastRow - blackPixels)
			arr[row][col] = '1';
		else
			arr[row][col] = '0';
	}
}

int main()
{
	cin >> r >> c;

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> arr[i][j];
		}
	}

	int lastRow = findLastRow();
	int i = 0;
	while(lastRow > 0){
		// cout << "coba " << ++i << endl;
		for(int col = 1; col <= c; col++){
			int blackPixels = countBlackPixelsAbove(lastRow, col);
			int lastRowToFall = findLastRowToFall(lastRow, col);
			collapse(blackPixels, lastRowToFall, col);
		}
		lastRow = findLastRow();
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}


	return 0;
}
