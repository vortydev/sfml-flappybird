/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		gameState.h
 * Description:	Actual game being played.
 */

#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameOverState.h"
#include "pipe.h"
#include "land.h"
#include "bird.h"
#include "collision.h"
#include "flash.h"
#include "hud.h"

using namespace sf;
using namespace std;

//chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
//un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameState : public state
{
private:
    gameDataRef _data;  //chaque state recevra le pointeur sur la gameData qui
                        //donne acc�s au stateMachine, au RenderWindow, au
                        //assertManager et au inputManager

    Clock _clock;

    int _gameState; // �tat du jeu
    int _score;     // score du joueur

    Sprite _background; //le sprite pour la background

    pipe* _pipe;        //un pointeur de pipe
    land* _land;
    bird* _bird;
    flash* _flash;
    hud* _hud;

    collision _collision;

    // audio
    /*SoundBuffer _hitSoundBuffer;
    SoundBuffer _pointSoundBuffer;
    SoundBuffer _wingSoundBuffer;

    Sound _hitSound;
    Sound _pointSound;
    Sound _wingSound;*/

public:
    gameState(gameDataRef data);
    ~gameState();

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt) const;
};