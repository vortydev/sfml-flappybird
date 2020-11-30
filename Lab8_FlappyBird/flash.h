/*
 * Author:		Étienne Ménard
 * Date:		30/11/2020
 * File:		flash.h
 * Description:	Bref flash de blanc quand le bird hit un obstacle.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;

class flash
{
private:
    gameDataRef _data;
    RectangleShape _shape;
    bool _flashOn;

public:
    flash(gameDataRef data);
    void show(float dt);
    void draw();
};