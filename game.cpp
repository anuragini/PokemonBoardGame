#include <iostream> 
//#include <iomainip> 
#include "pokemon.h"
#include "player.h"
#include "trainer.h"
#include "tile.h"
#include "gameBoard.h"
#include "game.h"
#include <vector>
#include <fstream>
using namespace std; 

////GAME IMPLEMENTATION////
game :: game()
{
    wildPokemons = {};
}
game :: game(vector<pokemon> WildPokemon)
{
    wildPokemons = WildPokemon;
}

int game :: split(string s, char delimiter, string inputarr[],int len)// this will take in four parameters
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


void game :: showInitalBoard(string PokemonName)   
{

}

void game :: readPokemonFile(string fileName)
 {
    ifstream file (fileName);
    if(!file)
    {
        return; 
    }
    char delimiter = ',';
    int len = 10;
    string arr[len];
    string s; 
    int y;
    
    //pokeman properties
    int id, hp, attack, defense, speed, max;
    string name, type1, type2;
    
    int count = 0;
    getline(file, s);    //read the first line that is column name
    while(getline(file, s)) // getline function that takes both file and string s
    {
        if (s.length() > 0 ) // if the length of the string is more than zero check next if
        {
            int x = split(s,  delimiter, arr, len);
            id = stoi(arr[0]);
            name = arr[1];
            hp = stoi(arr[2]);
            attack = stoi(arr[3]);
            defense = stoi(arr[4]);
            speed = stoi(arr[5]);
            max = stoi(arr[6]);
            pokemon p = pokemon(id, name, hp, attack, defense, max, speed);
            //cout << p.getPokemonName() << " " << p.getSpeedConst() << endl;
            allPokemons.push_back(p);
            count ++; // count will increment for each line
        }
    
    }
 }
 
 
pokemon game :: getActivePokemon()
 {
     return activePokemon;
 }

vector<tile> game :: getWildPokemonTiles()
{
    return wildPokemonTiles;
}
vector<int> game :: generateRandomNumbersInRange(vector<int> v, int numRandom)

 {
    //generate multiple random numbers in a range
    //vector<int> v = { 0, 1, 2, 3, 4, 5, 6 }; //index of vector containing land tile row and col
    vector<int> randomNumbers = {};
    int max = v.size(); //set the upper bound to generate the random number
    srand(time(0));
    int count = 0;
    //int numRandom = 10;
    while(true)
    {
      //cout << "The random number is: "<<rand()%max << endl;
      int rndNum = rand()%max;  //max = 151, rndNum = 34
      bool found = false;
      for (int i=0; i < randomNumbers.size(); i++)
      {
          if (randomNumbers[i] == rndNum)
          {
              found = true;
          }
      }
      if (found == false)
      {
          randomNumbers.push_back(rndNum);
          count++;
      }
      if (count == numRandom) //20 for wild pokemon. 15 for gym trainer pokemon
      {
          break;
      }
    }
    return randomNumbers;
 }
 
void game :: getRandomWildPokemonLocations(vector<tile> landTilesRowCol, int numRandommTiles)
//when reading the map file, this array is populated and is the land tile
//numRows = numnber of land tiles and it has row and column for that tile
//numRandommTiles = 15 for wild pokemons
 {  
    int numRows = landTilesRowCol.size();
    vector<int> v = {};
    for (int i=0; i < numRows; i++)
    {
        v.push_back(i);
    }
    vector<int> v1 = generateRandomNumbersInRange(v, numRandommTiles); 
    //cout <<"Wild pokemon tiles"<<endl;
    for (int i=0; i < v1.size(); i++)
    {   
        int index = v1[i];
        tile t = landTilesRowCol[index];
        int r = t.getRow();
        int c = t.getCol();

        wildPokemonTiles.push_back(t);
        //cout << r << " " << c << endl;

    }
 }
 
 vector<pokemon> game :: getRandomWildPokemons(int numWildPokemons)
 {  
    int numRows = allPokemons.size();
    vector<int> v = {};
    for (int i=0; i < numRows; i++)
    {
        v.push_back(i);
    }
    vector<int> v1 = generateRandomNumbersInRange(v, numWildPokemons); 
    //cout <<"Wild pokemons"<<endl;
    for (int i=0; i < v1.size(); i++)
    {   
        int index = v1[i];
        pokemon p = allPokemons[index];
        wildPokemons.push_back(p);
        //cout<<p.getPokemonName()<<endl;

    }
    return wildPokemons;
 }
 
 vector<pokemon> game :: getRandomTrainerPokemons(int numPokemons)
 //for each trainer, get randomly selected pokemons
 {  
     vector<pokemon> trPokemons = {};
    int numRows = allPokemons.size();
    vector<int> v = {};
    for (int i=0; i < numRows; i++)
    {
        v.push_back(i);
    }
    vector<int> v1 = generateRandomNumbersInRange(v, numPokemons); 
    //cout <<"Trainer pokemons"<<endl;
    for (int i=0; i < v1.size(); i++)
    {   
        int index = v1[i];
        pokemon p = allPokemons[index];
        trPokemons.push_back(p);
        //cout<<p.getPokemonName()<<endl;

    }
    return trPokemons;
 }
 
 
