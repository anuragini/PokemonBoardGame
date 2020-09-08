#ifndef POKEMON_H 
#define POKEMON_H
#include <vector>
#include <iostream>
#include <string>
using namespace std; 


class pokemon
{

    private:
        //design variables
        int hpConst; 
        int attackStrengthConst;
        int defenseStrengthConst; 
        int maxConst;
        int defenseAttackStrengthConst;  
        int speedConst;
        //pokemon temp variables 
        int id;
        string pokemonName;
        int hp; 
        int attackStrength;
        int defenseStrength; 
        int max;
        int defenseAttackStrength;
        int speed;
    
    public:
        pokemon();
        pokemon(int idVal, string pokemonNameVal, int hpVal, int attackStrengthVal, int defenseStrengthVal, int speedVal, int maxVal);
        int getHP();
        void setHP(int hp);
        int getAttackStrength(); 
        void setAttackStrength(int attackStrength); 
        int getDefenseStrength();
        void setDefenseStrength(int defenseStrength);
        int getSpeed(); 
        void setSpeed(int speed);
        int getMax();
        void setMax(int max);
        string getPokemonName();
        int getId();
    
        int getHPConst();
        int getAttackStrengthConst(); 
        int getDefenseStrengthConst();
        int getSpeedConst(); 
        int getMaxConst();
        string getPokemonNameConst();
        int getIdConst();
};
#endif
