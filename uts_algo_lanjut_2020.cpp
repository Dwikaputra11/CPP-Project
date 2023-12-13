#include <iostream>
using namespace std;


// struct Tanggal{
//     int hari;
//     int bulan;
//     int tahun;
// };

// // typedef struct{
// //     // atribut
// // }ABC;

// struct Pemeriksaan{
//     Tanggal tgl;
//     string diagnosa;
//     string jenisPenyakit;
//     string pengobatan;
//     string paraf;
// };

// struct Biodata{
//     string nama;
//     int umur;
//     string alamat;
//     string pekerjaan;
//     string agama;
//     string gender[2] = {"laki-laki","perempuan"};
//     string namaKk;
//     int noKartu;
// };

// struct Pasien{
//     Biodata bio;
//     string jenisKunjungan;
//     string jenisPelayanan;
//     Pemeriksaan pemeriksaan[15];   
// };

// int main(){   

//     Pasien pasien[10];
//     cout << pasien[0].bio.gender[0] << endl;

//     // pasien[1].bio.nama;
//     // pasien[0].jenisKunjungan;
//     // pasien[0].pemeriksaan[1].tgl.tahun;

//     // pasien[3].jenisKunjungan;

//     // pasien[1].bio.nama;
//     // pasien[2].pemeriksaan[1].tgl.hari;

//     return 0;
// }


void findAndMeanInRange(int rangeMin, int rangeMax, int arr[][5]);
void findAndMeanInRange(int range, int arr[][5]);

int main(int argc, char const *argv[])
{
    int arr[2][5] = {
        {2, 5, 1, 2, 4},
        {6, 3, 2, 7, 1}
    };

    findAndMeanInRange(5,arr);
    
    return 0;
}
void findAndMeanInRange(int range, int arr[][5]){
    int total = 0; // untuk total jumlah dari nilai dalam range
    double n = 0; // banyak nilai yang masuk dalam range
    cout << "In Range " << range << " :\n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] < range){ // sequential search
                cout << arr[i][j] << " ";
                total = (total + arr[i][j]);// total += (double) arr[i][j]; // total =(double) (total + arr[i][j])
                n++;
            }
        }
    }
    total = 0 + 2; total = 2
    total = 2 + 1; total = 3

    double mean = (double) total/n;
    cout << "\nmean: " << mean << endl; 
}

void findAndMeanInRange(int rangeMin, int rangeMax, int arr[][5]){
    double total = 0;
    double n = 0;
    cout << "In Range " << rangeMin << " - " << rangeMax << " :\n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] < rangeMax && arr[i][j] > rangeMin){ // sequential search
                cout << arr[i][j] << " ";
                total += (double) arr[i][j]; // total = total + arr[i][j]
                n++;
            }
        }
    }

    double mean = (double) total/n;
    cout << "\nmean: " << mean << endl; 
}

// 1,2,3,4,5,6,7,8 cari --> 6
// bagi 2 array
// 0 + 8/2 = 4
// semisal ketemu di index tengah
// arr[tengah] -- nilai ada di index tengah
// kalu tidak
// cari > arr[tengah] --> 6 > 5 true
// awal = tengah + 1

// bagi 2 array
// (5 + 8)/2 = 6
// arr[1] = 7 == 6 ? false
// cari < arr[tengah]
// terakhir tengah - 1
// 0

// bagi 2 array
// (5 + 5)/2 = 0
// tengah = 0
// arr[tengah] == cari --> output tengah
// arr[0] index --> 5

// int recursion(int n, int step);

// int main(int argc, char const *argv[])
// {
//     cout << recursion(19, 0) << endl;
//     return 0;
// }

// int recursion(int n, int step){
//     // cout << "step: " << step++ << endl;
//     if(n == 0) return 1;
//     else if(n == 1) return -2;
//     else if(n == 2) return -1;
//     else return -3*recursion(n - 1, step) - 3*recursion(n - 2,step) - recursion(n - 3,step);
// }

// n = 4
// an = 3*a3 - 3*a2 + a1 
// analisis a1 --> 2
// an = 3*a3 - 3*a2 + 2
// analisis a2 --> 4
// an = 3*a3 - 3*4 + 2
// analisis a3 --> 3*a2 - 3*a1 + a0 = 3*4 - 3*2 + 1 = 12 - 6 + 1 = 7
// a4 = 3*7 - 3*4 + 2 = 21 - 12 + 2 = 9 + 2 =11




// int binary_search(int arr[], int find,int n){
//     int first = 0;
//     int last = n;
//     while(first <= last){
//         int mid = (first + last)/2;
//         if(arr[mid] == find)
//             return mid;
//         else if(find < arr[mid])
//             last = mid - 1;
//         else
//             first = mid + 1;
//     }
//     return -1;
// }

// int binary_search(int arr[], int f, int l, int x){ // f = first, l = last, x = cari
//     if(f <= l){
//         int mid = (f + l)/2;
//         if(arr[mid] == x)
//             return mid;
//         else if(x < arr[mid])
//             return binary_search(arr,f,mid-1,x);
//         else if(x > arr[mid])
//             return binary_search(arr,mid + 1, l, x);
//     }
//     return -1;
// }

// int seq_search(int arr[],int f,int l, int x){
//     if(f > l)
//         return -1;
//     else if(arr[f] == x)
//         return f;
//     else 
//         return seq_search(arr, f + 1,l, x);
// }


// int main(int argc, char const *argv[])
// {
//     int arr[5] = {3,5,6,7,10};
//     int l = sizeof(arr)/sizeof(arr[0]);
//     (binary_search(arr,7,l) == -1) ?
//         cout << "Bilangan tidak ada dalam array\n":
//         cout << "Bilangan berada dalam array\n";
//     // cout << binary_search(arr, 7,l);
//     // cout << binary_search(arr,0,l,5) << endl;
//     // (seq_search(arr,0,l,7) == -1) ?
//     //     cout << "Bilangan tidak ada dalam array\n":
//     //     cout << "Bilangan berada dalam array\n";

//     return 0;
// }
