/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		pipe.h
 * Description:	Le pipe est un obstacle généré automatiquement de hauteur aléatoire.
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
    list<Sprite> _scoringPipes; //position des pipes invisibles
    int _pipeSpawnYOffset;

public:
    pipe(gameDataRef data);
    void drawPipes()/*const*/;

    void spawnTopPipe();
    void spawnBottomPipe();
    void spawnScoringPipe();

    void movePipes(float dt);
    void randomisePipeOffset();

    list<Sprite>& getSprites();
    list<Sprite>& getScoringSprites();
};