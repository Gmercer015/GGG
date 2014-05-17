//VERSION 1.09a, created by Grant Mercer in c++
//changes --
///The game no longer takes bad input as a turn
///removed 'I' characters to make players seen and board cleaner
///TO-DO list for v1.09b
    //
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include "MessageNameSpace.h"
/// Declaring main varibles to be used inside of main loop
bool Game = true;
bool pOneTurn = true;
bool pTwoTurn = false;
bool Winner = true;

/// Declaring function to be used inside main
bool Restart(Map& Ob);
void LoopGame(Map& mObj);
/// End function/variable declaration
int main()
{
    Map mObj(2);
    Message::PrintOpening();
    Message::RunMenu(mObj);
    do{LoopGame(mObj);}while(Restart(mObj));
    std::cout << "\n\t\tThanks for playing!";
}

bool Restart(Map& Ob)
{
    Message::delay(2500);
    Message::RunMenu(Ob);
    return true;
}

void LoopGame(Map& mObj)
{
        pTwoTurn = false;
        pOneTurn = true;
        mObj.SetBool(true); //set the game bool to start running, mostly important when the
        //player restarts. Since the bool ended in false, it needs to be mannually reset to true
        mObj.createmap();
        mObj.SSP(); //set starting position
        mObj.RefreshScreen();
        while(mObj.GetBool()){ /// MAIN LOOP(WHILE GAME RUNNING)
            while(pOneTurn && mObj.GetBool()){ /// PLAYER ONE'S TURN
                int moves = 0;
                while(moves < 3 && mObj.GetBool()){
                    std::cout  << "PLAYER ONE w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)"; //display controls and stats
                    std::cout  << "\n --- MOVES LEFT --- " << 3 - moves << std::endl;
                    mObj.InputChoice(1); //run input function to see where to move
                    mObj.RefreshScreen(); //rewrite the array
                    Game = mObj.GetBool();
                    moves++;
                }
                if(mObj.GetBool())
                    Message::SwitchPlayers(2,mObj);
                mObj.RefreshScreen();
                Winner = true; //means player one wins
                pTwoTurn = true; //set player twos turn to true
                pOneTurn = false; //set player ones turn to false
            }
            while(pTwoTurn && mObj.GetBool()){ /// PLAYER TWO'S TURN
                int moves=0;
                while(moves < 3 && mObj.GetBool()){
                    std::cout << "PLAYER TWO w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)";
                    std::cout << "\n --- MOVES LEFT --- " << 3-moves << std::endl;
                    mObj.InputChoice(2);
                    mObj.RefreshScreen();
                    Game = mObj.GetBool();
                    moves++;

                }
                if(mObj.GetBool())
                    Message::SwitchPlayers(1,mObj);
                mObj.RefreshScreen();
                Winner = false; //player two wins
                pOneTurn = true;
                pTwoTurn = false;
            }
        }
        mObj.cls();
        Message::DisplayWinner(Winner); //display winner of game
}
