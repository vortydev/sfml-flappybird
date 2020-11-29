/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		pipe.cpp
 * Description:	Définitions des méthodes de pipe.
 */

#include "pipe.h"

pipe::pipe(gameDataRef data) : _data(data)
{

}

void pipe::drawPipes() /*const*/
{
    for (list<Sprite>::iterator it = _pipeSprites.begin(); it != _pipeSprites.end(); it++)
        _data->window.draw(*it);
}
