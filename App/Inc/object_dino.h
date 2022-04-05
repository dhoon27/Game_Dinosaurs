#pragma once

#define DINO_MIN_H (12)
#define DINO_MIN_W (38)

typedef struct _DINO{
    int h,w;
    int hitbox[11][2];
}DINO;

DINO dino;

void init_dino(void);
void jump_dino(void);
void game_dino(void);