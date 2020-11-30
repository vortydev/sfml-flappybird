/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		pipe.cpp
 * Description:	Définitions des méthodes de pipe.
 */

#include "pipe.h"

pipe::pipe(gameDataRef data) : _data(data)
{
    _pipeSpawnYOffset = 0;
}

void pipe::drawPipes() /*const*/
{
    for (list<Sprite>::iterator it = _pipeSprites.begin(); it != _pipeSprites.end(); it++)
        _data->window.draw(*it);
}

void pipe::spawnTopPipe()
{
    Sprite sprite(_data->assets.getTexture("pipe up"));
    sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
    _pipeSprites.push_back(sprite);
}

void pipe::spawnBottomPipe()
{
    Sprite sprite(_data->assets.getTexture("pipe down"));
    sprite.setPosition(_data->window.getSize().x, 0 - _pipeSpawnYOffset);
    _pipeSprites.push_back(sprite);
}

void pipe::movePipes(float dt)
{
    list<Sprite>::iterator it = _pipeSprites.begin();
    while (it != _pipeSprites.end()) {
        //si la position des pipes sont inférieurs à 0 auquel on soustrait la largeur d’un pipe
        if (it->getPosition().x < 0 - it->getGlobalBounds().width)
        {
            it = _pipeSprites.erase(it);
        }
        else {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            it->move(-movement, 0); //on se déplace vers la gauche -x
            it++;
        }
    }
}

void pipe::randomisePipeOffset()
{
    _pipeSpawnYOffset = rand() % (MAX_PIPE_HEIGHT + 1);
}
