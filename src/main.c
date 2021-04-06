#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"
#include "Archmage.h"
#include "DeathKnight.h"
#include "DrawRanger.h"

int main(void){

  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  int manaRegenModifier = 0;
  
  Hero heroes[3];
  //read Archmage data
  scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
  createArchmage(&heroes[ARCHMAGE], name, maxMana, baseManaRegenRate, manaRegenModifier);

  //read Death Knight data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  createDeathKnight(&heroes[DEATH_KNIGHT], name, maxMana, baseManaRegenRate);
  
  //read Draw Ranger data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  createDrawRanger(&heroes[DRAW_RANGER], name, maxMana, baseManaRegenRate);
 
  int commandsCount = 0;
  int currAction = 0;
 
  scanf("%d", &commandsCount);

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
    castSpell(heroes, currAction);
  }

  return EXIT_SUCCESS;
}