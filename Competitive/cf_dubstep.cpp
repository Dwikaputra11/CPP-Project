#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char song[205] = {'\0'};
	cin >> song;
	int p = strlen(song);

	for(int i = 0; i < p; i++){
		if(song[i] == 'W' && song[i + 1] == 'U' && song[i + 2] == 'B'){
			song[i] = '0';
			song[i + 1] = '0';
			song[i + 2] = '0';
		}
	}
	int start;
	for(int i = 0 ; i < p; i++){
		if(song[i] != '0'){
			start = i;
			break;
		}
	}

	for(int i = start; i < p; i++){
		if (song[i] == '0'){
			cout << " ";
			for(int j = i; j < p; j++){
				if(song[i] != '0'){
					i = j - 1; break;
				}
			}
		}else{
			cout << song[i];
		}
	}


	return 0;
}