#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "mesin_kar.h"
#include "mesin_kata.h"
#include "boolean.h"


boolean IsSkill(Kata kata);

boolean IsMap(Kata kata);

boolean IsBuff(Kata kata);

boolean IsInspect(Kata kata);

boolean IsRoll(Kata kata);

boolean IsSave(Kata kata);

boolean IsEndturn(Kata kata);

boolean IsUndo(Kata kata);

void command();


#endif