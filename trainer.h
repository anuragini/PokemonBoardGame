#ifndef TRAINER_H 
#define TRAINER_H 
#include "pokemon.h"
#include "tile.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;  

class trainer
{
    private: 
        int pokemonCount; 
        vector<pokemon> trainerPokemons;
        tile trainerTile;
    
    public: 
        trainer();
        trainer(int pokemonCount, tile trainerTile, vector<pokemon> trainerPokemons);
        int getPokemonCount();
        void setPokemonCount(int pokemonCount);
        vector<pokemon> getTrainerPokemons();
        void setTrainerPokemons(vector<pokemon> value);
        void setTrainerTile(tile value);
        tile getTrainerTile();
    
};
#endif