#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "pokemon.h"
#include "gameBoard.h"
#include "player.h"
#include "trainer.h"
#include "tile.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std; 

class game
{
    private: 
        vector<pokemon> wildPokemons;
        vector<pokemon> allPokemons;
        vector<tile> wildPokemonTiles;
        pokemon activePokemon;
        vector<trainer> trainers;
        vector<tile>battledTrainerTiles = {};

    
    public: 
        game();  
        game(vector<pokemon> WildPokemon);
        void showInitalBoard(string pokemonName);
        void readPokemonFile(string fileName);
        pokemon getActivePokemon();
        vector<tile> getWildPokemonTiles();
        vector<int> generateRandomNumbersInRange(vector<int> v, int numRandom); //generate random numbers in a range
        void getRandomWildPokemonLocations(vector<tile> landTilesRowCol, int numRandommTiles); //randomly select numRandommTiles nuber of tiles from vector landTilesRowCol
        vector<pokemon> getRandomWildPokemons(int numWildPokemons);
        vector<pokemon> getRandomTrainerPokemons(int numPokemons);
        int generateRandomNumberOfPokemonForTrainer();
        bool random50();
        bool random30();
        bool random20();
        bool random25();
        string generateRandomDirection();
        void gotoPokemonCenter(vector<pokemon> pokedex);
        void fightWildPokemon(gameBoard gb, player p, pokemon ap, vector<pokemon> pokedex);
        void fightTrainerPokemon(gameBoard gb, player p, pokemon ap,  vector<pokemon> pokedex, vector<trainer> trainers);
        void playGame();
        void levelupPokemon(pokemon p);
        void randomEvents();
        int split(string s, char delimiter, string inputarr[],int len);

};
#endif