#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hero.h"

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana, int inputManaRegenRate){

    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
}

void heroSpellsInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost,
                    const char *ultimateSpellName, int ultimateSpellManaCost){

    strcpy(hero->spells[BASIC].name, basicSpellName);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
    strcpy(hero->spells[ULTIMATE].name, ultimateSpellName);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;    
}

void regenarateMana(Hero *hero){

    hero->currMana += hero->manaRegenRate;
    if(hero->currMana > hero->maxMana){
        hero->currMana = hero->maxMana;
    }
}