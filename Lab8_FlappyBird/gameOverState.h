/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		gameOverState.h
 * Description:	Game over menu state.   
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

//chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
//un init, update, draw et handleInput différent pour chaque fenêtre.
class gameOverState : public state
{
private:
    gameDataRef _data;  //chaque state recevra le pointeur sur la gameData qui
                        //donne accès au stateMachine, au RenderWindow, au
                        //assertManager et au inputManager

    Sprite _background;
    Sprite _gameOverTitle;
    Sprite _gameOverContainer;
    Sprite _retryButton;
    Sprite _medal;

    Text _scoreText;
    Text _highScoreText;

    int _score;
    int _highScore;

public:
    gameOverState(gameDataRef data, int score);

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt) const;
};
