/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		gameState.cpp
 * Description:	Définitions des méthodes du gameState.
 */

#include "gameState.h"

 //le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
gameState::gameState(gameDataRef data) : _data(data)
{
    _pipe = nullptr;
    _land = nullptr;
}

gameState::~gameState()
{
    delete _pipe;
}

//load l’image du background à l’aide du assetManager ds _data et la set au Sprite
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

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
    }
}

//gère le délai, après 3 secondes, on veut afficher la prochaine fenêtre
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

//clear, dessine le background et display la fenêtre. (dt n’est pas utilisé ici)
void gameState::draw(float dt) const
{
    _data->window.clear();
    _data->window.draw(_background);
    _pipe->drawPipes();
    _land->drawLand();
    _data->window.display();
}