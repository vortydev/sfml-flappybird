/*
 * Author:		�tienne M�nard
 * Date:		30/11/2020
 * File:		hud.h
 * Description:	Display sur l'�cran le score du joueur.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;

class hud
{
private:
    gameDataRef _data;
    Text _scoreText;

public:
    hud(gameDataRef data);
    void updateScore(int score);
    void draw()const;
};