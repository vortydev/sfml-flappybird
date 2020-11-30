/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		bird.h
 * Description:	Personnage jouable. Le but est de le naviguer
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;

class bird
{
private:
    gameDataRef _data;
    Sprite _birdSprite;     //on n’a qu’un Sprite qui sera modifié selon l’animation

    Clock _clock;
    vector<Texture> _animationFrames;
    int _animationIterator;

    Clock _mouvementClock;  //une autre clock pour le temps de mouvement
    int _birdState;         //le bird state

    float _rotation;

public:
    bird(gameDataRef data);

    void draw()const;
    void animate(float dt);

    void update(float dt);
    void tap();
};