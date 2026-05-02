#ifndef	INIT_H_
#	define	INIT_H_

#	include	<raylib.h>
#	include	<stdbool.h>
#	include <stdint.h>
#	include	"config.h"

typedef	struct
{
	Vector2	position;
	Vector2	velocity;
	float	alpha;
	float	lifeSpan;
	bool	active;
}	Particle;

typedef enum { LEFT, RIGHT }	Control;

typedef struct
{
	Font	fonts[1]; // One font
	Sound	sounds[2]; // Two sounds
}	Assets;

typedef struct
{
	Vector2	position;
	Vector2	size;
	float	speed;
	uint8_t	score;
}	Player;

typedef	struct
{
	Vector2	position;
	Vector2	speed;
	float	radius;
}	Ball;

typedef struct
{
	Particle particles[MAX_PARTICLES];
	Player playerOne;
	Player playerTwo;
	Ball ball;
	Assets assets;
	bool isPaused;
}	Game;

void	InitGame(Game *g);
void	LoadAssets(Assets *a);

#endif

