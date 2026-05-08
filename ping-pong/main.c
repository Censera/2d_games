#	include	<raylib.h>
#	include "include/init.h"
#	include	"include/config.h"
#	include	"include/rendering.h"
#	include	"include/logic.h"

int	main(void)
{
	Game	game = { 0 };

	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	InitAudioDevice();

	SetTargetFPS(FPS_CAP);

	LoadAssets(&game.assets);
	InitGame(&game);

	while (!WindowShouldClose())
	{
		HandleInput(&game);
		UpdateGame(&game);

		BeginDrawing();

			ClearBackground(BG_COLOR);
			DrawParticles(&game);
			Draw(&game);

		EndDrawing();
	}

	CloseGame(&game);
	return (0);
}
