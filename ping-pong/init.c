#	include <stddef.h>
#	include <raylib.h>
#	include	"include/config.h"
#	include "include/init.h"
#	include	"include/font/pong.h"
#	include	"include/sound/hit.h"
#	include	"include/sound/score.h"

void	LoadAssets(Assets *a)
{
	a->font = LoadFontFromMemory(".ttf", pong_ttf, pong_ttf_len, 46, NULL, 0);

	Wave	hit = LoadWaveFromMemory(".wav", hit_wav, hit_wav_len);
	a->sounds[0] = LoadSoundFromWave(hit); UnloadWave(hit);

	Wave	score = LoadWaveFromMemory(".wav", score_wav, score_wav_len);
	a->sounds[1] = LoadSoundFromWave(score); UnloadWave(score);
}

void	InitGame(Game *g)
{
	float center_y = (WINDOW_HEIGHT / 2.0f) - (PADDLE_SIZE.y / 2.0f);

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

void	CloseGame(Game *g)
{
	UnloadFont(g->assets.font);
	UnloadSound(g->assets.sounds[0]);
	UnloadSound(g->assets.sounds[1]);

	CloseAudioDevice();
	CloseWindow();
}
