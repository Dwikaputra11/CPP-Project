#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N,a,b;
	cin >> N >> a >> b;
	char map[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) cin >> map[i][j];
	}
	
	int ver = 0,hor = 0;
	int way = 0;

	if(map[a-1][b-1] == 'x') cout << "-1";
	else{
		way++;
		for(int i = 0; i < N; i++){
			int countX = 0;
			for(int j = 0; j < N; j++){
				// cout << "Process...\n";
				if(map[i][j] == '.' && j == countX){

				}
				else{
					countX++;
				}
			}
			if(countX == N){
				cout << "-1"; break;
			}
		}
	}

	cout << way;
	return 0;
}
