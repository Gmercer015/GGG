#ifndef MAP_H
#define MAP_H
#include <string>
#include "Map.h"
#include "Player.h"
#include <vector>
class Map
{
    public:
        void createmap() ;
        void InputChoice(int pN); //pN(Player Number)
        Map(int noP); //number of PLAYERS
        void SSP(); //SET START POSITION
        void RefreshScreen(); //reprint array
        void cls();
        void callFire(int pN); //call the fire function using map
        bool Game(); //used for main loop, ends when player dies.
        bool GetBool(){return game;}
        void SetBool(const bool TF){game = TF;}
    private:
        static const int nrows = 20; //array bounds
        static const int ncols = 20;
        char map[nrows][ncols];
        char bgmap[nrows][ncols];
        Player pObj; //a map HAS a player, a player is NOT a map(thanks you guys for that logic, helped A LOT)
        Player ptObj;
        bool game;
};
#endif // MAP_H
