#ifndef __PLAYER_H__
#define __PLAYER_H__


#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>
#include "listlinier.h"
#include "skill.h"

#define NilPlayer NULL

typedef struct{
    boolean isImmuned;
    boolean isSenterPembesar;
    boolean isSenterPengecil;
    boolean isCerminGanda;
} BuffPlayer;

typedef struct{
    char pName[15];
    int nomorPemain;
    int position;
    List skills;
    boolean isRolled;
    boolean isTeleported;
    BuffPlayer TabBuff[4+1];
} DataPlayer;

typedef struct{
    int banyakPlayer;
    DataPlayer TabPlayer[4+1];
} Player;

#define jumlah(Player) (Player).banyakPlayer

/******* KONSTRUKTOR ***********/

void CreatePlayerEmpty(Player *P);

void InputPlayer(Player *P, int banyakPlayer);

void showName (Player *P, int nomorPemain);

void useSkill(Player *P, int inputs, int nomorPemain);

#endif