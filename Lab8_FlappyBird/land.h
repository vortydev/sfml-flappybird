/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		land.h
 * Description:	Objet du sol qui déroulera devant les pipes.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <vector>
#include "game.h"

using namespace sf;

class land
{
private:
    gameDataRef _data;
    vector<Sprite> _landSprites;

public:
    land(gameDataRef data);
    void drawLand()const;
    void moveLand(float dt);

    const vector<Sprite>& getSprites()const;
};