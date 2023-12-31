//NIM : 18220084
//Nama : Dewa Ayu Mutiara Kirana Praba Dewi
//Tanggal : 21 September 2021
//Topik praktikum : mesin kata
//Deskripsi : pra praktikum

#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kar.c"


boolean EndKata;
Kata CKata;
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK){
        ADV();
    }
}
void SalinKata() //pokoknya tadi letak salahnya disini
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i;
    i=1; //NOTEEEEEE!!!! awalnya make nol ternyata salah 
    while ((CC!=BLANK) && (CC!= MARK)){
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i-1;
}
void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata = true;
    }else{
        EndKata = false;
        SalinKata();
    }
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC==MARK){
        EndKata = true;
    }else{
        EndKata = false;
        SalinKata();
        IgnoreBlank();
    }
}