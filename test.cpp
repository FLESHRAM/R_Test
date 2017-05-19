/*
*    Example program for the Allegro library, by Shawn Hargreaves.
*
*    This is a very simple program showing how to get into graphics
*    mode and draw text onto the screen.
*/


// Enum for possible directions
enum inputDirection 
{ 
    NO_INPUT = 0, 
    UP, 
    DOWN, 
    LEFT, 
    RIGHT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    EXIT 
};


#include <iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <windows.h>
#include <conio.h>
#include ".\lib\Thing.cpp"
#include ".\lib\Character.cpp"
#include ".\lib\Spot.cpp"
#include ".\lib\Place.cpp"




using namespace std;

int Place::maxWidth = 77;
int Place::maxHeight = 77;
int Place::minHeight = 3;
int Place::minWidth = 3;

char CURR_UP_KEY = 'w';
char CURR_DOWN_KEY = 's';
char CURR_LEFT_KEY = 'a';
char CURR_RIGHT_KEY = 'd';
char EXIT_KEY = 'p';

bool VALID_KEY(char key, char desired)
{
    if
    (
        tolower(key) == tolower(desired) || 
        toupper(key) == toupper(desired)
    ) return true;

    return false;
}

bool UP_KEY(char key) { return VALID_KEY(key, CURR_UP_KEY); }

bool DOWN_KEY(char key) { return VALID_KEY(key, CURR_DOWN_KEY); }

bool LEFT_KEY(char key) { return VALID_KEY(key, CURR_LEFT_KEY); }

bool RIGHT_KEY(char key) { return VALID_KEY(key, CURR_RIGHT_KEY); }

bool QUIT_PRESSED(char key) { return VALID_KEY(key, EXIT_KEY); }


const short unsigned int Keyleft  = 37;
const short unsigned int Keytop   = 38;
const short unsigned int Keyright = 39;
const short unsigned int Keydown  = 40;
const short unsigned int Keyexit  = 81;


int width;
int height;

bool changeFlag = false;

Place * currentPlace;

inputDirection getDirection()
{
    if(_kbhit())
    {
        char key = _getch();

        if(UP_KEY(key) && LEFT_KEY(key))
        {
            return UP_LEFT;
        }

        else if(UP_KEY(key) && RIGHT_KEY(key))
        {
            return UP_RIGHT;
        }

        else if(DOWN_KEY(key) && LEFT_KEY(key))
        {
            return DOWN_LEFT;
        }

        else if(DOWN_KEY(key) && RIGHT_KEY(key))
        {
            return DOWN_RIGHT;
        }

        else if(UP_KEY(key))
        {
            return UP;
        }

        else if(DOWN_KEY(key))
        {
            return DOWN;
        }

        else if(LEFT_KEY(key))
        {
            return LEFT;
        }

        else if(RIGHT_KEY(key))
        {
            return RIGHT;
        }

        else if(QUIT_PRESSED(key))
        {
            return EXIT;
        }
    }

    return NO_INPUT;
}


void DrawWallH(int w = width)
{
    for(int i = 0; i<=w+1; i++)
    cout << "#";

    cout << endl;
}


void DrawWorld(int w = width, int h = height)
{
    system("cls");   

    DrawWallH(w);



    DrawWallH(w);
}


void PrintStatus(char * status = NULL)
{
    cout << "STATUS: ";

    // if(status == NULL)
    // {
        
    // }

    cout << endl;
    return;
}


void DrawWorld(Place * p)
{
    system("cls"); 

    DrawWallH(p->getW());

    int height = p->getH();
    int width = p->getW();

    for (int i = 0; i<height; i++)
    {
        cout << '#';

        for (int j = 0; j<width; j++)
        {
            cout << p->getSpotRender(i, j);
        }

        cout << "#" << endl;
    }

    DrawWallH(p->getW());

    PrintStatus();
}


void PrintHealthStatus(Character * c)
{
    int life = c->getLife();

    cout << endl << "LIFE: ";

    for(int i = 0; i <= life; i++)
    cout << "* ";

    cout << endl;

}


int main()
{
    //width = maxWidth;
    //width = maxHeight;

    currentPlace = new Place(50, 50);

    Character *player = new Character();
    player->overrideRender('&');  

    currentPlace->placeInSpot(15, 15, player);

    DrawWorld(currentPlace);
    PrintHealthStatus(player);

    inputDirection dir = getDirection();

    while(dir != EXIT)
    {
        if(changeFlag)
        {
            DrawWorld(currentPlace);
            PrintHealthStatus(player);
            changeFlag = false;
        }

        dir = getDirection();

        if(dir != NO_INPUT)
        changeFlag = currentPlace->moveThing(dir, player);
    }

    return 0;
}