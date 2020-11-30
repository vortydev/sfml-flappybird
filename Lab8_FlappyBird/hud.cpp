/*
 * Author:		Étienne Ménard
 * Date:		30/11/2020
 * File:		hud.cpp
 * Description:	Définitions des méthodes de hud.
 */

#include "hud.h"

hud::hud(gameDataRef data) :_data(data)
{
    _scoreText.setFont(_data->assets.getFont("flappy font"));
    _scoreText.setString("0");
    _scoreText.setCharacterSize(128);
    _scoreText.setFillColor(Color::White);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

    //l’image du texte sera centré sur l’écran grâce au point d’origine au milieu de l’image
    _scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 5);
}

void hud::updateScore(int score)
{
    _scoreText.setString(to_string(score));
}

void hud::draw() const
{
    _data->window.draw(_scoreText);
}