#include <stdio.h>
#include "map.h"
#include "array.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

int teleport(int posisi){
    int idx;
    Map map;
    ConfigureMap(&map);
    boolean check = false;
    for(int i = 1; i <= (NTeleport(map)); i++){
        if(IsTeleport(map).TI[i] == posisi){ 
            idx = i;
            check = true;
        }
    }
    if (check){
        posisi = Teleport(map).TI[IsTeleport(map).TI[idx]];
    }
    return posisi;
}

/*int main(){
    Map map;
    ConfigureMap(&map);
    for (int i = 1; i <= Length(map); i++){
        printf("%d\n", teleport(i));
    } 
}*/