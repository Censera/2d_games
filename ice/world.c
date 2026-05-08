#	define	STB_PERLIN_IMPLEMENTATION
#	include	<math.h>
#	include	<raylib.h>
#	include	"include/world.h"
#	include	"include/perlin.h"
#	include	"include/config.h"

void	InitMapTexture(Map *m)
{
	m->sprite = LoadTexture("res/sprite.png");
}

#include <math.h>

void	RenderMap(Map *m, Camera2D *c)
{
	for (float x = -TILE_SIZE; x < TILE_SIZE * 16; x +=
TILE_SIZE)
	{
		for (float y = -TILE_SIZE; y < TILE_SIZE * 11 ; y +=
TILE_SIZE)
		{
			Rectangle	dst = (Rectangle)
			{
				x,
				y,
				TILE_SIZE,
				TILE_SIZE
			};

			DrawTexturePro
			(
				m->sprite,
    				(Rectangle){16,0,16,16,},
				dst,
				(Vector2)
				{
					c->target.x,
					c->target.y
				},
				0,
				WHITE
			);
		}
	}
}
