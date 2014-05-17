#include "MessageNameSpace.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

extern void Instructions();
extern void Credits();

namespace Message
{
    struct Cords
    {
        int x; //x and y cords of menu
        int y;
        int bgx; //background x y cords of menu
        int bgy;
    };


    char MenuStruct[NUMMENUSTRUCTS][70]=
        {
        {"--------------------------------------------------------------------"},
        {"|                                                                  |"},
        {"|         PLAY                 INSTRUCTIONS                        |"},
        {"|                                                                  |"},
        {"|         CREDITS              EXIT                                |"},
        {"|                                                                  |"},
        {"--------------------------------------------------------------------"},
        {"              s to navigate, space to select                        "}
        };
        //POS 1 is INSTRUCTIONS
        //POS 2 is PLAY
        //POS 3 is CREDITS
        //POS 4 is EXIT
    char bgMenuStruct[NUMMENUSTRUCTS][70];


        //[2][16] is the space infront of PLAY
        //[2][37] is the space infront of INSTRUC.
        //[5][16]
        //[5][37]
    void RunMenu(Map& Obj)
    {
        bool Game = true;
        Cords Pos; //create a struct to store cords of the menu options
        static int Position = 1;
        char c;
        for(int r = 0; r < NUMMENUSTRUCTS;r++){for(int c = 0; c < 70; c++)
        bgMenuStruct[r][c] = MenuStruct[r][c];} //sets a background map
        RefreshMenu(Obj);
        do{
        c = getch(); //get input from user
        switch(c)
        {
            case 's':
                Position++;
                if(Position == 5){Position = 1;} //only 4 options, resets back to option one
                FindCursor(Position,Pos); //find the position of the current and next menu item
                SetCursor(Pos); //set the cursor to the desired menu option
                RefreshMenu(Obj); //refresh screen
                break;
            case ' ':
                Obj.cls();
                char * x = new char;
                delete x;
                SelectItem(Position,Game);
                break;

        }

        }while(Game);
        Reset();
    }

    void SwitchPlayers(int x, Map& o)
    {
        if(x == 1)
        {
            o.cls();
            std::cout << "\n\n\n\n\n\n\t\t\tPLAYER ONE'S TURN";
            delay(600);
        }else{
            o.cls();
            std::cout << "\n\n\n\n\n\n\t\t\tPLAYER TWO'S TURN";
            delay(600);
        }
    }

    void Reset()
    {
        MenuStruct[2][30] = ' '; //space infront of PLAY
        MenuStruct[2][9] = ' ';
        MenuStruct[4][30] = ' ';
        MenuStruct[4][9] = ' ';
    }
    bool SelectItem(int& Pos, bool& Game)
    {
        switch(Pos)
        {
            case 1: Instructions(); break;
            case 2: Game = false; break;
            case 3: Credits();break;
            case 4: exit(0); break;
        }
        return true;

    }
    void SetCursor(Cords& mCord)
    {
        MenuStruct[mCord.x][mCord.y] = 'x'; //put an x next to the new menu option
        MenuStruct[mCord.bgx][mCord.bgy] = bgMenuStruct[mCord.bgx][mCord.bgy]; //replace the last x
        //with whatever the menu orignally had in its place
    }
    Cords FindCursor(int Position, Cords& mCord)
    {
        static int x = 4; //random coordinates to start off as the background cords
        static int y = 12; //static so they hold onto the previous cords after the function ends
        mCord.bgx = x; //set back ground cords, which read the position of the function before hand
        mCord.bgy = y; //before running again, grabbing the cords of the last menu item.
        switch(Position)
        {
            case 1:
                x = 2; //space infront of PLAY
                y = 30;
                break;

            case 2:
                x = 2; //space infront of CREDITS
                y = 9;
                break;
            case 3:
                x = 4; //space infront of EXIT
                y = 9;
                break;
            case 4:
                x = 4; //space infront of INSTRUCTIONS
                y = 30;
                break;

        }
        mCord.x =  x; //set the struct variables to the new cords
        mCord.y =  y;
        return mCord; //return the structure
    }
    void RefreshMenu(Map &Obj)
    {
        Obj.cls();
        for(int r = 0; r < NUMMENUSTRUCTS;r++)
        {
            for(int c = 0; c < 70;c++)
            {
                std::cout << MenuStruct[r][c];
            }
            std::cout << std::endl;
        }
    }
    void DisplayWinner(bool Winner)
    {
            std::string NAME;
            if(Winner){NAME = "PLAYER ONE WINS";}else{NAME = "PLAYER TWO WINS";}
            std::cout <<"        __,:,__               __,:,__               __,:,__\n";
            std::cout <<"     ,ad88P`Y88ba,         ,ad88P`Y88ba,         ,ad88P`Y88ba,\n";
            std::cout <<"   ad88888' `88888ba     ad88888' `88888ba     ad88888' `88888ba\n";
            std::cout <<" ,d88888P'   `Y88888b, ,d88888P'   `Y88888b, ,d88888P'   `Y88888b,\n";
            std::cout <<",d888P\"'       `\"Y888b,d888P\"'       `\"Y888b,d888P\"'       `\"Y888b,\n";
            std::cout <<":([\"               ``\":\"''               ``\":\"''               \"]):\n";
            std::cout <<"`Y88ba,                                                     ,ad88P'\n";
            std::cout <<" `88888ba                                                 ad88888'\n";
            std::cout <<"  `Y88888b,                                             ,d88888P'\n";
            std::cout <<"    `\"Y888b,                                           ,d888P\"'\n";
            std::cout <<"        \"]):            "; std::cout << NAME << "                :([\"\n";
            std::cout <<"     ,ad88P'                                           `Y88ba,\n";
            std::cout <<"   ad88888'                                             `88888ba\n";
            std::cout <<" ,d88888P'                                               `Y88888b,\n";
            std::cout <<",d888P\"'                                                   `\"Y888b,\n";
            std::cout <<":([\"               __,:,__               __,:,__               \"]):\n";
            std::cout <<"`Y88ba,         ,ad88P`Y88ba,         ,ad88P`Y88ba,         ,ad88P'\n";
            std::cout <<" `88888ba     ad88888' `88888ba     ad88888' `88888ba     ad88888'\n";
            std::cout <<"  `Y88888b, ,d88888P'   `Y88888b, ,d88888P'   `Y88888b, ,d88888P'\n";
            std::cout <<"    `\"Y888b,d888P\"'       `\"Y888b,d888P\"'       `\"Y888b,d888P\"'\n";
            std::cout <<"        ``\":\"''               ``\":\"''               ``\":\"''\n";
    }

