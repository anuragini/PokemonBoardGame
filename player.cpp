#include <iostream> 
//#include <iomainip> 
#include "pokemon.h"
#include "gameBoard.h"
#include "game.h"
#include "player.h"
#include "trainer.h"
#include "tile.h"
#include <vector>
#include <fstream>
using namespace std; 

player :: player()
{
    numPokeBalls = 10; 
    numBadges = 0; 
    pokeDex = {};
    points = 0; 
    battledTrainers = {};
    activePokemon = pokemon(); 
    pokemonSuite = {};
    starterPokemon = pokemon();
    
}

player :: player(int numPokeBallsVal,int numBadgesVal, int pointsVal, pokemon activePokemonVal, pokemon starterPokemonVal, vector<pokemon> PokeDex, vector<trainer> BattledTrainers, vector<pokemon> PokemonSuite)
{
    numPokeBalls = numPokeBallsVal;
    numBadges = numBadgesVal;
    pokeDex = PokeDex; 
    points = pointsVal;
    battledTrainers = BattledTrainers;
    activePokemon = activePokemonVal;
    pokemonSuite = PokemonSuite;
    starterPokemon = starterPokemonVal;
} 
int player ::  getnumPokeBalls()
{
    return numPokeBalls;
}
void player ::  setnumPokeBalls(int numPokeBallsVal)
{
    numPokeBalls = numPokeBallsVal;
}
int player :: getnumBadges()
{
    return numBadges;
}
void player ::  setnumBadges(int numBadgesVal)
{
    numBadges = numBadgesVal;
}
pokemon player :: getActivePokemon()
{
    return activePokemon;
}
void player :: setActivePokemon(pokemon activePokemonVal)
{
    activePokemon = activePokemonVal;
}
pokemon player ::  getStarterPokemon()
{
    return starterPokemon;
}
void player :: setStarterPokemon(pokemon starterPokemonVal)
{
    starterPokemon = starterPokemonVal;
}
int player :: getPoints()
{
    return points;
}
void player ::setPoints(int pointsVal)
{
    points = pointsVal;
}
vector<pokemon> player :: getPokedex()
{
    return pokeDex;
}
void player :: addPokemonToPokedex(pokemon value)
{
    pokeDex.push_back(value);
}
void player :: removePokemonFromPokedex(pokemon pval)
{
    //myvector.erase (myvector.begin()+5);
    int index = -1;
    for (int i=0; i<pokeDex.size(); i++)
    {
        pokemon p = pokeDex[i];
        string name = p.getPokemonName();
        if (name == pval.getPokemonName())
        {
            index = i;
            cout << "Pokemon " << name << "removed from Pokedex"<< endl;
            break;
        }
    }
    if (index != -1)
    {
        pokeDex.erase(pokeDex.begin()+index); //can we use pokedex.erase(i);
    }
}