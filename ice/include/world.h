#ifndef	WRLD_H_
#	define	WRLD_H_

#	include	<stdint.h>
#	include	<raylib.h>

typedef	struct
{
	Texture2D	sprite;
	Vector2	start;
	uint8_t	tilesize;
} Map;

void	InitMapTexture(Map *m);
void	RenderMap(Map *m, Camera2D *c);
#endif