    void delay( unsigned long ms ) //sleep for _ miliseconds
        {
            Sleep( ms );
    }

    void PrintOpening()
    {
            std::cout <<"Hard coded in c++ Code::Blocks::10.05 Version 1.09A Artwork by Chris/ASCII\n";
            delay(100);
            std::cout <<"        ^+xw*\"\"\"^q_  0 p\" F  F _F  p^^\"___jM   j  F              F\n";
            delay(100);
            std::cout <<"      _,,__   q x\" [  F J_ J  P  w\"\"\"\"_  _,\"  9  _m^`\"*____x\"    _____\n";
            delay(100);
            std::cout <<" v,,_w\"   \"M_ @ `, \",_!u_9__L F #  r^\"\"^^\"    f j\"      \"      _*\"   \"6_\n";
            delay(100);
            std::cout <<"     _,,__  B 9_ \"v,_Zp*\"\"\"\"\"^@u# P _m^\"^u,a*\"  j   ____       9       \"\"\n";
            delay(100);
            std::cout <<"   _F    `4 A_ \"*-ap\"            ^Lj\" _smu,    _* ,-\"   9_   _wf\n";
            delay(100);
            std::cout <<" ^^\"__,,_ jL  -- m<                5j! ____*-*^   &       \"\"\"\"     ___\n";
            delay(100);
            std::cout <<"   p\"    9p`^u,av'    Two Player    `,*\"\"\"\"q_   _x\" _aa,_        p^\" \"\"u\n";
            delay(100);
            std::cout <<" ,r  _____!L___,M      Shooter       Lsr--x_\"^^`\" qP     9      J      `M\n";
            delay(100);
            std::cout <<"   y^    \"_    _J      By Grant      L_,,_ ?_    _#       ^v- -^\"\n";
            delay(100);
            std::cout <<"  _F  __,_`^---\"jr      Mercer      j___ \"\"y\"\"^^\"\"_,-r-u_\n";
            delay(100);
            std::cout <<" r^ j!    ?s_, *\"jp                g\"\"\"\"^q_b_    _F     \"p      j^^\"\"-w\n";
            delay(100);
            std::cout <<"    L  _,wma_  _x\"jN__          __d\"\"\"^c  F  \"-^\"\"  _    \"c____j'      L\n";
            delay(100);
            std::cout <<"   j\" J\"    \"\"\"  _F 99Nu______g**L_\"\"s  4 A,    _P\"\"\"^q_    \"\"         \"-\n";
            delay(100);
            std::cout <<" m^  j_  _-^\"\"mw^\" _' # 9\"N\"\"L ^, \"s  b #   \"--^\"      0\n";
            delay(100);
            std::cout <<"      @ j\"   _v-wa+\" ,\" j  #  p  r j qF \"q_   _*-wu_   9,     y^`\"^w_\n";
            delay(100);
            std::cout <<"   _,!  0_  f   _m-**\" _F _F  L _FjP ?,    \"^\"\"    \"u    \"---^      j\n";
            delay(100);
            std::cout <<" \"\"\"     # J   j\"   p\"\"\"p-^ x^ p\" d_   -q__a-mw_    j               `L\n";
            delay(100);
            std::cout <<"        V  `q  #   f   j   4   b   ^,   __      6_  ?,     _,__       \"--\n";
            delay(100);
            std::cout <<" *`^ww-\"     F 9L_ b   1   4   `u_   \"-^\"\"*,    jh    ^-xm*\"   9z\n";
            delay(100);
            std::cout <<"            )    0 `+a_ W__ 9,___\"^^\"+_     L   0                k\n";
            delay(100);
            std::cout <<"     _x-*v+\"     9    0   \"b    \"_    \"p   _0   `&    ___       d_\n";
            std::cout <<"\t\t PLEASE WAIT";
            delay(3000);
    }
}
