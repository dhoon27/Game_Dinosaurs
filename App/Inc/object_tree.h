#pragma once

#define TREE_MIN_COLS (28)
#define TREE_MAX_COLS (128)
#define TREE_MIN_LINES (3)
#define TREE_MAX_LINES (23)
#define MAX_TREE_CNT (20)

// char tree_image[3][5] = {
//     {'#'},
//     {'#','#','#'},
//     {'#','#','#','#','#'},
// };

typedef struct _TREE{
    int type;
    int h, w;
    int hitbox[5][2];
}TREE;

TREE tree[MAX_TREE_CNT];

int check_tree(int, int);
void *game_tree(void*);
void *start_tree(void*);
int random_make_tree(int);
void generate_tree(int);
void move_tree(int);