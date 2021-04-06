#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"
#include "Defines.h"
#include "DeathKnight.h"

void createDeathKnight(Hero *deathKnight, const char *inputName, int inputMaxMana, int inputManaRegenRate){

    heroBaseInit(deathKnight, inputName, inputMaxMana, inputManaRegenRate);
    heroSpellsInit(deathKnight, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
                    DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
}

void basicSpellDeathKnight(Hero *deathKnight){

    if(deathKnight->currMana >= DEATH_KNIGHT_BASIC_SPELL_MANA_COST){
        deathKnight->currMana -= DEATH_KNIGHT_BASIC_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", deathKnight->name, deathKnight->spells[BASIC].name, DEATH_KNIGHT_BASIC_SPELL_MANA_COST);
    }else{
        printf("%s - not enough mana to cast %s\n", deathKnight->name, deathKnight->spells[BASIC].name);
    }
}

void ultimateSpellDeathKinght(Hero *deathKnight){

    if(deathKnight->currMana >= DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST){
        deathKnight->currMana -= DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", deathKnight->name, deathKnight->spells[ULTIMATE].name, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
        printf("%s casted %s for 0 mana\n", deathKnight->name, deathKnight->spells[BASIC].name);
    }else{
        printf("%s - not enough mana to cast %s\n", deathKnight->name, deathKnight->spells[ULTIMATE].name);
    }
}