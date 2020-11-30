/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		gameState.cpp
 * Description:	D�finitions des m�thodes du gameState.
 */

#include "gameState.h"

 //le constructeur utilise les : pour initialiser _data avant m�me l�ex�cution du contenu{}
gameState::gameState(gameDataRef data) : _data(data)
{
    _pipe = nullptr;
    _land = nullptr;
}

gameState::~gameState()
{
    delete _pipe;
}

//load l�image du background � l�aide du assetManager ds _data et la set au Sprite
void gameState::init()
{
    // load bg sprite
    _data->assets.loadTexture("game state background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.getTexture("game state background"));

    // load pipe
    _data->assets.loadTexture("pipe up", PIPE_UP_FILEPATH);
    _data->assets.loadTexture("pipe down", PIPE_DOWN_FILEPATH);
    _pipe = new pipe(_data);

    // load land
    _data->assets.loadTexture("land", LAND_FILEPATH);
    _land = new land(_data);
}

//fen�tre qui reste ouverte tant qu�elle n�est pas ferm�e
void gameState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
    }
}

//g�re le d�lai, apr�s 3 secondes, on veut afficher la prochaine fen�tre
void gameState::update(float dt)
{
    _pipe->movePipes(dt);
    _land->moveLand(dt);

    if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
    {
        _pipe->randomisePipeOffset();   
        _pipe->spawnBottomPipe();
        _pipe->spawnTopPipe();
        _clock.restart();
    }
}

//clear, dessine le background et display la fen�tre. (dt n�est pas utilis� ici)
void gameState::draw(float dt) const
{
    _data->window.clear();
    _data->window.draw(_background);
    _pipe->drawPipes();
    _land->drawLand();
    _data->window.display();
}