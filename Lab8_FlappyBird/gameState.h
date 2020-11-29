/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		gameState.h
 * Description:	Actual game being played.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "pipe.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

//chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
//un init, update, draw et handleInput différent pour chaque fenêtre.
class gameState : public state
{
private:
    gameDataRef _data;  //chaque state recevra le pointeur sur la gameData qui
                        //donne accès au stateMachine, au RenderWindow, au
                        //assertManager et au inputManager

    Sprite _background; //le sprite pour la background
    pipe* _pipe;        //un pointeur de pipe

public:
    gameState(gameDataRef data);

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt) const;
};
