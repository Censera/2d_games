#	include <stdio.h>
#	include <raylib.h>
#	include	"include/config.h"
#	include "include/init.h"

void	LoadAssets(Assets *a)
{
	a->fonts[0] = LoadFontEx("font/Pong.ttf", 68, NULL, 0);
	a->sounds[0] = LoadSound("sound/BallBounce.wav");
	a->sounds[1] = LoadSound("sound/Score.wav");
}

void	InitGame(Game *g)
{
	float center_y = (WINDOW_HEIGHT /2.0f) - (PADDLE_SIZE.y /2.0f);

	g->playerOne = (Player)
	{
		{ MARGIN, center_y },
		PADDLE_SIZE,
		PADDLE_SPEED,
		0
	};

	g->playerTwo = (Player)
	{
		{
			WINDOW_WIDTH - (PADDLE_SIZE.x + MARGIN),
			center_y
		},
		PADDLE_SIZE,
		PADDLE_SPEED,
		0
	};

	g->ball = (Ball)
	{
		{
			WINDOW_WIDTH /2,
			WINDOW_HEIGHT /2
		},
		{
			GetRandomValue(0, 1) ? BALL_SPEED : -BALL_SPEED,
			(float)GetRandomValue(-100, 100)
		},
		BALL_RADIUS
	};

	g->isPaused = true;
}
