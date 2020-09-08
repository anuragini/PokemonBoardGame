#include<iostream> 
#include "pokemon.h"
#include "gameBoard.h"
#include "player.h"
#include "trainer.h"
#include "tile.h"
#include <vector>
#include <fstream>
using namespace std; 


gameBoard :: gameBoard()
{
    activePokemonRow = 0; 
    activePokemonCol = 0; 
    gymRow = 0; 
    gymCol = 0;
    pokemonCenterRow = 0; 
    pokemonCenterCol = 0;
}
gameBoard :: gameBoard(int ActivePokemonRow, int ActivePokemonCol,int GymRow, int GymCol, int PokemonCenterRow, int PokemonCenterCol)
{
    activePokemonRow = ActivePokemonRow;
    activePokemonCol = ActivePokemonCol;
    gymCol = GymCol;
    pokemonCenterRow = PokemonCenterRow;
    pokemonCenterCol = PokemonCenterCol;
}
int gameBoard :: getActivePokemonRow()
{
    return activePokemonRow;
}
void gameBoard :: setActivePokemonRow(int activeRow)
{
    activePokemonRow =  activeRow;
}
int gameBoard :: getActivePokemonCol()
{
    return activePokemonCol;
}
void gameBoard :: setActivePokemonCol(int activeCol)
{
    activePokemonCol = activeCol;
}
        
int gameBoard ::  getnumWaterTiles()
{
    return numWaterTiles;
}
int gameBoard :: getnumLandTiles()
{
    return numLandTiles;
}
tile gameBoard :: getEnemyWildPokemonTile()
{
    return enemyWildPokemonTile;
}
tile gameBoard :: getEnemyTrainerPokemonTile()
{
    return enemyTrainerPokemonTile;
}
void gameBoard :: readGameBoardFile(string fileName)
{
    //read the mappoke file and populate the mapPoke array
    //char mapPoke[25][16];
    ifstream file (fileName);
    if(!file)
    {
        return; 
    }
    char delimiter = ',';
    int len = 16;
    string arr[len];
    string s; 
    int y;

    int count = 0;
    while(getline(file, s)) // getline function that takes both file and string s
    {
        if (s.length() > 0 ) // if the length of the string is more than zero check next if
        {
            int x = split(s,  delimiter, arr, len);
            for (int i=0; i < 16; i++)
            {
                string s1 = arr[i];
                mapPoke[count][i] = s1[0]; //string s1 is an array of char
                if (s1[0] == 'p')
                {
                    tile landTile = tile();
                    landTile.setRow(count);
                    landTile.setCol(i);
                    landTile.setType("p");
                    landTileRowCol.push_back(landTile);
                }
                if (s1[0] == 'G')   //pokemon gym where the trainer lives
                {
                    tile t = tile();
                    t.setRow(count);
                    t.setCol(i);
                    t.setType("G");
                    trainerTileRowCol.push_back(t);
                }
                if (s1[0] == 'C')   //pokemon center
                {
                    tile t = tile();
                    t.setRow(count);
                    t.setCol(i);
                    t.setType("C");
                    pokemonCenterTileRowCol.push_back(t);
                } 
            }

            count ++; // count will increment for each line
        }
    }

}
void gameBoard :: show7x7Area()
{
    //print out the map visible to player show it at every turn
    for (int i=activePokemonRow-3; i <= activePokemonRow+3; i++)
    {
        for (int j=activePokemonCol-3; j <= activePokemonCol+3; j++)
        {
            if ((i < 0) || (i > 24) || (j < 0) || (j > 15)) //check for area outside the board. area is 25 rows and 16 col
            {
                cout<<"x ";
            }
            else if ((i == activePokemonRow) && (j == activePokemonCol))
            {
                cout<<"@ "; //active pokemon
            }
            else
            {
                if (mapPoke[i][j] == 'w')   //water
                {
                    cout<<"~ ";
                }
                else if (mapPoke[i][j] == 'p')  //land
                {
                    cout<<"* ";
                }
                else
                {
                    cout <<mapPoke[i][j] << " ";
                }
            }
        }
        cout<<endl;
    }  
    
}

void gameBoard :: showMap()
{
    //print out the map 
    for (int i=0; i < 25; i++)
    {
        for (int j=0; j < 16; j++)
        {
            if (mapPoke[i][j] == 'w')
            {
                cout<<"~ ";
            }
            else if (mapPoke[i][j] == 'p')
            {
                cout<<"* ";
            }
            else
            {
                cout <<mapPoke[i][j] << " ";
            }
        }
        cout<<endl;
    }  
    
}

