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
    _bird = nullptr;
    _flash = nullptr;
    _hud = nullptr;

    _score = 0;

    _gameState = gameStates::ready;
}

gameState::~gameState()
{
    delete _pipe;
    delete _land;
    delete _bird;
    delete _flash;
    delete _hud;
}

//load l’image du background à l’aide du assetManager ds _data et la set au Sprite
void gameState::init()
{
    // set le game state
    _gameState = gameStates::ready;

    // load HUD
    _score = 0;
    _data->assets.loadFont("flappy font", FLAPPY_FONT_FILEPATH);
    _hud = new hud(_data);
    _hud->updateScore(_score);

    // load bg sprite
    _data->assets.loadTexture("game state background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.getTexture("game state background"));

    // load pipe
    _data->assets.loadTexture("pipe up", PIPE_UP_FILEPATH);
    _data->assets.loadTexture("pipe down", PIPE_DOWN_FILEPATH);
    _data->assets.loadTexture("scoring pipe", SCORING_PIPE_FILEPATH);
    _pipe = new pipe(_data);

    // load land
    _data->assets.loadTexture("land", LAND_FILEPATH);
    _land = new land(_data);

    // load bird
    _data->assets.loadTexture("bird frame1", BIRD_FRAME_1_FILEPATH);
    _data->assets.loadTexture("bird frame2", BIRD_FRAME_2_FILEPATH);
    _data->assets.loadTexture("bird frame3", BIRD_FRAME_3_FILEPATH);
    _data->assets.loadTexture("bird frame4", BIRD_FRAME_4_FILEPATH);
    _bird = new bird(_data);

    // load flash
    _flash = new flash(_data);

    if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
        cout << "erreur loading sound effect" << endl;
    }
    if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {
        cout << "erreur loading sound effect" << endl;
    }
    if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {
        cout << "erreur loading sound effect" << endl;
    }
    _hitSound.setBuffer(_hitSoundBuffer);
    _wingSound.setBuffer(_wingSoundBuffer);
    _pointSound.setBuffer(_pointSoundBuffer);
}

//fenêtre qui reste ouverte tant qu’elle n’est pas fermée
void gameState::handleInput()
{
    Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            _data->window.close();
        else if (_data->input.isSpriteClicked(_background, Mouse::Left, _data->window)) {
            
            //si ce n’est pas gameOver, on devient playing
            if (_gameState != gameStates::gameOver) {
                _gameState = gameStates::playing;
                _bird->tap();
                _wingSound.play();
            }
        }
    }
}

//gère le délai, après 3 secondes, on veut afficher la prochaine fenêtre
void gameState::update(float dt)
{
    //si ce n’est pas gameOver, on bouge le bird et le land
    if (_gameState != gameStates::gameOver) {
        _bird->animate(dt);
        _land->moveLand(dt);
    }

    //si c’est playing, on a cliqué, donc on joue. Ajoute movePipe, la clock
    //pour la création des pipes et l’update du bird. Ensuite viennent les collisions
    if (_gameState == gameStates::playing) {
        _pipe->movePipes(dt);

        if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            _pipe->randomisePipeOffset();

            _pipe->spawnBottomPipe();
            _pipe->spawnTopPipe();
            _pipe->spawnScoringPipe();

            _clock.restart();
        }

        _bird->update(dt);

        //Après le mouvement du bird, on check les collisions avec les lands
        for (int i = 0; i < _land->getSprites().size(); i++)
            if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, _land->getSprites().at(i), 1.0f)) {
                _gameState = gameStates::gameOver;
                _clock.restart();

                _hitSound.play();
            }

        //Après on check les collisions avec les pipes
        for (list<Sprite>::iterator it = _pipe->getSprites().begin(); it != _pipe->getSprites().end(); it++) {
            if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *it, 1.0f)) {
                _gameState = gameStates::gameOver;
                _clock.restart();

                _hitSound.play();
            }
        }

        // collisions avec les scorings pipes pour compter les points
        if (_gameState == gameStates::playing) {
            list<Sprite>::iterator itS = _pipe->getScoringSprites().begin();
            while (itS != _pipe->getScoringSprites().end()) {

                if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *itS, 1.0f)) {
                    _score++;
                    _hud->updateScore(_score);

                    itS = _pipe->getScoringSprites().erase(itS);

                    _pointSound.play();
                }
                else
                    itS++;
            }
        }
    }

    if (_gameState == gameStates::gameOver) {
        _flash->show(dt);

        if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
        {
            _data->machine.addState(stateRef(new gameOverState(_data, _score)), true);
            cout << "go to game over screen" << endl;
            cout << "score: " << _score << endl;
        }
    }
}

//clear, dessine le background et display la fenêtre. (dt n’est pas utilisé ici)
void gameState::draw(float dt) const
{
    _data->window.clear();

    _data->window.draw(_background);
    _pipe->drawPipes();
    _land->drawLand();
    _bird->draw();
    _flash->draw();
    _hud->draw();

    _data->window.display();
}