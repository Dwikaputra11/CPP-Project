#include <stdio.h>
#include <time.h>
#include "listlinier.h"
#include "skill.h"
#include "roll.h"
#include "player.h"
#include <stdlib.h>


int chance (int x){
    if ((x >= 1) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 30) && (x <= 45)){
        return 3;
    }
    else if((x >= 46) && (x <= 60)){
        return 4;
    }
    else if((x >= 61) && (x <= 70)){
        return 5;
    }
    else{
        return 0;
    }
}

void getSkill(List *skill){
    int x;
    time_t t;
    
    srand(time(0));
    x = rand();
    x = chance((x) % 100 + 1);
    if (x == 1){
        printf("Pintu Ga Ke Mana-Mana\n");
    }
    else if (x == 2){ 
        printf("Cermin Pengganda\n");
    }
    else if (x == 3){ 
        printf("Senter Pembesar Hoki\n");
    }
    else if (x == 4){ 
        printf("Senter Pengecil Hoki\n");
    }  
    else if (x == 5){ 
        printf("Mesin Penukar Posisi\n");
    }else{
        printf("Teknologi Gagal.\n");
    }

    if (x != 0 && NbElmt(*skill) <= 9){
        InsVLast(skill, x);
        printf("Skill ");
        printf("%d", x);
        printf(" berhasil dimasukkan\n");
        printf("\n");
    } 
    else if (x == 0 ){
        printf("Punten, kamu tidak mendapat skill \n");
        printf("\n");
    }

    else if (NbElmt(*skill) >= 10){
        printf("Punten, Jumlah skill udah penuh euy\n");
        printf("\n");
    }
}

void displaySkill(List skill){
    address p;
    int count = 1;
    char listSkill[][25] = {
        "",
        "Pintu Ga Ke Mana Mana",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    p = First(skill);
    printf("Kamu memiliki skill: \n");
    while(p != Nil){
        printf("%d. %s\n", count, listSkill[Info(p)]);
        count++;
        p = Next(p);
    }  
}

void BuangSkill (List *skill, int count){
    address p;
    char listSkill[][25] = {
        "",
        "Pintu Ga Ke Mana Mana",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    if (!(IsEmptyList(*skill))) {
        count = count * (-1);
        DeleteI(skill, count); 
    }
    else {
        printf("Anda tidak mempunyai skill \n");  
    }
};


void getSkill2(List *skill){
    int x;
    
    x = rand();
    x = chance((x) % 100 + 1);

    if (x == 1){
        printf("Pintu Ga Ke Mana-Mana\n");
    }
    else if (x == 2){ 
        printf("Cermin Pengganda\n");
    }
    else if (x == 3){ 
        printf("Senter Pembesar Hoki\n");
    }
    else if (x == 4){ 
        printf("Senter Pengecil Hoki\n");
    }  
    else if (x == 5){ 
        printf("Mesin Penukar Posisi\n");
    }else{
        printf("Teknologi Gagal.\n");
    }

    if (x != 0 && NbElmt(*skill) <= 9){
        InsVLast(skill, x);
        printf("Skill ");
        printf("%d", x);
        printf(" berhasil dimasukkan\n");
        printf("\n");
    } 
    else if (x == 0){
        printf("Punten, kamu tidak mendapat skill \n");
        printf("\n");
    }
    else if (NbElmt(*skill) >= 10){
        printf("Punten, Jumlah skill udah penuh euy\n");
        printf("\n");
    }
}

void cerminPengganda(List *skill){
    getSkill2(&(*skill));
    getSkill2(&(*skill)); 
}


/*void mainSkill(Player *P, int nomorPemain){
    int input;
    displaySkill((*P).TabPlayer[nomorPemain].skills);
    printf("\nMasukan SKill: ");
    scanf("%d", &input);
    boolean done = false;
    while (input != 0)
    {
        if (input > 0 && input <= NbElmt((*P).TabPlayer[nomorPemain].skills))
        {
            puts("");
            showName((&P), nomorPemain);
            printf(" memakai skill ");
            PrintSkillKe(((*P).TabPlayer[nomorPemain].skills), input);
            printf("\n");
            UseSkill(&P, input, nomorPemain);
            // DeleteSkill(&(PlayerSkills(*p)), inputs);
        }
        else if (input < 0)
        {
            input = input * (-1);
            puts("");
            showName((&P), nomorPemain);
            printf(" membuang skill ");
            PrintSkillKe((*P).TabPlayer[nomorPemain].skills, input);
            printf("\n");
            BuangSkill(&((*P).TabPlayer[nomorPemain].skills), input);
        }
        displaySkill((*P).TabPlayer[nomorPemain].skills);
        printf("\nMasukkan skill: ");
        scanf("%d", &input);
    }
    if (input == 0)
    {
        puts("");
        showName((&P), nomorPemain);
        printf(" keluar dari command SKILL\n");
    }
}   
*/