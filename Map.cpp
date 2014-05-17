#include "Map.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <windows.h>
Map::Map(int pN)
{
}

void Map::SSP() //calls player function
{
            pObj.SetStartPos('B',map,5,5);
            ptObj.SetStartPos('O',map,15,15);
}
void Map::InputChoice(int pN) //player NUMBER
{
    switch(pN){
        case 1:
            pObj.InputChoice(*this,'B',map,bgmap,1); //calls player functions
            break;
        case 2:
            ptObj.InputChoice(*this,'O',map,bgmap,2);
            break;
    }
}
void Map::RefreshScreen() //reprint array
{
    cls();
    for( int nrow = 0; nrow < nrows; nrow++){
            for(int ncol = 0; ncol < ncols;ncol++)
                std::cout << map[nrow][ncol] << " ";
            std::cout << std::endl;
            }
}
void Map::cls() //windows h function to replace screen with nulls
{
  DWORD n;
  DWORD size;
  COORD coord = {0};
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  GetConsoleScreenBufferInfo ( h, &csbi );
  size = csbi.dwSize.X * csbi.dwSize.Y;
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );
  SetConsoleCursorPosition ( h, coord );
}
void Map::callFire(int pN)
{
    switch(pN){
        case 1:
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            pObj.FireG(&game,1,*this, map, bgmap, pObj.getx(), pObj.gety());
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            break;
        case 2:
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            ptObj.FireG(&game,2,*this, map, bgmap,ptObj.getx(),ptObj.gety()); //ERRORS HERE!
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            break;
    }
}
void Map::createmap() { //read map in from "Map.txt" file
    using namespace std;
    ifstream MapStruct("Map.txt");
    while(!MapStruct.eof()){
        for( int nrow = 0; nrow < nrows; nrow++){
            for(int ncol = 0; ncol < ncols;ncol++){
                    MapStruct >> map[nrow][ncol];
                    if(map[nrow][ncol] == 'I')
                        map[nrow][ncol] = ' ';
                    bgmap[nrow][ncol] = map[nrow][ncol];
                }
            }
        }
MapStruct.close(); //close file to prevent leaks
}

bool Map::Game() //checks if player is killed by the H's, returns false if true and main loop will terminate
{
    if(map[pObj.gety()][pObj.getx()] == 'H' || map[ptObj.gety()][ptObj.getx()] == 'H')
    {
        return false;
    }
    return true;
}
