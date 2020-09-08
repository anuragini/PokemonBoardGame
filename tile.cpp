
#include<iostream> 
#include "pokemon.h"
#include "tile.h"
#include <vector>
using namespace std; 

int tile :: getRow()
{
    return row;
}
int tile :: getCol()
{
    return col;
}
string tile :: getType()
{
    return type;
}
void tile :: setRow(int value)
{
    row = value;
}
void tile :: setCol(int value)
{
    col = value;
}
void tile :: setType(string value)
{
    type = value;
}
pokemon tile :: getWildPokemon()
{
    return wildPokemon;
}
void tile :: setWildPokemon(pokemon value)
{
    wildPokemon = value;
}