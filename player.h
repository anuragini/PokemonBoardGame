#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include "pokemon.h"
#include "trainer.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std; 

class player
{

    private:
        int numPokeBalls; 
        int numBadges; 
        vector<pokemon> pokeDex;
        int points;
        vector<trainer> battledTrainers;
        pokemon activePokemon;
        vector<pokemon> pokemonSuite;//six pokemon in the team that battles
        pokemon starterPokemon;
        
    public: 
        player();
        player(int numPokeBalls, int numBadges,int points, pokemon activePokemon, pokemon starterPokemon, vector<pokemon> pokeDex, vector<trainer>battledTrainers, vector<pokemon> pokemonSuite);
        int getnumPokeBalls(); 
        void setnumPokeBalls(int PokeBallsVal);
        int getnumBadges(); 
        void setnumBadges(int numBadgesVal);
        pokemon getActivePokemon(); 
        void setActivePokemon(pokemon activePokemonVal);
        pokemon getStarterPokemon();
        void setStarterPokemon(pokemon starterPokemonVal);
        int getPoints(); 
        void setPoints(int pointsVal);
        vector<pokemon> getPokedex();
        void addPokemonToPokedex(pokemon value);
        void removePokemonFromPokedex(pokemon value);
};
#endif 