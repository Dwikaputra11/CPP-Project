#ifndef __MAP_H__
#define __MAP_H__

#include "mesin_kata.h"
#include "mesin_kar.h"
#include "array.h"
#include <stdio.h>


typedef struct{
    int Length;
    int MaxRoll;
    int NTeleport;
    TabInt Config;
    TabInt Teleport;
    TabInt IsTeleport;
    TabInt IsNotTeleport;
    TabInt AllMap;
} Map;

#define Length(Map) (Map).Length
#define MaxRoll(Map) (Map).MaxRoll
#define NTeleport(Map) (Map).NTeleport
#define Config(Map) (Map).Config
#define Teleport(Map) (Map).Teleport
#define IsTeleport(Map) (Map).IsTeleport
#define IsNotTeleport(Map) (Map).IsNotTeleport
#define AllMap(Map) (Map).AllMap

void ConfigureMap (Map *map);
/*membaca file konfigurasi menjadi peta*/

int ConverterCharInt (Kata CKata, int *hasilConvert, int Kelipatan);
/*fungsi untuk mengubah karakter menjadi integer*/

#endif
