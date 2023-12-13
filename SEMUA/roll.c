#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "map.h"
#include "mesin_kata.h"
#include "mesin_kar.h"
#include "array.h"

int randomize(time_t t, int Max){  
    return rand() % Max;
}

int roll(int buffSkill, int maxRoll){
    time_t t;
    srand((unsigned) (time(&t)));
    int Max;
    int angkaAtas, angkaBawah;
    if (buffSkill == 1){ // skill 1 = senter pembesar hoki
        angkaAtas = maxRoll;
        angkaBawah = floor(maxRoll/2);
    }else if (buffSkill == 2){ // skill 2 = senter pengecil hoki
        angkaAtas = floor(maxRoll/2);
        angkaBawah = 1;
    }else{
        angkaAtas = maxRoll;
        angkaBawah = 1;
    }
    Max = (angkaAtas - angkaBawah + 1);
    return (randomize(t, Max) + angkaBawah);
}

// driver roll
/*int main(){
    START();
    Map map;
    ConfigureMap(&map);
    int maxroll = MaxRoll(map);
    printf("%d\n", roll(3, maxroll));
}*/