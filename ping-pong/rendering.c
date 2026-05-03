#	include	<raylib.h>
#	include	"include/init.h"
#	include	"include/config.h"
#	include "include/rendering.h"

void	DrawParticles(Game *g)
{
	for (uint8_t i = 0; i < MAX_PARTICLES; i++)
	{
		if (g->particles[i].active)
		{
			DrawRectangleV
			(
				g->particles[i].position,
				(Vector2){ 4, 4 },
				Fade(FG_COLOR, g->particles[i].alpha)
			);
		}
	}
}

void	Draw(Game *g)
{
	const char	*info_score = TextFormat
	(
		"%d | %d",
		g->playerOne.score,
		g->playerTwo.score
	);

	DrawRectangleV(g->playerOne.position, g->playerOne.size, FG_COLOR);
	DrawRectangleV(g->playerTwo.position, g->playerTwo.size, FG_COLOR);
	DrawCircleV(g->ball.position, g->ball.radius, FG_COLOR);

	DrawTextEx(
	g->assets.font,
	info_score,
	(Vector2)
	{
		(
			WINDOW_WIDTH
			-(float)MeasureTextEx
			(
				g->assets.font,
				info_score,
				44,
				1
			).x
		)/2,
		MARGIN
	},
	44,	// font size
	1,	// font spacing
	FG_COLOR
	);

	if (g->isPaused)
	{
		DrawTextEx
		(
			g->assets.font,
			"||",
			(Vector2){ MARGIN, MARGIN},
			32,	// font size
			1,	// font spacing
			FG_COLOR
		);
	}
}


