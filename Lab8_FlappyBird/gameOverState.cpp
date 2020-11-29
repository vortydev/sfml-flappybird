/*
 * Author:		�tienne M�nard
 * Date:		29/11/2020
 * File:		gameState.cpp
 * Description:	D�finitions des m�thodes du gameOverState.
 */

#include "gameOverState.h"

 //le constructeur utilise les : pour initialiser _data avant m�me l�ex�cution du contenu{}
gameOverState::gameOverState(gameDataRef data) : _data(data)
{

}

//load l�image du background � l�aide du assetManager ds _data et la set au Sprite
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

//fen�tre qui reste ouverte tant qu�elle n�est pas ferm�e
void gameOverState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
    }
}

//g�re le d�lai, apr�s 3 secondes, on veut afficher la prochaine fen�tre
void gameOverState::update(float dt)
{

}

//clear, dessine le background et display la fen�tre. (dt n�est pas utilis� ici)
void gameOverState::draw(float dt) const
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}