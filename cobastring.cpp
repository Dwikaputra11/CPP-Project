#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    string str; // setiap akhir statement diakhiri dengan titik koma ;
    int asdm, aslmn, aadskfnmm;

    if(1 < 2){
        // statement
    }else if(3 == 5){
        // statement else if
    }else{

    }

    // sama dengan ==
    // tidak sama dengan !=

    cin.ignore();
    cout << "Masukkan str: ";
    cout << "sad " << endl;
    getline(cin, str);  
    // cin >> str;

    string opsi;
    char opsiChar;

    cout << "Y/N String : "; cin >> opsi;
    if(opsi == "Y") cout << "Iya String" << endl;
    else if(opsi == "N") cout << "Tidaks String" << endl;

    cout << "Y/N Char : "; cin >> opsiChar;
    if(opsiChar == 'Y') cout << "Iya Char" << endl;
    else if(opsiChar == 'N') cout << "Tidak Char" << endl;

    cout << str << endl;

    return 0;

}