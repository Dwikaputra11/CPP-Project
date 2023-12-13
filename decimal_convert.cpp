#include <iostream>
using namespace std;

void decToBinary(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    int binaryNum[32];
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // cout << "Biner: ";
    for (int j = i - 1; j >= 0; j--)
    {
        cout << binaryNum[i];
    }
}

int main()
{
    int bilanganDesimal;

    // Input bilangan desimal
    cout << "Masukkan bilangan desimal: ";
    cin >> bilanganDesimal;

    // Konversi ke biner
    cout << "Biner: ";
    decToBinary(bilanganDesimal);
    cout << endl;

    // Konversi ke oktal
    cout << "Oktal: " << oct << bilanganDesimal << endl;

    // Konversi ke heksadesimal
    cout << "Heksadesimal: " << hex << bilanganDesimal << endl;
    return 0;
}
