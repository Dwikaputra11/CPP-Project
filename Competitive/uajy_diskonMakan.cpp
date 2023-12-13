#include <iostream>
using namespace std;

#define ll long long

void ans(ll m, ll d,ll md,ll hp,ll jp){
    ll hNDiskon = jp * hp;
    ll hDiskon = 0;
    if(hNDiskon > m){
        ll hPotongan = hNDiskon - (hNDiskon*d)/100;
        if(hPotongan > md){
            hPotongan = md;
        }
        hDiskon = hNDiskon - hPotongan;
        cout << hDiskon;
    }else{
        cout << hNDiskon ;
    }
}

int main(int argc, char const *argv[])
{
    ll m,d,md,hp,jp;
    cin >> m >> d >> md >> hp >> jp;
    ans(m, d, md, hp, jp);
    return 0;
}

/**
 * #include <iostream>
using namespace std;

int main(int argc, char const argv[])
{
    unsigned int min, persen, max, harga, porsi, jumlah, diskon=0;

    cin >> min >> persen >> max >> harga >> porsi;

    jumlah = harga*porsi;
    if(jumlah >= min){
        diskon = jumlah*persen/float(100);

        if(diskon>max){
            diskon = max;
        }
    }

    cout << jumlah - diskon << endl;
    return 0;
}
 * 
 */