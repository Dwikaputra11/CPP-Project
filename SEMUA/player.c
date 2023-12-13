#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "listlinier.h"
#include "skill.h"

void CreatePlayerEmpty(Player *P){
    jumlah(*P) = 0;
}

void InputPlayer(Player *P, int banyakPlayer){
    int i = 1;
    int j;
    int salah;
    boolean valid;
    jumlah(*P) = banyakPlayer;
    for (i; i <= banyakPlayer; i++){
        valid = false;
        printf("Masukkan Nama Player-%d: ", i);
        scanf("%s", &((*P).TabPlayer[i].pName));
        while(!valid){
            salah = 0;
            for (j = 1; j <= banyakPlayer; j++) {
                if ((!strcmp((*P).TabPlayer[i].pName, (*P).TabPlayer[j].pName)) && (i != j)){
                    salah++;
                    printf("Nama %s sudah ada!\n", (*P).TabPlayer[i].pName);
                    printf("Ganti nama player-%d: ", i);
                    scanf("%s", &((*P).TabPlayer[i].pName));
                }
            }
            if (salah == 0){
                valid = true;
            }else{
                valid = false;
            }
        }
        (*P).TabPlayer[i].nomorPemain = i;
        (*P).TabPlayer[i].position = 1;
        (*P).TabPlayer[i].isRolled = false;
        (*P).TabPlayer[i].isTeleported = false;
        (*P).TabPlayer[i].TabBuff[i].isImmuned = false;
        (*P).TabPlayer[i].TabBuff[i].isSenterPembesar = false;
        (*P).TabPlayer[i].TabBuff[i].isSenterPengecil = false;
        (*P).TabPlayer[i].TabBuff[i].isCerminGanda = false;
        First((*P).TabPlayer[i].skills) = NilPlayer;
    }
}

void showName (Player *P, int nomorPemain){
    printf("%s", (*P).TabPlayer[nomorPemain].pName);
}

void useSkill(Player *P, int inputs, int nomorPemain){
    if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 1){
        ((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isImmuned) = true;
        DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
    }
    else if(infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 2){
        if(NbElmt((*P).TabPlayer[nomorPemain].skills) <= 8 && (!(*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda)){
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda = true;
            cerminPengganda(&(*P).TabPlayer[nomorPemain].skills);
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }else{
            if (NbElmt((*P).TabPlayer[nomorPemain].skills) <= 9){
                printf("\nPunten skill maneh penuh, jadi ga bisa make skill ini\n");
            }else if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda)){
                printf("\nBuff cermin pengganda sudah aktif.");
            }
        }
    }
    else if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 3){
        if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar) || ((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil)){
            printf("\nPunten maneh lagi make skill Senter Pengecil, jadi gak bisa make Senter Pembesar\n");
        }else{
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }
    }
    else if(infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 4){
        if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar)|| ((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil)){
            printf("\nPunten maneh lagi make skill Senter Pembesar, jadi gak bisa make Senter Pengecil\n");
        }else{
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }
    }else if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 5){
        int i;
        for (i = 1; i<=jumlah(*P); i++){
            printf("%d. ", i);
            showName(&(*P), i);
            printf("\n");
        }
        printf("Pilih pemain untuk ditukar posisinya : ");
        int pilihan;
        scanf("%d", &pilihan);
        boolean valid = false;
        while (!valid){
            if (pilihan <= jumlah(*P) && pilihan >= 1){
                valid = true;
            }else{
                printf("Pilihan angka tidak valid\n");
                printf("Masukkan kembali angka sesuai nomor pemain yang tertera : ");
                scanf("%d", &pilihan);
            }
        }
        int posisi;
        posisi = (*P).TabPlayer[nomorPemain].position;
        (*P).TabPlayer[nomorPemain].position = (*P).TabPlayer[pilihan].position;
        (*P).TabPlayer[pilihan].position = posisi;
        DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
    }
    //else{
       // DeleteSkill(&((*P).TabPlayer[nomorPemain].skills), inputs);
    //}
}

