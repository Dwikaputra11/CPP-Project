#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>

#define Nil NULL

int chance (int x);

void getSkill(List *skill);

void displaySkill(List skill);

void BuangSkill (List *skill, int count);

void getSkill2(List *skill);

void cerminPengganda(List *skill);

#endif

