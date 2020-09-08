#ifndef TILE_H
#define TILE_H
#include<iostream> 
#include "pokemon.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std; 

//////TILE///////
class tile
{
    private:
        int row;
        int col;
        string type; //w,p,C,G
        pokemon wildPokemon;
        
    public:
        int getRow();
        int getCol();
        string getType();
        void setRow(int value);
        void setCol(int value);
        void setType(string value);
        pokemon getWildPokemon();
        void setWildPokemon(pokemon value);
};
#endif
