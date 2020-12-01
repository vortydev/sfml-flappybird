/*
 * Author:		�tienne M�nard
 * Date:		26/11/2020
 * File:		DEFINITIONS.hpp
 * Description:	Fichier contenant les constantes n�cessaires pour le projet. R�utilisable pour des projets ult�rieurs.
 */

#pragma once
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

// splashState
#define LOGO_STATE_SHOW_TIME 3.0
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

// mainMenuState
#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

// gameState
enum gameStates {
    ready,
    playing,
    gameOver
};

// gameOverState
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define HIGHSCORE_FILEPATH "Resources/highScore.txt"

#define TIME_BEFORE_GAME_OVER 1.5f

// pipe
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f // normal: 3.0
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

// flash
#define FLASH_SPEED 1500.0f

// medals
#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

// sounds
#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wave"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wave"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wave"