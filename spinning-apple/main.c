#	include	<raylib.h>
#	include	"include/config.h"

int	main(void)
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);

	SetTargetFPS(FPS_CAP);

	Texture2D	background = LoadTexture("res/wallpaper.png");
	Model	apple = LoadModel("res/apple.obj");

	Camera3D camera =
	{
		.position	= (Vector3) { 0.0f, 5.0f, 10.0f},
		.target		= (Vector3) { 0.0f, 0.0f, 0.0f},
		.up		= (Vector3) { 0.0f, 1.0f, 0.0f},
		.fovy		= 45.0f,
		.projection	= CAMERA_PERSPECTIVE
	};

	Rectangle	rec	= { 0.0f, 0.0f, W_WIDTH, W_HEIGHT};
	Vector3	position	= { 0.0f, 0.0f, 0.0f};
	Vector3	rotationAxis	= { 0.0f, 1.0f, 0.0f};
	Vector3	scale		= { 2.0f, 2.0f, 2.0f};
	Vector3	wiresScale	= { 2.05f, 2.05f, 2.05f};

	float	rotationAngle = 0.0f;
	float	dt = 0.0f;

	while (!WindowShouldClose())
	{
		dt = GetFrameTime();

		rotationAngle += dt * ROTATION_SPEED;
		if (rotationAngle > 360.0f) rotationAngle = 0.0f;

		BeginDrawing();

			ClearBackground(BG_COLOR);

			DrawTextureRec(background, rec, (Vector2) { 0.0f, 0.0f }, BG_COLOR);

			BeginMode3D(camera);

				DrawModelEx
				(
					apple,
					position,
					rotationAxis,
					rotationAngle,
					scale,
					BG_COLOR
				);

				DrawModelWiresEx
				(
					apple,
					position,
					rotationAxis,
					rotationAngle,
					wiresScale,
					GRAY
				);

			EndMode3D();

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadModel(apple);
	CloseWindow();
	return (0);
}
