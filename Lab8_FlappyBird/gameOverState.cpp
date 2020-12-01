/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		gameState.cpp
 * Description:	Définitions des méthodes du gameOverState.
 */

#include "gameOverState.h"

 //le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
gameOverState::gameOverState(gameDataRef data, int score) : _data(data), _score(score)
{
    _highScore = 0;
}

//load l’image du background à l’aide du assetManager ds _data et la set au Sprite
void gameOverState::init()
{
    float centerWindowX = _data->window.getSize().x / 2;
    float centerWindowY = _data->window.getSize().y / 2;

    // load bg
    _data->assets.loadTexture("game over state background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.getTexture("game over state background"));

    // load container
    _data->assets.loadTexture("game over state container", GAME_OVER_BODY_FILEPATH);
    _gameOverContainer.setTexture(_data->assets.getTexture("game over state container"));
    _gameOverContainer.setPosition(centerWindowX - _gameOverContainer.getGlobalBounds().width / 2, centerWindowY - _gameOverContainer.getGlobalBounds().height / 2);

    // load title
    _data->assets.loadTexture("game over state title", GAME_OVER_TITLE_FILEPATH);
    _gameOverTitle.setTexture(_data->assets.getTexture("game over state title"));
    _gameOverTitle.setPosition(centerWindowX - _gameOverTitle.getGlobalBounds().width / 2, centerWindowY - _gameOverContainer.getGlobalBounds().height);

    // load retry button
    _data->assets.loadTexture("retry button", PLAY_BUTTON_FILEPATH);
    _retryButton.setTexture(_data->assets.getTexture("retry button"));
    _retryButton.setPosition(centerWindowX - _retryButton.getGlobalBounds().width / 2, _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height * 0.2);

    //load highscore
    ifstream highScoreFile(HIGHSCORE_FILEPATH);
    if (highScoreFile && !highScoreFile.eof()) {
        highScoreFile >> _highScore;
        highScoreFile.close();
    }
    if (_score > _highScore) {
        _highScore = _score;

        ofstream highScoreFile(HIGHSCORE_FILEPATH);
        highScoreFile << _highScore;
        highScoreFile.close();
    }

    // load scoreText
    _scoreText.setFont(_data->assets.getFont("flappy font"));
    _scoreText.setString(to_string(_score));
    _scoreText.setCharacterSize(56);
    _scoreText.setFillColor(Color::White);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);

    // load highscoreText
    _highScoreText.setFont(_data->assets.getFont("flappy font"));
    _highScoreText.setString(to_string(_highScore));
    _highScoreText.setCharacterSize(56);
    _highScoreText.setFillColor(Color::White);
    _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
    _highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);

    // load medal
    _data->assets.loadTexture("bronze medal", BRONZE_MEDAL_FILEPATH);
    _data->assets.loadTexture("silver medal", SILVER_MEDAL_FILEPATH);
    _data->assets.loadTexture("gold medal", GOLD_MEDAL_FILEPATH);
    _data->assets.loadTexture("platinum medal", PLATINUM_MEDAL_FILEPATH);

    _medal.setPosition(175, 465);

    if (_score >= PLATINUM_MEDAL_SCORE)
        _medal.setTexture(_data->assets.getTexture("platinum medal"));
    else if (_score >= GOLD_MEDAL_SCORE)
        _medal.setTexture(_data->assets.getTexture("gold medal"));
    else if (_score >= SILVER_MEDAL_SCORE)
        _medal.setTexture(_data->assets.getTexture("silver medal"));
    else if (_score >= BRONZE_MEDAL_SCORE)
        _medal.setTexture(_data->assets.getTexture("bronze medal"));
}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameOverState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
        else if (_data->input.isSpriteClicked(_retryButton, Mouse::Left, _data->window)) {
            //create the new stage main screen
            _data->machine.addState(stateRef(new gameState(_data)), true);
            cout << "go to game screen" << endl;
        }
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
    _data->window.draw(_gameOverContainer);
    _data->window.draw(_gameOverTitle);
    _data->window.draw(_retryButton);
    _data->window.draw(_medal);

    _data->window.draw(_scoreText);
    _data->window.draw(_highScoreText);

    _data->window.display();
}