int game :: generateRandomNumberOfPokemonForTrainer()
//return reandom number of pokemon for a trainer

 {
    vector<int> v = {1, 2, 3, 4, 5, 6}; //index of vector containing land tile row and col
    int max = v.size(); //set the upper bound to generate the random number
    return rand()%6 + 1;
 }
 
bool game :: random50()
 {
    int p = rand()%2 + 1;
    if (p == 2)
    {
        return true;
    }
    else 
    {
        return false;
    }
 }
 
 bool game :: random30()
 {
    int p = rand()%3 + 1;
    if (p == 3)
    {
        return true;
    }
    else 
    {
        return false;
    }
 }
 
bool game :: random25()
 {
    int p = rand()%4 + 1;
    if (p == 4)
    {
        return true;
    }
    else 
    {
        return false;
    }
 }
  
 
  bool game :: random20()
 {
    int p = rand()%5 + 1;
    if (p == 5)
    {
        return true;
    }
    else 
    {
        return false;
    }
 }
 
 string game :: generateRandomDirection()
 {
     //pokemon will travel in one direction. Generate a randon number between 1 and 4, and do the following
    int p = rand()%4 + 1;
    if (p == 1)
    {
        return "East";
    }
    else if(p == 2) 
    {
        return "West";
    }
    else if(p == 3)
    {
        return "North";
    }
    else if(p == 4)
    {
        return "South";
    }
 }
 
void game :: gotoPokemonCenter(vector<pokemon> pokedex)
//all pokemon heal in a pokedex
{
    for (int i=0; i< pokedex.size(); i++)
    {
        pokemon p = pokedex[i];
        p.setHP(p.getHPConst());
        p.setAttackStrength(p.getAttackStrengthConst());
        p.setDefenseStrength(p.getDefenseStrengthConst());
        p.setSpeed(p.getSpeedConst());
        p.setMax(p.getMaxConst());
    
        //void setAttackStrength(int attackStrength)
        //void setDefenseStrength(int defenseStrength);
        //void setSpeed(int speed);
        //void setMax(int max);
    }
}

