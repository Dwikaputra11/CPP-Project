#ifndef __ROLL_H__
#define __ROLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "map.h"
#include "mesin_kata.h"
#include "mesin_kar.h"
#include "array.h"

int randomize(time_t t, int Max);

int roll(int buffSkill, int maxRoll);

#endif