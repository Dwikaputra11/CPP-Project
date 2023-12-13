#include <iostream>
using namespace std;

int main()
{
    int x = 4; // jarak enter untuk mengerluarkan "-"
	int y = 2; // jarak enter untuk mengeluarkan nomor atau karakter
	int t = 0; // untuk index dalam pengecekan nomor dari player1
	int a = 0; // untuk index dalam pengecekan nomor dari player2
	
	for(int i = 0; i < 25; i++){
		int p = 9; // jarak spasi untuk memunculkan "|"
        if(i == x){
            for(int j = 0; j < 39; j++){
                if(j >= 18 && j <= 21){
                    cout << " ";
                }else{
                    cout << "-";
                }
            }
            cout << endl;
            x+=4;
        }else if(i == y){
            int r = 5; // jarak spasi untuk memunculkan nomor
			y = y + 4;
            for(int j = 1; j < 39; j++ ){
                if(j == p){
                    cout << "|";
                    if(p == 18){
                        p += 13;
                    }else{
                        p += 9;
                    }
                }else 
                if(j == r){
                    cout << "O" ;
                    if(r == 14){
                        r += 13;
                    }else{
                        r = r + 9;
                    }	
                }else if(j == 22){
                    cout << "|";
                }else {
                    cout << " ";// spasi pada baris yang muncul angka
                }
            }
            cout << endl;
        }else{
            int num = 0;
            for(int j = 1; j < 39; j++ ){
                // if(j == 27){
                //     cout << " " << endl;
                // }
                if(j == p){
                    cout << "|";
                    if(p == 18){
                        p += 13;
                    }else{
                        p = p + 9;
                    }
                }else if(j == 22){
                    cout << "|";
                }else{
                    cout << " ";
                }	
            }
            cout << endl;
        }	
	}


    return 0;
}
