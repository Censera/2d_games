#	include	<math.h>
#	include	<raylib.h>
#	include	<raymath.h>
#	include	"include/player.h"
#	include	"include/world.h"
#	include "include/config.h"

int	main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	Player	player = { 0 };

	Map	map = { 0 };
	InitMapTexture(&map);

	Camera2D camera = { 0 };
	camera.zoom = 1.f;

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		if (IsKeyDown(KEY_RIGHT)) camera.target.x += 300 * dt;
		if (IsKeyDown(KEY_LEFT)) camera.target.x -= 300 * dt;
		if (IsKeyDown(KEY_UP)) camera.target.y -= 300 * dt;
		if (IsKeyDown(KEY_DOWN)) camera.target.y += 300 * dt;

		BeginDrawing();

			ClearBackground(SKYBLUE);

			BeginMode2D(camera);

				RenderMap(&map, &camera);

			EndMode2D();

			DrawFPS(20, 20);

		EndDrawing();
	}

	UnloadTexture(map.sprite);
	CloseWindow();
	return (0);
}