void game :: fightWildPokemon(gameBoard gb, player p, pokemon ap, vector<pokemon> pokedex)
{
        int fightOption, rndA, rndB, damage, selectedPokemonNumber,A,B,C,D;
        if (gb.encounterWildPokemon(wildPokemonTiles) == true) //means wild pokemon found
        {
            tile t = gb.getEnemyWildPokemonTile();
            pokemon pm = t.getWildPokemon();
            if (pokedex.size() <1) //for testing restricting it to 1. After capturing 1, it will fight
            {
                p.addPokemonToPokedex(pm);
                //wildPokemonTiles.erase(wildPokemonTiles.begin()+index);
                cout<< pm.getPokemonName() << " pokemon was added to pokeDex\n"<<endl;
            }
            else 
            {
                while (true)
                {
                    //pm = wild pokemon, ap = active pokemon of player
                    cout << "You ran into a wild Pokemon!" << endl;
                    cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                    cout << "\n" << endl;
                    cout << "Your Active Pokemon is: " << endl;
                    cout<<"Name: " << ap.getPokemonName()  << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl; 

                    cout << "What do you want to do (pick 1,2, or 3): \n1. Fight\n2. Switch Active Pokemon\n3. Run" <<endl;
                    cin >> fightOption;
                    A = pm.getSpeed(); //wild pokemon speed
                    B = (ap.getSpeed()/4)%256;  //adjusted speed of active player pokemon
                    C = 1;
                    D =  ap.getSpeed(); //active pokemon speed
                    int F = ((A*32)/B) + (30*C);
                    if (fightOption == 1)
                    {
                        cout <<"Fighting wild Pokemon " << pm.getPokemonName() << endl;
                        if (A > D) //wild pokeman speed is greater than active pokemon speed wild pokemon will attack first
                        {
                            rndA = rand()%A + 1;// this will be a number between 1 and the wild pokemon speed
                            rndB = rand()%B + 1; // this will be a number between 1 and the adjusted speed of active pokemon
                            damage = 0;
                            if (rndA > rndB)
                            {
                                damage = rndA - rndB; //50
                                int netHP = ap.getHP() - damage;    //40 - 50
                                if (netHP <= 0)// my pokemon faints I lose
                                {
                                    ap.setHP(0);
                                    cout <<ap.getPokemonName() << " has fainted!" <<endl;
                                }
                                else
                                {
                                    ap.setHP(netHP);
                                }
                            }
                            //print stats
                            cout <<"\n" << pm.getPokemonName() << " attacks first" <<endl;
                            cout <<pm.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            cout<<"Name: " << ap.getPokemonName() << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl; 
                                                        
                            //defender attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndB > rndA)
                            {
                                damage = rndB - rndA;
                                if ((pm.getHP() - damage) <= 0)
                                {
                                    pm.setHP(0);
                                }
                                else
                                {
                                    pm.setHP(pm.getHP() - damage);
                                }
                            }
                            cout <<"\n" << ap.getPokemonName() << " attacks first" <<endl;
                            cout <<ap.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            cout<<"Name: " << ap.getPokemonName() << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl;                             
                        }
                        else    //my active pokemon attacks
                        {
                            //defender attacks - player pokemon attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndB > rndA)
                            {
                                damage = rndB - rndA;
                                if ((pm.getHP() - damage) <= 0)
                                {
                                    pm.setHP(0);
                                }
                                else
                                {
                                    pm.setHP(pm.getHP() - damage);
                                }
                            }
                            cout <<"\n" << ap.getPokemonName() << " attacks first" <<endl;
                            cout <<ap.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            
                            //wild pokemon attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndA > rndB)
                            {
                                damage = rndA - rndB;
                                if ((ap.getHP() - damage) <= 0)
                                {
                                    ap.setHP(0);
                                    cout <<ap.getPokemonName() << " has fainted!" <<endl;
                                }
                                else
                                {
                                    ap.setHP(ap.getHP() - damage);
                                }
                            }
                            //print stats
                            cout <<"\n" << pm.getPokemonName() << " attacks first" <<endl;
                            cout << pm.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 

                        }
                        //battle end condition
                        if (pm.getHP() == 0)
                        {
                            cout << "The wild Pokemon has fainted!" << endl;
                            //ap levels up
                            levelupPokemon(ap); //the active pokemon levels up
                            p.setPoints(p.getPoints() + 10);
                            break; //turn ends
                        }
                        if (ap.getHP() == 0)
                        {
                            //player loses
                            cout << "Your Pokemon has fainted!, you lose the battle!!" << endl;
                            //pm levels up
                            levelupPokemon(pm); //level up wild pokemon
                            break; //turn ends
                        }
                    }
                    else if (fightOption == 2)
                    {
                        cout <<"Pick another Active Pokemon (1,2,3 or 4): "<< endl;
                        for (int i = 0; i <pokedex.size(); i++)
                        {
                            cout << i+1 << ". " << pokedex[i].getPokemonName() << endl;
                        }
                        cin >> selectedPokemonNumber;
                        cout << "Your ACTIVE Pokemon is:" << endl;
                        pm = pokedex[selectedPokemonNumber-1];
                        cout<<"Name: " << pm.getPokemonName() << " (ACTIVE) "<< " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                        p.setActivePokemon(pm);
                    }
                    else if (fightOption == 3)
                    {
                        if (ap.getSpeed() > pm.getSpeed())

                        if (   (ap.getSpeed() > pm.getSpeed())  ||  (F>255)  )
                        {
                            //escapes! take wild pokemon to random location
                            t.setRow(t.getRow()+1); //check the logic
                            t.setRow(t.getCol()+1);
                            cout << "Wild pokeman escape was successful!" << endl;
                        }
                        else 
                        {
                            //escape fails
                            cout << "Escape failed!" <<endl;
                        }
                    }
                }   //while (true)
            }   //if (pokedex.size() <1) 
        } //if (gb.encounterWildPokemon(wildPokemonTiles) == true) 
        return;
}


