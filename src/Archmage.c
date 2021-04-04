#include <stdlib.h>
#include <stdio.h>
#include "Hero.h"
#include "Defines.h"
#include "Archmage.h"

void createArchmage(Hero *archmage, const char *inputName, int inputMaxMana, int inputManaRegenRate, int manaRegMod){
    
    inputManaRegenRate *= manaRegMod;

    heroBaseInit(archmage, inputName, inputMaxMana, inputManaRegenRate);
    heroSpellsInit(archmage, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST,
                    ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
}

void basicSpellArchmage(Hero *archmage){

    if(archmage->currMana >= ARCHMAGE_BASIC_SPELL_MANA_COST){
        archmage->currMana -= ARCHMAGE_BASIC_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", archmage->name, archmage->spells[BASIC].name, ARCHMAGE_BASIC_SPELL_MANA_COST);
    } else {
        printf("%s - not enough mana to cast %s\n", archmage->name, archmage->spells[BASIC].name);
    }
}

void ultimateSpellArchmage(Hero *archmage){
    
    if(archmage->currMana >= ARCHMAGE_ULTIMATE_SPELL_MANA_COST){
        archmage->currMana -= ARCHMAGE_ULTIMATE_SPELL_MANA_COST;
        printf("%s casted %s for %d mana\n", archmage->name, archmage->spells[ULTIMATE].name, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
        //regenarateManaArchmage(archmage);
        regenarateMana(archmage);
    }else{
        printf("%s - not enough mana to cast %s\n", archmage->name, archmage->spells[ULTIMATE].name);
    }
}