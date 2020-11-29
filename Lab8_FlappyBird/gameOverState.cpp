/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		gameState.cpp
 * Description:	Définitions des méthodes du gameOverState.
 */

#include "gameOverState.h"

 //le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
gameOverState::gameOverState(gameDataRef data) : _data(data)
{

}

//load l’image du background à l’aide du assetManager ds _data et la set au Sprite
void gameOverState::init()
{
    // load bg
    _data->assets.loadTexture("game over state background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.getTexture("game over state background"));

    // load title
    _data->assets.loadTexture("game over state title", GAME_OVER_TITLE_FILEPATH);
    _title.setTexture(_data->assets.getTexture("game over state title"));
    _title.setPosition(SCREEN_WIDTH / 2 - _title.getGlobalBounds().width / 2, _title.getGlobalBounds().height / 2); // temp
}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameOverState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
    }
}

//gère le délai, après 3 secondes, on veut afficher la prochaine fenêtre
void gameOverState::update(float dt)
{

}

//clear, dessine le background et display la fenêtre. (dt n’est pas utilisé ici)
void gameOverState::draw(float dt) const
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}