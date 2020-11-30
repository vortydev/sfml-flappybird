/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		bird.cpp
 * Description:	D�finition des m�thodes de bird.
 */

#include "bird.h"

bird::bird(gameDataRef data) : _data(data)
{
    _birdSprite.setTexture(_data->assets.getTexture("bird frame1"));

    // push les frames d'animations du bird dans le vecteur
    _animationFrames.push_back(_data->assets.getTexture("bird frame1"));
    _animationFrames.push_back(_data->assets.getTexture("bird frame2"));
    _animationFrames.push_back(_data->assets.getTexture("bird frame3"));
    _animationFrames.push_back(_data->assets.getTexture("bird frame4"));

    _animationIterator = 0;

    _birdState = BIRD_STATE_FLYING;

    _birdSprite.setPosition((_data->window.getSize().x / 4) - _birdSprite.getGlobalBounds().width / 2,
        (_data->window.getSize().y / 2) - _birdSprite.getGlobalBounds().height / 2);

    _rotation = 0;
    _birdSprite.setOrigin(Vector2f(_birdSprite.getGlobalBounds().width / 2,
        _birdSprite.getGlobalBounds().height / 2));
}

void bird::draw() const
{
    _data->window.draw(_birdSprite);
}

void bird::animate(float dt)
{
    //si on veut que l�animation dure .4 seconde et qu�on a 4 images, chaque image
    //durera .1 seconde. D�o� la division par la taille du vecteur de frame
    if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
    {
        _animationIterator++;
        if (_animationIterator >= _animationFrames.size()) //apr�s 4 images, on revient � 0
            _animationIterator = 0;

        _birdSprite.setTexture(_animationFrames.at(_animationIterator));

        _clock.restart();
    }
}

void bird::update(float dt)
{
    if (_birdState == BIRD_STATE_FALLING)       //si on tombe, on move le sprite
    {                                           //par en bas � l�aide de la gravit�
        _birdSprite.move(0, GRAVITY * dt);

        _rotation += ROTATION_SPEED * dt;   //modifie la rotation avec le dt re�u
        if (_rotation > 25.0f)              //sans le laisser d�passer l�angle 25 degr�
            _rotation = 25.0f;

        _birdSprite.setRotation(_rotation); //applique la rotation au sprite du bird
    }
    else if (_birdState == BIRD_STATE_FLYING)   //si on vole, on move le sprite
    {                                           //par en haut � l�aide du flying speed
        _birdSprite.move(0, -FLYING_SPEED * dt);

        _rotation -= ROTATION_SPEED * dt;
        if (_rotation < -25.0f)
            _rotation = -25.0f;

        _birdSprite.setRotation(_rotation);
    }

    //� l�aide de la 2e clock, on change le state du bird apr�s le temps de vol � fall
    if (_mouvementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
    {
        _birdState = BIRD_STATE_FALLING;
        _mouvementClock.restart();
    }
}

void bird::tap()
{
    _mouvementClock.restart(); //si on click, on call tap qui reset la clock
    _birdState = BIRD_STATE_FLYING; //et met le state � FLYING
}