void game :: fightTrainerPokemon(gameBoard gb, player p, pokemon ap,  vector<pokemon> pokedex, vector<trainer> trainers)
{

        int fightOption, rndA, rndB, damage, selectedPokemonNumber,A,B,C,D, row, col;
        trainer gymTrainer;
        bool trainerFound = false;
        pokemon pm;
        vector<pokemon> trainerPokemons;
        vector<tile> trainerTiles = gb.getTrainerTileRowCol();
        if (gb.encounterTrainerPokemon(trainerTiles) == true) //means wild pokemon found
        {
            tile et = gb.getEnemyTrainerPokemonTile();
            int r = et.getRow();
            int c = et.getCol();
            //check if the trainer has been battled before
            for (int i=0; i <battledTrainerTiles.size(); i++)
            {
                row = et.getRow();
                col = et.getCol();
                if (row == r && col == c)
                {
                    return; //you have already fought this trainer
                }
            }
            battledTrainerTiles.push_back(et);

            
            for (int i=0; i < trainers.size(); i++)
            {
                tile t = trainers[i].getTrainerTile();
                row = t.getRow();
                col = t.getCol();
                if (row == r && col == c)
                {
                    gymTrainer = trainers[i];
                    trainerFound = true;
                    break;
                }
            }
            if (trainerFound == false)
            {
                cout << "Failed to get the trainer too fight!" << endl;
                return;
            }
            else
            {
                trainerPokemons = gymTrainer.getTrainerPokemons();
                pm = trainerPokemons[0];
            }
        
        
            
            //pokemon pm = t.getWildPokemon(); //this is the trainer pokemon in this case
            
                while (true)
                {
                    //pm = wild pokemon, ap = active pokemon of player
                    cout << "You ran into a trainer Pokemon!" << endl;
                    cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                    cout << "\n" << endl;
                    cout << "Your Active Pokemon is: " << endl;
                    cout<<"Name: " << ap.getPokemonName()  << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl; 

                    cout << "What do you want to do (pick 1,2): \n1. Fight\n2. Switch Active Pokemon" <<endl;
                    cin >> fightOption;
                    A = pm.getSpeed(); //wild pokemon speed
                    B = (ap.getSpeed()/4)%256;  //adjusted speed of active player pokemon
                    C = 1;
                    D =  ap.getSpeed(); //active pokemon speed
                    int F = ((A*32)/B) + (30*C);
                    if (fightOption == 1)
                    {
                        cout <<"Fighting trainer Pokemon " << pm.getPokemonName() << endl;
                        if (A > D) //wild pokeman speed is greater than active pokemon speed wild pokemon will attack first
                        {
                            rndA = rand()%A + 1;// this will be a number between 1 and the wild pokemon speed
                            rndB = rand()%B + 1; // this will be a number between 1 and the adjusted speed of active pokemon
                            damage = 0;
                            if (rndA > rndB)
                            {
                                damage = rndA - rndB; //50
                                int netHP = ap.getHP() - damage;    //40 - 50
                                if (netHP <= 0)// my pokemon faints I lose
                                {
                                    ap.setHP(0);
                                    cout <<ap.getPokemonName() << " has fainted!" <<endl;
                                }
                                else
                                {
                                    ap.setHP(netHP);
                                }
                            }
                            //print stats
                            cout <<"\n" << pm.getPokemonName() << " attacks first" <<endl;
                            cout <<pm.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            cout<<"Name: " << ap.getPokemonName() << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl; 
                                                        
                            //defender attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndB > rndA)
                            {
                                damage = rndB - rndA;
                                if ((pm.getHP() - damage) <= 0)
                                {
                                    pm.setHP(0);
                                }
                                else
                                {
                                    pm.setHP(pm.getHP() - damage);
                                }
                            }
                            cout <<"\n" << ap.getPokemonName() << " attacks first" <<endl;
                            cout <<ap.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            cout<<"Name: " << ap.getPokemonName() << " HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl;                             
                        }
                        else    //my active pokemon attacks
                        {
                            //defender attacks - player pokemon attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndB > rndA)
                            {
                                damage = rndB - rndA;
                                if ((pm.getHP() - damage) <= 0)
                                {
                                    pm.setHP(0);
                                }
                                else
                                {
                                    pm.setHP(pm.getHP() - damage);
                                }
                            }
                            cout <<"\n" << ap.getPokemonName() << " attacks first" <<endl;
                            cout <<ap.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                            
                            //wild pokemon attacks
                            rndA = rand()%A + 1;
                            rndB = rand()%B + 1;
                            damage = 0;
                            if (rndA > rndB)
                            {
                                damage = rndA - rndB;
                                if ((ap.getHP() - damage) <= 0)
                                {
                                    ap.setHP(0);
                                    cout <<ap.getPokemonName() << " has fainted!" <<endl;
                                }
                                else
                                {
                                    ap.setHP(ap.getHP() - damage);
                                }
                            }
                            //print stats
                            cout <<pm.getPokemonName() << " attacks first" <<endl;
                            cout <<pm.getPokemonName() << " deals " << damage << " damage" << endl;
                            cout<<"Name: " << pm.getPokemonName() << " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 

                        }
                        //battle end condition
                        if (pm.getHP() == 0)
                        {
                            cout << "The trainer Pokemon has fainted!" << endl;
                            //ap levels up
                            p.setPoints(p.getPoints() + 60);
                            p.setnumBadges(p.getnumBadges() + 1);
                            p.setnumPokeBalls(p.getnumPokeBalls() + 5);
                            break; //turn ends
                        }
                        if (ap.getHP() == 0)
                        {
                            //player loses
                            cout << "Your Pokemon has fainted!, you lose the battle!!" << endl;
                            //pm levels up
                            break; //turn ends
                        }
                    }
                    else if (fightOption == 2)
                    {
                        cout <<"Pick another Active Pokemon (1,2,3 or 4): "<< endl;
                        for (int i = 0; i <pokedex.size(); i++)
                        {
                            cout << i+1 << ". " << pokedex[i].getPokemonName() << endl;
                        }
                        cin >> selectedPokemonNumber;
                        cout << "Your ACTIVE Pokemon is:" << endl;
                        pm = pokedex[selectedPokemonNumber-1];
                        cout<<"Name: " << pm.getPokemonName() << " (ACTIVE) "<< " HP: " << pm.getHP() << ", A: " << pm.getAttackStrength() <<  ", D: " << pm.getDefenseStrength() <<  ", S: " << pm.getSpeed() << ", M: " << pm.getMax() <<endl; 
                        p.setActivePokemon(pm);
                    }
                }   //while (true)

        } //if (gb.encounterWildPokemon(wildPokemonTiles) == true) 
        return;
}


