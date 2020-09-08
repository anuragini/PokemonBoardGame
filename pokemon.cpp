#include "pokemon.h"
#include <iostream>
#include <string>
using namespace std; 

pokemon :: pokemon()
{
    
    hpConst = 0; 
    attackStrengthConst = 0;
    defenseStrengthConst = 0; 
    maxConst = 0;
    defenseAttackStrengthConst = 0;  
    speedConst = 0;
    hp = 0; 
    attackStrength = 0;
    defenseStrength = 0; 
    max = 0;
    speed = 0;
}
pokemon :: pokemon(int idVal, string pokemonNameVal, int hpVal, int attackStrengthVal, int defenseStrengthVal, int speedVal, int maxVal)
{
    id = idVal;
    pokemonName = pokemonNameVal;
    hpConst = hpVal; 
    attackStrengthConst = attackStrengthVal; 
    defenseStrengthConst = defenseStrengthVal;
    maxConst = maxVal; 
    speedConst = speedVal;
    hp = hpVal; 
    attackStrength = attackStrengthVal;
    defenseStrength = defenseStrengthVal; 
    max = maxVal;
    speed = speedVal;
    
}
int pokemon :: getHP()
{
    return hp;
}
void pokemon :: setHP(int hpVal)
{
    hp = hpVal;
}
int pokemon :: getAttackStrength()
{
    return attackStrength;
}
void pokemon :: setAttackStrength(int attackStrengthVal)
{
    attackStrength = attackStrengthVal;
}
int pokemon :: getDefenseStrength()
{
    return defenseStrength;
}
void pokemon :: setDefenseStrength(int defenseStrengthVal)
{
    defenseStrength = defenseStrengthVal;
}
int pokemon :: getSpeed()
 {
     return speed;
 }
void pokemon :: setSpeed(int speedVal)
 {
     speed = speedVal;
 }
int pokemon :: getMax()
{
    return max;
}
void pokemon :: setMax(int maxVal)
{
    max = maxVal;
}
int pokemon :: getHPConst()
{
    return hpConst;
}
int pokemon :: getAttackStrengthConst()
{
    return attackStrengthConst;
}
int pokemon :: getDefenseStrengthConst()
{
    return defenseStrengthConst;
}
int pokemon :: getSpeedConst()
 {
     return speedConst;
 }
int pokemon :: getMaxConst()
{
    return maxConst;
}

string pokemon :: getPokemonName()
 {
     return pokemonName;
 }
int pokemon :: getId()
 {
     return id;
 }
 