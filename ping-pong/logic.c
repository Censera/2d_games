#	include	<raylib.h>
#	include	<raymath.h>
#	include	"include/logic.h"
#	include	"include/config.h"
#	include	"include/init.h"
#	include	"include/rendering.h"

void	UpdatePlayer(Control ctrl, Player *p, float dt)
{
	if (ctrl == LEFT)
	{
		if (IsKeyDown(KEY_W)) p->position.y -= p->speed * dt;
		if (IsKeyDown(KEY_S)) p->position.y += p->speed * dt;
	}

	if (ctrl == RIGHT)
	{
		if (IsKeyDown(KEY_UP)) p->position.y -= p->speed * dt;
		if (IsKeyDown(KEY_DOWN))p->position.y += p->speed * dt;
	}

	float btmBound = WINDOW_HEIGHT - (p->size.y +MARGIN);
	p->position.y = Clamp(p->position.y, MARGIN, btmBound);
}

void	UpdateBall(Game *g, float dt)
{
	if (g->ball.position.y <= g->ball.radius
		|| (g->ball.position.y + g->ball.radius) >= WINDOW_HEIGHT)
	{
		g->ball.speed.y *= -1;
		PlaySound(g->assets.sounds[0]);
	}

	g->ball.position.x += g->ball.speed.x * dt;
	g->ball.position.y += g->ball.speed.y * dt;
}

void	PauseGame(Game *g)
{
		g->isPaused = !g->isPaused;
}

void	ResetGame(Game *g)
{
		InitGame(g);
}

void	HandleInput(Game *g)
{
	if (IsKeyPressed(KEY_P)
	|| IsKeyPressed(KEY_SPACE)
	|| IsKeyPressed(KEY_ENTER))
		PauseGame(g);

	if (IsKeyPressed(KEY_R))
		ResetGame(g);
}

void	UpdateCollision(Game *g, Player *p)
{

	Rectangle	paddle = (Rectangle)
	{
		p->position.x,
		p->position.y -PADDLE_HITBOX_PADDING,
		p->size.x,
		p->size.y +PADDLE_HITBOX_PADDING,
	};

	if (CheckCollisionCircleRec(g->ball.position, g->ball.radius, paddle))
	{
		g->ball.speed.x *= -1;

		float	paddleCenterY = p->position.y +(p->size.y /2);
		float	distanceFromCenter = g->ball.position.y -paddleCenterY;

		float	normDistance = distanceFromCenter / (p->size.y /2);

		float	bounceIntensity = 400.0f;
		float	randomness = (float)GetRandomValue(-20, 20);

		g->ball.speed.y = ((normDistance * bounceIntensity) +randomness);

		if (g->ball.speed.x > 0) g->ball.position.x = p->position.x +p->size.x +g->ball.radius;
		else g->ball.position.x = p->position.x - g->ball.radius;

		PlaySound(g->assets.sounds[0]);

		CreateBurst(g->particles, 5, g->ball.position);
	}
}

void	ResetBall(Game *g)
{
		g->ball.position = (Vector2){ WINDOW_WIDTH/2, WINDOW_HEIGHT/2 };
		g->ball.speed = (Vector2)
		{
			GetRandomValue(0, 1) ? BALL_SPEED : -BALL_SPEED,
			(float)GetRandomValue(-100, 100)
		};
		g->isPaused = true;
}

void	CheckScore(Game *g)
{
	if (g->ball.position.x <= -g->ball.radius*2)
	{
		g->playerTwo.score++;
		CreateBurst
		(
			g->particles,
			100,
			(Vector2)
			{
				g->ball.position.x + g->ball.radius*2,
				g->ball.position.y
			}
		);
		PlaySound(g->assets.sounds[1]);

		ResetBall(g);
	}
	else if (g->ball.position.x >= WINDOW_WIDTH + g->ball.radius*2)
	{
		g->playerOne.score++;
		CreateBurst
		(
			g->particles,
			100,
			(Vector2)
			{
				g->ball.position.x - g->ball.radius*2,
				g->ball.position.y
			}
		);
		PlaySound(g->assets.sounds[1]);

		ResetBall(g);
	}
}

void	UpdateGame(Game *g)
{
	float	dt = GetFrameTime();

	UpdateParticles(g->particles, MAX_PARTICLES, dt);
	CheckScore(g);

	if (!g->isPaused)
	{
		UpdatePlayer(LEFT, &g->playerOne, dt);
		UpdatePlayer(RIGHT, &g->playerTwo, dt);

		UpdateBall(g, dt);
		UpdateCollision(g, &g->playerOne);
		UpdateCollision(g, &g->playerTwo);
	}
}

void	UpdateParticles(Particle *p, uint8_t count, float dt)
{
	for (uint8_t i = 0; i < count; i++)
	{
		if (p[i].active)
		{
			p[i].position.x += p[i].velocity.x * dt;
			p[i].position.y += p[i].velocity.y * dt;
			p[i].alpha -= 2.0f * dt;

			if (p[i].alpha <= 0) p[i].active = false;
		}
	}
}

void	CreateBurst(Particle *p, uint8_t count, Vector2 position)
{
	uint8_t spawned = 0;
	for (uint8_t i = 0; i < MAX_PARTICLES && spawned < count; i++)
	{
		if (!p[i].active)
		{
			p[i].active = true;
			p[i].position = position;
			p[i].alpha = 1.0f;

			p[i].velocity.x = (float)GetRandomValue(-200, 200);
			p[i].velocity.y = (float)GetRandomValue(-200, 200);
			spawned++;
		}
	}
}
