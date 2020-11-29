/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		pipe.h
 * Description:	Le pipe est un obstacle généré automatiquement de hauteur aléatoire que le joueur doit éviter afin de progresser et gagner des points.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <list>
#include "game.h"

using namespace sf;

class pipe
{
private:
    gameDataRef _data;
    list<Sprite> _pipeSprites;

public:
    pipe(gameDataRef data);
    void drawPipes()/*const*/;
};

