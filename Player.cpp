#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "Map.h"
#include "Player.h"
#include <time.h>
#include <conio.h>


Player::Player()
{
}


void Player::InputChoice(Map& screen,char c,char map[][20], char bgmap[][20], int pN)
{
        char x;

        do{
            x = getch();    //read in chars until the input is good
        }while(Badinput(x)); //function that returns true if input is bad
         switch(x){
                case 'w' :        //moves 'x' up one and replaces the coord before with what it originally had
                    if(map[yp-1][xp] == '#') break;
                    if(yp <= 0){
                        yp = 0;
                        break;
                    }
                    yp-=1;
                        map[yp + 1][xp] = bgmap[yp + 1][xp]; //replace last coord with the background map, which stays constant.
                    break;
                case 's':
                    if(map[yp+1][xp] == '#') break;
                    if(yp >= 19){
                        yp = 19;
                        break;
                    }else{yp+=1;}
                        map[yp - 1][xp] = bgmap[yp - 1][xp];
                    break;
                case 'a':
                    if(map[yp][xp - 1] == '#') break;
                    if(xp <= 0){
                        xp = 0;
                        break;
                    }else{xp -=1;}
                        map[yp][xp + 1] = bgmap[yp][xp + 1];
                    break;
                case 'd':
                    if(map[yp][xp + 1] == '#') break;
                    if(xp >= 19){
                        xp = 19;
                        break;
                    }else{xp +=1;}
                        map[yp][xp - 1] = bgmap[yp][xp - 1];
                    break;
                case 'g':
                    screen.callFire(pN);
            }
            map[yp][xp] = c; //set current position to 'x', later in this project i will be using a varible when i ask how to put in multiple players
            // and study vectors a little more(lots of learning to do!).
}
void Player::SetStartPos(char c,char map[][20],int xx, int yy)
{
    xp = xx;
    yp = yy;
    map[xp][yp] = c;
}
void Player::FireG(bool *Game, int pN,Map& screen,char map[][20], char bgmap[][20], int xcord, int ycord) //FIRE function
{
    int Path = 1;
    if(pN==2){
        while(map[ycord][xcord - Path] != 'G' && map[ycord][xcord] != '#'){
            xcord -= Path;
            if(map[ycord][xcord] == '#')//check if barrier
            {
                map[ycord][xcord] = '^';
                bgmap[ycord][xcord] = '^';//set background map to ^ so that when H's are deleted the # does not reset
                break;
            }
            map[ycord][xcord] = 'H'; //this is the "Object" the player fires
            delay(85); //wait 3 seconds before refreshing the screen

            screen.cls();
            screen.RefreshScreen();
            *Game = screen.Game(); //set bool to check if a player is killed
        }
        delay(200); //delay 2 seconds
        for(int i = 19; i--; i == 0) //run through the x coordinates of the graph, deleting all H's found
            if(map[ycord][i] == 'H'){map[ycord][i] = bgmap[ycord][i];}
    }else{
        while(map[ycord][xcord + Path] != 'G' && map[ycord][xcord] != '#'){
            xcord += Path;
            if(map[ycord][xcord] == '#')
                        {
                            map[ycord][xcord] = '^';
                            bgmap[ycord][xcord] = '^';
                            break;
                        }
            map[ycord][xcord] = 'H'; //this is the "Object" the player fires
            delay(100); //wait 3 seconds before refreshing the screen, this function is not completely
            //finished yet, still working on deleting the H's on the map now.

            *Game = screen.Game();
            screen.cls();
            screen.RefreshScreen();

        }
        delay(200);
        for(int i = 19; i--; i == 0)
            if(map[ycord][i] == 'H'){map[ycord][i] = bgmap[ycord][i];}
    }
}
  inline void Player::delay( unsigned long ms ) //sleep for _ miliseconds
    {
    Sleep( ms );
    }

bool Player::Badinput(char x)
{
    char input[5] = {'w','s','a','d','g'};
    for(int i = 0; i < 5;i++)
    {
        if(x == input[i])
            return false;
    }
    return true;
}
