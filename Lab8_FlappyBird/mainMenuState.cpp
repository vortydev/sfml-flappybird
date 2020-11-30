/*
 * Author:		�tienne M�nard
 * Date:		28/11/2020
 * File:		mainMenuState.cpp
 * Description:	D�finitions des m�thodes du mainMenuState.
 */

#include "mainMenuState.h"

 //le constructeur utilise les : pour initialiser _data avant m�me l�ex�cution du contenu{}
mainMenuState::mainMenuState(gameDataRef data) : _data(data)
{

}

//load l�image du background � l�aide du assetManager ds _data et la set au Sprite
void mainMenuState::init()
{
    // load bg
    _data->assets.loadTexture("menu state background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.getTexture("menu state background"));

    // load title
    _data->assets.loadTexture("menu state title", GAME_TITLE_FILEPATH);
    _title.setTexture(_data->assets.getTexture("menu state title"));
    _title.setPosition(SCREEN_WIDTH / 2 - _title.getGlobalBounds().width / 2, _title.getGlobalBounds().height / 2);

    // load play button
    _data->assets.loadTexture("menu state button", PLAY_BUTTON_FILEPATH);
    _playButton.setTexture(_data->assets.getTexture("menu state button"));
    // centre le bouton au milieu de l'�cran
    _playButton.setPosition(SCREEN_WIDTH / 2 - _playButton.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _playButton.getGlobalBounds().height / 2);
}

//fen�tre qui reste ouverte tant qu�elle n�est pas ferm�e
void mainMenuState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
        else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window)) {
            //create the new stage main screen
            _data->machine.addState(stateRef(new gameState(_data)),true);
            cout << "go to game screen" << endl;
        }
    }
}

//g�re le d�lai, apr�s 3 secondes, on veut afficher la prochaine fen�tre
void mainMenuState::update(float dt)
{

}

//clear, dessine le background et display la fen�tre. (dt n�est pas utilis� ici)
void mainMenuState::draw(float dt) const
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playButton);
    _data->window.display();
}