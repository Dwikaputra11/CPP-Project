#include "command.h"
#include <stdio.h>
#include "mesin_kar.h"
#include "mesin_kata.h"
#include "boolean.h"
#include "teleporter.h"
#include "roll.h"
#include "map.h"
#include "player.h"
#include <string.h>
#include "skill.h"

boolean IsSkill(Kata kata){
    int bener = 0;
    int Length_skill = 5;
    char SKILL[5] = {'S', 'K', 'I', 'L', 'L'};
    char skill[5] = {'s', 'k', 'i', 'l', 'l'};
    for(int i = 1; i <= kata.Length; i++){

        if ((CKata.TabKata[i] == SKILL[i-1]) || (CKata.TabKata[i] == skill[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_skill){
        if (bener == Length_skill){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsMap(Kata kata){
    int bener = 0;
    int Length_map = 3;
    char MAP[3] = {'M', 'A', 'P'};
    char map[3] = {'m', 'a', 'p'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == MAP[i-1]) || (CKata.TabKata[i] == map[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_map){
        if (bener == Length_map){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsBuff(Kata kata){
    int bener = 0;
    int Length_buff = 4;
    char BUFF[4] = {'B', 'U', 'F', 'F'};
    char buff[4] = {'b', 'u', 'f', 'f'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == BUFF[i-1]) || (CKata.TabKata[i] == buff[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_buff){
        if (bener == Length_buff){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsInspect(Kata kata){
    int bener = 0;
    int Length_inspect = 7;
    char INSPECT[7] = {'I', 'N', 'S', 'P', 'E', 'C', 'T'};
    char inspect[7] = {'i', 'n', 's', 'p', 'e', 'c', 't'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == INSPECT[i-1]) || (CKata.TabKata[i] == inspect[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_inspect){
        if (bener == Length_inspect){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsRoll(Kata kata){
    int bener = 0;
    int Length_roll = 4;
    char ROLL[4] = {'R', 'O', 'L', 'L'};
    char roll[4] = {'r', 'o', 'l', 'l'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == ROLL[i-1]) || (CKata.TabKata[i] == roll[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_roll){
        if (bener == Length_roll){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsSave(Kata kata){
    int bener = 0;
    int Length_save = 4;
    char SAVE[4] = {'S', 'A', 'V', 'E'};
    char save[4] = {'s', 'a', 'v', 'e'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == SAVE[i-1]) || (CKata.TabKata[i] == save[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_save){
        if (bener == Length_save){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsEndturn(Kata kata){
    int bener = 0;
    int Length_endturn = 7;
    char ENDTURN[7] = {'E', 'N', 'D', 'T', 'U', 'R', 'N'};
    char endturn[7] = {'e', 'n', 'd', 't', 'u', 'r', 'n'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == ENDTURN[i-1]) || (CKata.TabKata[i] == endturn[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_endturn){
        if (bener == Length_endturn){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsUndo(Kata kata){
    int bener = 0;
    int Length_undo = 4;
    char UNDO[4] = {'U', 'N', 'D', 'O'};
    char undo[4] = {'u', 'n', 'd', 'o'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == UNDO[i-1]) || (CKata.TabKata[i] == undo[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_undo){
        if (bener == Length_undo){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void command(Map *map, Player *P, int giliran){
    boolean endturn = false;
    while (!endturn){
        printf ("Masukkan command: ");
        STARTforCommand();
        int maxroll = MaxRoll(*map);
        if (IsSkill(CKata)){
            if (NbElmt((*P).TabPlayer[giliran].skills) == 0){
                printf("Kamu ga punya skill apa apa nih :(\n");
            }else{
                printf("Kamu memiliki skill: \n");
                displaySkill((*P).TabPlayer[giliran].skills);
                printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
                int input;
                printf ("Masukkan skill: ");
                scanf("%d", &input);
                while (input != 0 && NbElmt((*P).TabPlayer[giliran].skills) != 0){
                    if (input > 0 && input <= NbElmt((*P).TabPlayer[giliran].skills))
                    {
                        puts("");
                        showName(&(*P), giliran);
                        printf(" memakai skill ");
                        PrintSkillKe(((*P).TabPlayer[giliran].skills), input);
                        printf("\n");
                        useSkill((&(*P)), input, giliran);
                    }
                    else if (input < 0)
                    {
                        input = input * (-1);
                        puts("");
                        showName(&(*P), giliran);
                        printf(" membuang skill ");
                        PrintSkillKe((*P).TabPlayer[giliran].skills, input);
                        printf("\n");
                        BuangSkill(&((*P).TabPlayer[giliran].skills), input);
                    }else{
                        printf("Inputan angkamu salah!\n");
                    }
                    printf("Kamu memiliki skill: \n");
                    displaySkill((*P).TabPlayer[giliran].skills);
                    printf("\nMasukkan skill: ");
                    scanf("%d", &input);
                }
                if (input == 0)
                {
                    puts("");
                    showName(&(*P), giliran);
                    printf(" keluar dari command SKILL\n");
                }    
            }
        }else if (IsMap(CKata)){
            int nomorPemain;
            printf("\n========== POSISI SAAT INI ==========\n\n");
            for (nomorPemain = 1; nomorPemain <= jumlah(*P); nomorPemain++){
                printf("%s  : ", (*P).TabPlayer[nomorPemain].pName);
                for (int i=1; i <= Length(*map); i++){
                    if (i != (*P).TabPlayer[nomorPemain].position){
                        printf("%c", (*map).Config.TI[i]);
                    }else{
                        printf("%c", '*');
                    }
                }
                printf("  %d\n", (*P).TabPlayer[nomorPemain].position);
            }
            printf("\n====================================\n\n");
        }else if (IsBuff(CKata)){
            int Buff = 0;
            if ((*P).TabPlayer[giliran].TabBuff[giliran].isImmuned){
                printf("Buff Imunitas Teleport Aktif.\n");
                Buff++;
            }
            if ((*P).TabPlayer[giliran].TabBuff[giliran].isCerminGanda){
                printf("Buff Cermin Pengganda Aktif.\n");
                Buff++;
            }
            if((*P).TabPlayer[giliran].TabBuff[giliran].isSenterPembesar){
                printf("Buff Senter Pembesar Hoki Aktif.\n");
                Buff++;
            }
            if ((*P).TabPlayer[giliran].TabBuff[giliran].isSenterPengecil){
                printf("Buff Senter Pengecil Hoki Aktif. \n");
                Buff++;
            }
            if (Buff == 0){
                printf("Belum ada buff yang aktif.\n");
            }
        }
        else if (IsInspect(CKata)){
            int nomorPetak;
            printf("Masukkan petak: ");
            scanf("%d", &nomorPetak);
            if ((*map).Config.TI[nomorPetak] == '#'){
                printf("Petak %d merupakan petak terlarang.\n", nomorPetak);
                printf("\n");
            }else{
                if (teleport(nomorPetak) != nomorPetak){
                    printf("Petak %d memiliki teleporter menuju %d.\n", nomorPetak, teleport(nomorPetak));
                    printf("\n");
                }else{
                    printf("Petak %d merupakan petak kosong.\n", nomorPetak);
                    printf("\n");
                }
            }
        }
        else if (IsRoll(CKata)){
            if (!((*P).TabPlayer[giliran].isRolled)){
                int hasil_roll;
                int rollmaju, rollmundur;
                if ((*P).TabPlayer[giliran].TabBuff[giliran].isSenterPembesar){
                    hasil_roll = roll(1, maxroll);
                    (*P).TabPlayer[giliran].TabBuff[giliran].isSenterPembesar = false;
                }else if ((*P).TabPlayer[giliran].TabBuff[giliran].isSenterPengecil){
                    hasil_roll = roll(2, maxroll);
                    (*P).TabPlayer[giliran].TabBuff[giliran].isSenterPengecil = false;
                }else{
                    hasil_roll = roll(3, maxroll);
                }
                rollmaju = ((*P).TabPlayer[giliran].position) + hasil_roll;
                rollmundur = ((*P).TabPlayer[giliran].position) - hasil_roll;
                showName(&(*P), giliran);
                printf(" mendapatkan angka %d\n", hasil_roll);
                int move = 0;
                if ((rollmaju <= Length(*map)) && (rollmundur >= 1) && ((*map).Config.TI[rollmaju] != '#') && ((*map).Config.TI[rollmundur] != '#')){
                    showName(&(*P), giliran);
                    printf(" dapat maju dan mundur.\n");
                    printf("Kemana ");
                    showName(&(*P), giliran);
                    printf(" mau bergerak?\n");
                    printf("1. %d\n", rollmundur);
                    printf("2. %d\n", rollmaju);
                    int choosenMove;
                    printf("Masukkan pilihan : ");
                    scanf("%d", &choosenMove);
                    boolean valid = false;
                    while (!valid){
                        if (choosenMove == 2 || choosenMove == 1){
                            valid = true;
                            if (choosenMove == 1){
                                ((*P).TabPlayer[giliran].position) = rollmundur;
                                showName(&(*P), giliran);
                                printf(" mundur %d langkah.\n", hasil_roll);
                                showName(&(*P), giliran);
                                printf(" berada di petak %d.\n", (*P).TabPlayer[giliran].position);
                            }else{
                                ((*P).TabPlayer[giliran].position) = rollmaju;
                                showName(&(*P), giliran);
                                printf(" maju %d langkah.\n", hasil_roll);
                                showName(&(*P), giliran);
                                printf(" berada di petak %d.\n", (*P).TabPlayer[giliran].position);
                            }
                        }else{
                            printf("Pilihan angka tidak valid\n");
                            printf("Masukkan kembali angka 1 atau 2 sesuai petak yang dipilih : ");
                            scanf("%d", &choosenMove);
                        }
                    }
                    move = 1;
                }else if (((*map).Config.TI[rollmaju] != '#') && (rollmaju <= Length(*map))){
                    (*P).TabPlayer[giliran].position = rollmaju;
                    showName(&(*P), giliran);
                    printf(" dapat maju.\n");
                    showName(&(*P), giliran);
                    printf(" maju %d langkah.\n", hasil_roll);
                    showName(&(*P), giliran);
                    printf(" berada di petak %d.\n", (*P).TabPlayer[giliran].position);
                    move = 2;
                }else if(((*map).Config.TI[rollmundur] != '#') && (rollmundur >= 1)){
                    (*P).TabPlayer[giliran].position = rollmundur;
                    showName(&(*P), giliran);
                    printf(" dapat mundur.\n");
                    showName(&(*P), giliran);
                    printf(" mundur %d langkah.\n", hasil_roll);
                    showName(&(*P), giliran);
                    printf(" berada di petak %d.\n", (*P).TabPlayer[giliran].position);
                    move = 3;
                }else{
                    showName(&(*P), giliran);
                    printf(" tidak dapat bergerak.\n");
                }
                if (move != 0){
                    if (AllMap(*map).TI[(*P).TabPlayer[giliran].position] == 2){
                        showName(&(*P), giliran);
                        printf(" tidak menemukan teleporter.\n");
                    }else{
                        printf("**");
                        showName(&(*P), giliran);
                        printf(" menemukan teleporter.\n");
                        if (!((*P).TabPlayer[giliran].TabBuff[giliran].isImmuned)){
                            showName(&(*P), giliran);
                            printf(" tidak memiliki imunitas teleport.\n");
                            (*P).TabPlayer[giliran].position = teleport((*P).TabPlayer[giliran].position);
                            showName(&(*P), giliran);
                            printf(" teleport ke petak %d.\n", (*P).TabPlayer[giliran].position);
                        }else{
                            showName(&(*P), giliran);
                            printf(" memiliki imunitas teleport.\n");
                            printf("Apakah ");
                            showName(&(*P), giliran);
                            printf(" ingin teleport (Y/N)?");
                            char tel;
                            scanf("%c", &tel);
                            boolean valid = false;
                            while (!valid){
                                if (tel == 'N' || tel == 'Y'){
                                    valid = true;
                                    if (tel == 'N'){
                                        showName(&(*P), giliran);
                                        printf(" tidak teleport.\n"); 
                                        printf("Buff imunitas teleport hilang.\n"); 
                                        (*P).TabPlayer[giliran].TabBuff[giliran].isImmuned = false;
                                    }else{
                                        (*P).TabPlayer[giliran].position = teleport((*P).TabPlayer[giliran].position);
                                        showName(&(*P), giliran);
                                        printf(" teleport ke petak %d.\n", (*P).TabPlayer[giliran].position);
                                    }
                                }else{
                                    printf("Salah input. Hanya bisa membaca input Y untuk iya dan N untuk tidak.\n");
                                    printf("Masukkan input kembali : ");
                                    scanf("%c", &tel);
                                }
                            }
                        }
                    }
                }
                (*P).TabPlayer[giliran].isRolled = true;
            }else{
                printf("Tidak bisa roll 2 kali.\n");
            }
            if ((*P).TabPlayer[giliran].position == Length(*map)){
                showName(&(*P), giliran);
                printf(" telah mencapai ujung.\n");
                printf("Pemenang game ini adalah ");
                showName(&(*P), giliran);
                printf("\n");
                endturn = true;
            }
        }
        else if (IsSave(CKata)){
            








        }
        else if (IsEndturn(CKata)){
            if ((*P).TabPlayer[giliran].isRolled){
                endturn = true;
            }else{
                printf("Harus roll dulu baru bisa endturn.\n");
            }
        }
        else if (IsUndo(CKata)){
            










        }
        else{
            printf("Salah input command, coba lagi.\n");
        }
    }
}

