#ifndef GAMEBOARD_H 
#define GAMEBOARD_H
#include <fstream>
#include "pokemon.h"
#include "player.h"
#include "trainer.h"
#include "tile.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std; 


class gameBoard
{
    const int rows = 25; 
    const int columns = 16;
    const int numWaterTiles = 153; 
    const int numLandTiles = 247;
    const int numPokemonCenters = 15;
    const int numPokemonGyms = 15;
    const int BulbasaurRow = 13;
    const int BulbasaurColumn = 7;
    const int CharmanderRow = 13; 
    const int CharmanderColumn = 8; 
    const int SquirtleRow = 13; 
    const int SquirtleColumn = 9; 
    const int PikachuRow = 13; 
    const int PikachuColumn = 10;
    private:
        int activePokemonRow;
        int activePokemonCol;
        int gymRow;
        int gymCol;
        int pokemonCenterRow;
        int pokemonCenterCol;
        char mapPoke[25][16];
        vector<tile> waterTileRowCol;
        vector<tile> landTileRowCol;
        vector<tile> pokemonCenterTileRowCol;
        vector<tile> trainerTileRowCol;
        tile enemyWildPokemonTile;
        tile enemyTrainerPokemonTile;

    
    public: 
        gameBoard(); 
        gameBoard(int activePokemonRow,int activePokemonCol,int gymRow,int gymCol,int pokemonCenterRow,int pokemonCenterCol);
        int getActivePokemonRow();
        void setActivePokemonRow(int activeRow);
        int getActivePokemonCol();
        void setActivePokemonCol(int activeCol);
        int getnumWaterTiles();
        int getnumLandTiles();
        void readGameBoardFile(string fileName);
        void show7x7Area();
        void showMap(); //will show the entire gameboard for debugging
        bool encounterWildPokemon(vector<tile> wildPokemonTiles); //inspect teh 5x5 area about the current location of active pokemon
        bool encounterTrainerPokemon(vector<tile> trainerPokemonTiles);
        tile getEnemyWildPokemonTile();
        tile getEnemyTrainerPokemonTile();
        int getBulbasaurRow();
        int getBulbasaurColumn();
        int getCharmanderRow();
        int getCharmanderColumn(); 
        int getSquirtleRow(); 
        int getSquirtleColumn(); 
        int getPikachuRow(); 
        int getPikachuColumn();
        vector<tile> getWaterTileRowCol();
        vector<tile> getLandTileRowCol();
        vector<tile> getPokemonCenterTileRowCol();
        vector<tile> getTrainerTileRowCol();
        char getMapChar(int row, int col);
        void setMapChar(int row, int col, char value);
        int split(string s, char delimiter, string inputarr[],int len);

};
#endif 
