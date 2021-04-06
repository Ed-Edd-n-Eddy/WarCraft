#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"
#include "Archmage.h"
#include "DeathKnight.h"
#include "DrawRanger.h"

void castSpell(Hero heroes[3], int actionType){

    switch (actionType){
    case CAST_BASIC_SPELL:
        basicSpellArchmage(&heroes[ARCHMAGE]);
        basicSpellDeathKnight(&heroes[DEATH_KNIGHT]);
        basicSpellDrawRanger(&heroes[DRAW_RANGER]);
        break;
    case CAST_ULTIMATE_SPELL:
        ultimateSpellArchmage(&heroes[ARCHMAGE]);
        ultimateSpellDeathKinght(&heroes[DEATH_KNIGHT]);
        ultimateSpellDrawRanger(&heroes[DRAW_RANGER]);
        break;
    case REGENERATE_MANA:
        regenarateMana(&heroes[ARCHMAGE]);
        regenarateMana(&heroes[DEATH_KNIGHT]);
        regenarateMana(&heroes[DRAW_RANGER]);
        break;
    default:
        printf("Invalid action type\n");
        break;
    }
}