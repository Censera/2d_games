#	include	<raylib.h>
#	include "include/init.h"
#	include	"include/config.h"
#	include	"include/rendering.h"
#	include	"include/logic.h"

int	main(void)
{
	Game game = { 0 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	InitAudioDevice();
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetTargetFPS(FPS_CAP);

	LoadAssets(&game.assets);
	InitGame(&game);

	while (!WindowShouldClose())
	{
		GameState(&game);
		UpdateGame(&game);

		BeginDrawing();
			ClearBackground(BG_COLOR);
			DrawParticles(&game);
			Draw(&game);
		EndDrawing();
	}

	UnloadFont(game.assets.fonts[0]);
	UnloadSound(game.assets.sounds[0]);
	UnloadSound(game.assets.sounds[1]);
	CloseAudioDevice();
	CloseWindow();
	return (0);
}
