#ifndef LOGIC_H_
#	define LOGIC_H_

#	include	"init.h"

void	UpdateGame(Game *g);

void	PauseGame(Game *g);
void	ResetGame(Game *g);

void	GameState(Game *g);

void	UpdatePlayer(Control ctrl, Player *p, float	speed, float dt);
void	UpdateBall(Game *g, float dt);
void	UpdateCollision(Game *g, Player *p);
void	UpdateParticles(Particle *p, uint8_t count, float dt);

void	CreateBurst(Particle *p, uint8_t count, Vector2 position);
void	CheckScore(Game *g);

#endif
