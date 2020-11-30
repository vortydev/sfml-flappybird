/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		land.cpp
 * Description:	D�finitions des m�thodes de land.
 */

#include "land.h"

land::land(gameDataRef data) : _data(data)
{
    Sprite sprite1(_data->assets.getTexture("land"));
    Sprite sprite2(_data->assets.getTexture("land"));

    //positionne � 0 en x et en bas de l��cran en y
    sprite1.setPosition(0, _data->window.getSize().y - sprite1.getGlobalBounds().height);

    //positionne � la fin du premier land en x et en bas de l��cran en y
    sprite2.setPosition(sprite1.getGlobalBounds().width,
        _data->window.getSize().y - sprite1.getGlobalBounds().height);

    _landSprites.push_back(sprite1);
    _landSprites.push_back(sprite2);
}

void land::drawLand() /*const*/
{
    for (int i = 0; i < _landSprites.size(); i++) 
    {
        _data->window.draw(_landSprites.at(i));
    }
}

void land::moveLand(float dt)
{
    for (int i = 0; i < _landSprites.size(); i++)
    {
        float movement = PIPE_MOVEMENT_SPEED * dt;
        _landSprites.at(i).move(-movement, 0); //on se d�place vers la gauche -x
        if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
        {
            //repositionne � droite de l��cran
            Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
            _landSprites.at(i).setPosition(position);
        }
    }
}   