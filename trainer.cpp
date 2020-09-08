#include<iostream>
#include "pokemon.h"
#include "tile.h"
#include "trainer.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


trainer :: trainer()
{
    pokemonCount = 0; 
    trainerPokemons = {};
}
trainer :: trainer(int pokemonCountVal, tile trainerTileValue, vector<pokemon> trainerPokemonsVal)
{
    pokemonCount = pokemonCountVal; 
    trainerTile = trainerTileValue;
    trainerPokemons = trainerPokemonsVal;
}
 int trainer :: getPokemonCount()
 {
     return pokemonCount;
 }
 void trainer ::  setPokemonCount(int pokemonCountVal)
 {
     pokemonCount = pokemonCountVal;
 }
vector<pokemon> trainer :: getTrainerPokemons()
{
    return trainerPokemons;
}
void trainer :: setTrainerPokemons(vector<pokemon> value)
{
    trainerPokemons = value;
}
        
 tile trainer ::  getTrainerTile()
 {
     return trainerTile;
 }
 void trainer ::  setTrainerTile(tile value)
 {
     trainerTile = value;
 }