bool gameBoard :: encounterWildPokemon(vector<tile> wildPokemonTiles)
{
    //inspect the 5x5 area from current location of active pokemon of player
    //explore if there is a wild pokemon or a trainer poke mon
    //Find the actual wild pokemon with which the player pokemon will fight
    for (int i=activePokemonRow-2; i <= activePokemonRow+2; i++)
    {
        for (int j=activePokemonCol-2; j <= activePokemonCol+2; j++)
        {
            if (mapPoke[i][j] == 'P')   //P = wild pokemon on map
            {
                cout<<"Wild pokemon found"<<endl;
            }
            //i,j
            //compare it to each wild pokemon tile and if they match, we have an encounter
            for (int k=0; k<wildPokemonTiles.size(); k++)
            {
                tile t = wildPokemonTiles[k];
                int r = t.getRow();
                int c = t.getCol();
                if (r == i && c == j)
                {
                    //We have an encounter
                    enemyWildPokemonTile = t;
                    return true;
                    
                }
            }
            
        }
    }
    return false;
}
//would we put the flee speed here?
/*
int gameBoard :: getFleeSpeed()
{
   int f;
   activePokemon ap; 
   int a = ap.getCurrentSpeed();
   int b = ap.get
   how would we do flee speed?
   what class would it be part of?
}
*/
bool gameBoard :: encounterTrainerPokemon(vector<tile> trainerPokemonTiles)
{
    //explore if there is a wild pokemon or a trainer poke mon
    for (int i=activePokemonRow-2; i <= activePokemonRow+2; i++)
    {
        for (int j=activePokemonCol-2; j <= activePokemonCol+2; j++)
        {
            if (mapPoke[i][j] == 'G')   //G = trainer pokemon on map as he lives at Gym
            {
                cout<<"Trainer pokemon found"<<endl;
            }
            //i,j
            //compare it to each trainer pokemon tiles and if they match, we have an encounter
            //Find the actual trainer pokemon with which the player pokemon will fight
            for (int k=0; k<trainerPokemonTiles.size(); k++)
            {
                tile t = trainerPokemonTiles[k];
                int r = t.getRow();
                int c = t.getCol();
                if ((r == i) && (c == j))
                {
                    //We have an encounter
                    enemyTrainerPokemonTile = t;
                    return true;
                    
                }
            }
            
        }
    }
    return false;
}

int  gameBoard :: getBulbasaurRow()
{
    return BulbasaurRow;
}
int  gameBoard :: getBulbasaurColumn()
{
    return BulbasaurColumn;
}
int  gameBoard :: getCharmanderRow()
{
    return CharmanderRow;
}
int gameBoard ::  getCharmanderColumn()
{
    return CharmanderColumn;
}
int gameBoard ::  getSquirtleRow()
{
    return SquirtleRow;
}
int gameBoard ::  getSquirtleColumn()
{
    return SquirtleColumn;
}
int gameBoard ::  getPikachuRow()
{
    return PikachuRow;
}
int gameBoard ::  getPikachuColumn()
{
    return PikachuColumn;
}

char gameBoard :: getMapChar(int row, int col)
{
    return mapPoke[row][col];
}
void gameBoard :: setMapChar(int row, int col, char value)
{
    mapPoke[row][col] = value;  //to set the location of wild pokemon as they are also moving with player pokemon
}

vector<tile> gameBoard :: getWaterTileRowCol()
{
    return waterTileRowCol;
}
vector<tile> gameBoard :: getLandTileRowCol()
{
    return landTileRowCol;
}
vector<tile> gameBoard :: getPokemonCenterTileRowCol()
{
    return pokemonCenterTileRowCol;
}
vector<tile> gameBoard :: getTrainerTileRowCol()
{
    return trainerTileRowCol;
}


int gameBoard :: split(string s, char delimiter, string inputarr[],int len)// this will take in four parameters
{
    s = s + delimiter;//
    string arr[len];
    int count = 0;
    string word = "";
    if(s.length() == 0 || s == "")// if s is equal to zero or s equals blank return zero
    {
        return 0; 
    }
    for(int i = 0; i < s.length();i++)// for loop cycling thorugh the entire string
    {
        if(s[i] == delimiter) // if the index equals delimiter
        {
            if (word.length() > 0)// when word length is more than zero 
            {
                arr[count] = word;// the count will equal the word 
                word = "";// this will be a blank
                count++;//iterate count
            }
        }
        else
        {
            if (s[i] != delimiter)//is s does not equal the delimter
            {
                word = word + s[i]; // string will be concatenated
            }
           

        }
    }
    for (int i=0; i<len; i++)// cycle through the count for the array
    {
        inputarr[i] = arr[i];// this will equal the new array
        
        
    }
    //return count
    return count;
}
