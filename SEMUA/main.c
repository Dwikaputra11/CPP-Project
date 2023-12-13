#include "command.h"
#include "command.c"
#include <stdio.h>
#include "mesin_kar.h"
#include "mesin_kata.h"
#include "mesin_kar.c"
#include "mesin_kata.c"
#include "boolean.h"
#include "teleporter.h"
#include "roll.h"
#include "map.h"
#include "teleporter.c"
#include "roll.c"
#include "map.c"
#include "player.h"
#include "player.c"
#include "listlinier.h"
#include "listlinier.c"
#include <string.h>
#include "skill.h"
#include "skill.c"


int main(){
    Map map;
    Player P;
    boolean menang = false;
    ConfigureMap(&map);
    int jumlahorang;
    int giliran;
    printf ("Ada berapa yang main? ");
    scanf("%d", &jumlahorang);
    boolean valid = false;
    while (!valid){
        if (jumlahorang > 4 || jumlahorang <= 1){
            printf("jumlah orang tidak valid\n");
            printf("masukkan kembali jumlah orang : ");
            scanf("%d", &jumlahorang);
        }else{
            valid = true;
        }
    }
    InputPlayer(&P, jumlahorang);
    int n = 1;
    while (!menang){
        printf ("\n               RONDE-%d\n", n);
        giliran = 1;
        while(giliran <= jumlahorang && (!menang)){
            int nomorPemain;
            printf("\n========== POSISI SAAT INI ==========\n\n");
            for (nomorPemain = 1; nomorPemain <= jumlah(P); nomorPemain++){
                printf("%s  : ", (P).TabPlayer[nomorPemain].pName);
                for (int i=1; i <= Length(map); i++){
                    if (i != (P).TabPlayer[nomorPemain].position){
                        printf("%c", (map).Config.TI[i]);
                    }else{
                        printf("%c", '*');
                    }
                }
                printf("  %d\n", (P).TabPlayer[nomorPemain].position);
            }
            printf("\n====================================\n\n");
            printf("\nGiliran ->  ");
            showName(&P, giliran);
            printf("\n");
            getSkill(&((P).TabPlayer[giliran].skills));
            command(&map, &P, giliran);
            if ((P).TabPlayer[giliran].position == Length(map)){
                menang = true;
            }
            giliran++;
        }
        int nomorPem;
        for (nomorPem = 1; nomorPem <= jumlah(P); nomorPem++){
            (P).TabPlayer[nomorPem].isRolled = false;
        }
        n++;
    }
}