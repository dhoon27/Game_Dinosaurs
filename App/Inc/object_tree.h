#pragma once

typedef struct _TREE{
    int type;
    int h, w;
    int hitbox[5][2];
}TREE;

TREE tree;

void init_dino(void);
void jump_dino(void);
