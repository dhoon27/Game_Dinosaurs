#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "console_control.h"
#include "object_tree.h"
#include "print_image.h"

int check_tree(int h, int w)
{
    if (h > TREE_MIN_LINES && h < TREE_MAX_LINES && w > TREE_MIN_COLS && w < TREE_MAX_COLS)
        return 1;
    return 0;
}

void generate_tree(int idx)
{
    tree[idx].type = 1;
    tree[idx].h = TREE_MAX_LINES - 5;
    tree[idx].w = TREE_MAX_COLS;

    tree[idx].hitbox[0][0] = TREE_MAX_COLS + 2;
    tree[idx].hitbox[0][1] = TREE_MAX_COLS + 2;

    tree[idx].hitbox[1][0] = TREE_MAX_COLS + 1;
    tree[idx].hitbox[1][1] = TREE_MAX_COLS + 3;

    tree[idx].hitbox[2][0] = TREE_MAX_COLS;
    tree[idx].hitbox[2][1] = TREE_MAX_COLS + 4;

    tree[idx].hitbox[3][0] = TREE_MAX_COLS + 2;
    tree[idx].hitbox[3][1] = TREE_MAX_COLS + 2;

    tree[idx].hitbox[4][0] = TREE_MAX_COLS + 2;
    tree[idx].hitbox[4][1] = TREE_MAX_COLS + 2;
}
int random_make_tree(int level)
{
    //seed를 현재 시간으로 --> 실행 마다 seed 달라짐
    srand((unsigned int)time(NULL));
    int random = (rand() % (MAX_TREE_CNT - level+1));
    if(random <= 1){
        generate_tree(tidx);
        return 1;
    }
    return 0;
}
void *start_tree(void* param)
{
    int idx = *((int *)(param));
    while (tree[idx].w + 4 > TREE_MIN_COLS){
        print_tree(tree[idx].h, tree[idx].w);
        usleep(70000);
        delete_tree(tree[idx].h, tree[idx].w);
        tree[idx].w--;
    }
    return param;
}
void *game_tree(void* param)
{
    pthread_t pthread_cnt[MAX_TREE_CNT];
    while(1){
        if (tidx >= MAX_TREE_CNT)
            break;
        if(random_make_tree(tidx)){
            pthread_create(&pthread_cnt[tidx], NULL, start_tree, &tidx);
            tidx++;
        }
        // usleep(70000);
    }
    
    return param;
}