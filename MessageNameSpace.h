#ifndef MESSAGENAMESPACE_H_INCLUDED
#define MESSAGENAMESPACE_H_INCLUDED

#include "Map.h"

namespace Message //All functions that have to do with displaying information
{
    extern char MenuStruct[][70]; //Main menu look
    extern char bgMenuStruct[][70]; //background menu, remains unchanged
    struct Cords; //holds x and y position of those the front and background map
    enum {NUMMENUSTRUCTS = 11, MENUCHOICES = 4}; //NUMMENU is the amount of rows, menuchoices represents the number of options
    void RefreshMenu(Map &Obj);//refresh the map
    void delay(unsigned long ms); //delay in miliseconds
    void DisplayWinner(bool Winner); //Display the winner of the game
    void PrintOpening(); //print opening of the game
    void RunMenu(Map& Obj); //Project the menu and handle input
    Cords FindCursor(int,Cords&); //return struct for x and y, finds the position of the x
    void SetCursor(Cords&); //set the new position of the x
    bool SelectItem(int&,bool&); //select and display the item chosen
    void Reset(); //reset data so the menu can run again.
    void SwitchPlayers(int,Map&); //display the changing of the players
}

#endif // MESSAGENAMESPACE_H_INCLUDED
