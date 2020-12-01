/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		collision.h
 * Description:	Permet de checker les collisions de sprites en faisant l'intersection de leur rectangles.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;

class collision
{
public:
    bool checkSpriteCollision(Sprite sprite1, Sprite sprite2)const;
    bool checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const;
};