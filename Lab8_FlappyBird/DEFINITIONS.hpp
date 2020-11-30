/*
 * Author:		Étienne Ménard
 * Date:		26/11/2020
 * File:		DEFINITIONS.hpp
 * Description:	Fichier contenant les constantes nécessaires pour le projet. Réutilisable pour des projets ultérieurs.
 */

#pragma once
// screen
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

// splashState
#define LOGO_STATE_SHOW_TIME 3.0
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

// mainMenuState
#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

// gameOverState
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

// pipe
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f
#define MAX_PIPE_HEIGHT 261

// land
#define LAND_FILEPATH "Resources/res/Land.png"

// birb
#define BIRD_FRAME_1_FILEPATH "Resources/res/BIRD-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/BIRD-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/BIRD-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/BIRD-04.png"
#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f