void game :: levelupPokemon(pokemon p)
{
    int hp = p.getHPConst()*0.02 + p.getHP();
    p.setHP(hp);
    int speed = p.getSpeedConst()*0.02 + p.getSpeed();
    p.setSpeed(speed);
    int attackSpeed = p.getAttackStrengthConst()*0.02 + p.getAttackStrength();
    if (p.getMaxConst() > attackSpeed)
    {
        p.setAttackStrength(attackSpeed); 
    }
    int defenseSpeed = p.getDefenseStrengthConst()*0.02 + p.getDefenseStrength();
    if (p.getMaxConst() > defenseSpeed)
    {
        p.setDefenseStrength(defenseSpeed); 
    }
    return;
}

void game :: randomEvents()
{
    
}

void game :: playGame()
{
    int numTrainers = 15;
    int numTrainerPokemons; //randomly generated
    int numWildPokemons = 20;
    int row, col;
    tile tilePokemon, t;
    
    //create output file
    ofstream outputFile;
    outputFile.open ("resultsPokemon.txt");
    outputFile << "<Name>" << "\t" << "<Won>" << "\t" << "<Points>" << endl;
  
    //Read files and setup board
    //game g = game();
    string fileName = "pokemon.txt";
    readPokemonFile(fileName);  //creates allpokemon vector
    gameBoard gb = gameBoard();
    string fn = "mapPoke.txt";
    gb.readGameBoardFile(fn);   //creates the map

    
    //use for debugging
    //gb.showMap();
    
    //Setup trainer
    //15 trainers at Gym location and each will have 1-6 randomly selected pokemon
    vector<trainer> trainers = {};
    vector<tile> trainerTiles = gb.getTrainerTileRowCol();
    for (int i=0; i < trainerTiles.size(); i++)
    {
        trainer tr = trainer();
        numTrainerPokemons = generateRandomNumberOfPokemonForTrainer(); //generate a number between 1 to 6
        vector<pokemon> tp = getRandomTrainerPokemons(numTrainerPokemons); //vector of pokemon for the trainer
        tr.setPokemonCount(numTrainerPokemons);
        tr.setTrainerPokemons(tp);
        tr.setTrainerTile(trainerTiles[i]);
        trainers.push_back(tr);
        //cout << tr.getPokemonCount() << endl;

    }

    
    //Player will be asked to select a starter pokemon
    player p = player();
    pokemon pm;
    p.setActivePokemon(pm);
    vector<pokemon> pokedex = p.getPokedex();
    
    //Select a pokemon
    bool playerStatus = false;  //player won or lost
    string playerName;
    int pokemonChoice;
    cout<<"Welcome to Pokemon!"<<endl;
    cout<<"Please state your name:"<<endl;
    //cin.ignore();
    getline(cin, playerName,'\n');
    while(true)
    {
        cout<<"Welcome, " << playerName << "! Before you can begin your" << endl;
        cout<<"Pokemon adventure, you must choose a starting" <<endl;
        cout <<"Pokemon, courtesy of the Professor. Please" <<endl;
        cout<<"choose form the following Pokemon:"<<endl;
        cout<<" 1. Bulbasaur"<<endl;
        cout<<" 2. Charmander"<<endl;
        cout<<" 3. Squirtle"<<endl;
        cout<<" 4. Pikachu"<<endl;

        cin >> pokemonChoice;
        if (pokemonChoice == 1)
        {
            p.setActivePokemon(pokemon(1, "Bulbasaur", 45, 49, 49, 45,65)) ;
            gb.setActivePokemonRow(12);
            gb.setActivePokemonCol(6);
            break;
        }
        else if (pokemonChoice == 2)
        {
            p.setActivePokemon(pokemon(2, "Charmander", 39, 52, 43, 65,50)) ;
            gb.setActivePokemonRow(12);
            gb.setActivePokemonCol(7);
            break;
        }    
        else if (pokemonChoice == 3)
        {
            p.setActivePokemon(pokemon(3, "Squirtle", 44, 48, 65, 43,50));
            gb.setActivePokemonRow(12);
            gb.setActivePokemonCol(8);       
            break;
            
        }    
        else if (pokemonChoice == 4)
        {
            p.setActivePokemon(pokemon(4, "Pikachu", 35, 55, 30,90,50));
            gb.setActivePokemonRow(12);
            gb.setActivePokemonCol(9);
            break;
        }        

        else
        {
            cout<<"Invalid entry, try again"<<endl;
        }

    }
    pokemon ap = p.getActivePokemon();
    //add active pokemon to pokedex
    p.addPokemonToPokedex(ap);
    pokedex = p.getPokedex();
    
    //get land tiles
    row = gb.getActivePokemonRow();
    col = gb.getActivePokemonCol();
    vector<tile> landTiles = gb.getLandTileRowCol();
    vector<tile> landTilesWithoutAP = {};
    for (int i=0; i< landTiles.size(); i++)
    {
        tile t = landTiles[i];
        if (t.getRow() == row && t.getCol() == col)
        {
            //do nothing
        }
        else
        {
            landTilesWithoutAP.push_back(t);
        }
    }
    //Generate random wild pokemon tile locations
    getRandomWildPokemonLocations(landTilesWithoutAP, numWildPokemons); //247 landtiles 153 water tiles
    //Generate wild pokemons randomly
    vector<pokemon> wp = getRandomWildPokemons(numWildPokemons);//20 genereated pokemons are in numWildPokemon
    //Assign wild pokemons to tiles
    for (int i=0; i<wildPokemonTiles.size(); i++)
    {
        int r = wildPokemonTiles[i].getRow();
        int c = wildPokemonTiles[i].getCol();
        gb.setMapChar(r,c,'P'); //wild pokemon
        wildPokemonTiles[i].setWildPokemon(wp[i]);
        //cout << "WildPokemon is " << wildPokemonTiles[i].getWildPokemon().getPokemonName() <<endl;
        //cout << "WildPokemon is " << wp[i].getPokemonName() <<endl;
    }
   
    while (true) //turns of game
    {
        //big while loop for each turn of the game2
        cout << "\n" << endl;
        gb.show7x7Area();
        int gameOption, row, col;
        //show message
        cout<<"\nThe sun is shining, " << playerName << "! It's a beautiful day, we have " << p.getnumPokeBalls() << " Pokeballs left and your Pokemon are strong.\n"<<endl;
        cout<<"Name: " << ap.getPokemonName() << " (ACTIVE), " << "HP: " << ap.getHP() << ", A: " << ap.getAttackStrength() <<  ", D: " << ap.getDefenseStrength() <<  ", S: " << ap.getSpeed() << ", M: " << ap.getMax() <<endl; 
        cout<<"Please choose from the following options:"<<endl;
        cout<<"1. Travel"<<endl; 
        cout<<"2. Rest"<<endl; 
        cout<<"3. Try your luck"<<endl;
        cout<<"4. Quit the game"<<endl;
        cin >> gameOption;
        if(gameOption == 1)
        {
            while (true)
            {
                int d;
                cout <<"Choose direction of travel"<<endl;
                cout<<"1. East"<<endl;
                cout<<"2. West"<<endl;
                cout<<"3. North"<<endl;
                cout<<"4. South"<<endl;
                cin >> d;
                
                //string d =  generateRandomDirection();
                row = gb.getActivePokemonRow();
                col = gb.getActivePokemonCol();
                if(d == 1)
                {
                   col = col + 1;
                }
                if(d == 2)
                {
                   col = col - 1;
                }       
                if(d == 3)
                {
                   row = row - 1;
                }
                if(d == 4)
                {
                   row = row + 1;
                }

                //If next tile is water or outside the board, ask again
                if ((gb.getMapChar(row,col) == 'w') || (row>25) || (row<0) || (col >15) || (col <0))
                {
                   cout<<"You got into water or outside map area, choose again!\n"<<endl;
                }
                else if (gb.getMapChar(row,col) == 'C')
                {
                    gotoPokemonCenter(pokedex); //all stats are restored to design values
                }
                else
                {
                    gb.setActivePokemonCol(col); 
                    gb.setActivePokemonRow(row);
                    cout<<"Player pokemon has travelled\n"<<endl;
                    break;
                }
            }   //while east/west/north/south

        }   //gameoption = 1
        else if (gameOption == 2)
        {
            //rest
           for(int i = 0; i<pokedex.size();i++)
           {
                pm = pokedex[i];
                int hp = pm.getHP();
                pm.setHP(hp + 1);
                int x = p.getnumPokeBalls();
                if(x > 0)
                {
                    p.setnumPokeBalls(x-1);
                }
           }
           cout<<"Player stats were updated for Rest option\n"<<endl;
    
        }   //gameoption = 2
        else if (gameOption == 3)
        {
            //try your luck
            bool b = random50();
            if (b == true) //you win, so you are lucky
            {
                if (gb.encounterWildPokemon(wildPokemonTiles) == true)  //5x5 area
                {
                    tile t = gb.getEnemyWildPokemonTile();
                    pm = t.getWildPokemon();
                    p.addPokemonToPokedex(pm);
                    cout<<"A pokemon was added to pokeDex as you are lucky\n"<<endl;
                } 
            }
            cout<<"You have tried your luck!"<<endl;

        }   //gameoption = 3
        else if (gameOption == 4)
        {
            playerStatus = false;
            cout<<"You have lost the game!"<<endl;
            break;
        }   //gameoption = 4
        else
        {
            cout<<"Invalid entry, try again"<<endl;
        }
        //gameOptions end here
        
        
        if (gameOption == 4)
        {
            break;  //no more game
        }
        
        
        //update player status - location, hp, pokeballs
        row = gb.getActivePokemonRow();
        col = gb.getActivePokemonCol();
        //gb.setMapChar(row,col,'@'); //active pokemon
        //gb.showMap();
        cout <<"Player stats updated!" <<endl;
        
        //update wild pokemon locations
        /*
        for (int i=0; i< wildPokemonTiles.size(); i++)
        {
            tilePokemon = wildPokemonTiles[i];
            row = tilePokemon.getRow();
            col = tilePokemon.getCol();
            vector<int> v = {1,2,3,4};
            while (true)
            {
                int d = rand()%4 + 1;
                if(d == 1)
                {
                   col = col + 1;
                }
                else if(d == 2)
                {
                   col = col - 1;
                }       
                else if(d == 3)
                {
                   row = row - 1;
                }
                else if(d == 4)
                {
                   row = row + 1;
                }
    
                if ((gb.getMapChar(row,col) == 'w') || (row>25) || (row<0) || (col >15) || (col <0) || (gb.getMapChar(row,col) == 'C') || (gb.getMapChar(row,col) == 'G') || (gb.getMapChar(row,col) == '@') )
                {
                   cout<<"Wild pokemonn stepped on forbidden tile, regenerating direction!\n"<<endl;
                }
                else
                {
                    tilePokemon.setRow(row);
                    tilePokemon.setCol(col);
                    gb.setMapChar(row,col,'P'); //wild pokemon
                    break;
                }
            }

        
        }
        */
        //gb.showMap(); //debug for wild pokemon location
        cout <<"Wild pokemons location updated!" <<endl;
        
        //Fight the wild pokemon, if found
        fightWildPokemon(gb, p, ap, pokedex);
        
        //Fight the trainer pokemon, if found
        fightTrainerPokemon(gb, p, ap, pokedex, trainers);
    
        
        //random events - 30% another pokemon spawned
        if (random30() == true)
        {
            int choice;
            string s;
            int index = rand()%150 + 1; //total pokemon are 151 (150 is the last index value)
            pokemon pk = allPokemons[index];
            cout << "Suddenly, " << pk.getPokemonName() << " appears in your path. Do you want to:\n1. Catch it\n2. Release it" << endl;
            cin >> choice;
            if (choice == 1)
            {
                p.addPokemonToPokedex(pk);
                cout << "Awesome! " << pk.getPokemonName()  << " joins the Pokedex. You still have room your battle party. Do you want to make it the active Pokemon? (Y/N)" << endl;
                cin >> s;
                if (s == "Y")
                {
                    p.setActivePokemon(pk);
                }
            }

        }
        //random events - 25% hidden treasure
        if (random25() == true)
        {
            cout <<"Great news! You have stumbled upon a hidden stash of Pokeballs. Your reserves increased to 4 Pokeballs" << endl;
            p.setnumPokeBalls(p.getnumPokeBalls() + 4);
        }
        
        //random events - 20% pokeman dies
        if (random20() == true)
        {
            cout << "Oh no! After years of legendary batlles, Bulbasaur died of old age. Thank you for your companionship, dear friend." << endl;
        }
        
        //game end conditions
        if ( (p.getnumBadges() >= 6) || (pokedex.size() >= 8) )
        {
            playerStatus = true;
            cout <<"You have won the game!!!" <<endl;
            break;
        }

    
        
    } //while loop for turn
    
    //write the file
    //name won points
    string status = "Y";
    if (playerStatus == false)
    {
        status = "N";
    }
    else
    {
        status = "Y";
    }
    outputFile << playerName << "\t" << status << "\t" << p.getPoints() << endl;
    outputFile.close();
}
