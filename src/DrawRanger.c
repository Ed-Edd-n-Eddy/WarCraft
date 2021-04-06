#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"
#include "DrawRanger.h"

void createDrawRanger(Hero *drawRanger, const char *inputName, int inputMaxMana, int inputManaRegenRate){
    
    heroBaseInit(drawRanger, inputName, inputMaxMana, inputManaRegenRate);
    heroSpellsInit(drawRanger, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST,
                            DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
}

void basicSpellDrawRanger(Hero *drawRanger){

    if(drawRanger->currMana >= DRAW_RANGER_BASIC_SPELL_MANA_COST){
        drawRanger->currMana -= DRAW_RANGER_BASIC_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", drawRanger->name, drawRanger->spells[BASIC].name, DRAW_RANGER_BASIC_SPELL_MANA_COST);
        printf("%s casted %s for 0 mana\n", drawRanger->name, drawRanger->spells[BASIC].name);
    } else {
        printf("%s - not enough mana to cast %s\n", drawRanger->name, drawRanger->spells[BASIC].name);
    }
}

void ultimateSpellDrawRanger(Hero *drawRanger){

    if(drawRanger->currMana >= DRAW_RANGER_ULTIMATE_SPELL_MANA_COST){
        drawRanger->currMana -= DRAW_RANGER_ULTIMATE_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", drawRanger->name, drawRanger->spells[ULTIMATE].name, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
    } else {
        printf("%s - not enough mana to cast %s\n", drawRanger->name, drawRanger->spells[ULTIMATE].name);
    }
}