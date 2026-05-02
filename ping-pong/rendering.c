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
	g->assets.fonts[0],
	info_score,
	(Vector2){(WINDOW_WIDTH - (float)MeasureText(info_score, 44))/2, MARGIN},
	44,	// font size
	1,	// font spacing
	FG_COLOR
	);

	if (g->isPaused)
	{
		DrawTextEx
		(
			g->assets.fonts[0],
			"||",
			(Vector2){ MARGIN, MARGIN},
			32,	// font size
			1,	// font spacing
			FG_COLOR
		);
	}
}


