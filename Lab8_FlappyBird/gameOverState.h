/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		gameOverState.h
 * Description:	Game over menu state.   
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

//chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
//un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameOverState : public state
{
private:
    gameDataRef _data;  //chaque state recevra le pointeur sur la gameData qui
                        //donne acc�s au stateMachine, au RenderWindow, au
                        //assertManager et au inputManager

    Sprite _background; //le sprite pour la background
    Sprite _title;
    Sprite _body;

public:
    gameOverState(gameDataRef data);

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt) const;
};
