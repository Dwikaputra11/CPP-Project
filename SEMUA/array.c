/*
NIM : 18220084
Nama : Dewa Ayu Mutiara Kirana Praba Dewi
Tanggal : 15 September 2021
Topik praktikum : array (pra praktikum 2)
Deskripsi : implementasi dari array.h
*/

#include <stdio.h>
#include "array.h"

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArray (TabInt *T)
{
    (*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (TabInt T)
{
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
{
    return (IdxMax-IdxMin+1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
{
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType GetLastIdx (TabInt T)
{
    return T.Neff;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */

ElType GetElmt (TabInt T, IdxType i)
{
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout)
{
    *Tout = Tin;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */

/* Assignment THsl -> Tin */
void SetEl (TabInt *T, IdxType i, ElType v)
{
    (*T).TI[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabInt *T, IdxType N)
{
    (*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
{
    return ((i<= IdxMax) && (i>=IdxMin));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i)
{
    return ((i>= GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
{
    return (NbElmt(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
{
    return (NbElmt(T) == MaxNbEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
