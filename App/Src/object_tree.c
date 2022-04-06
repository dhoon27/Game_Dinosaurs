#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "console_control.h"
#include "object_tree.h"
#include "print_image.h"

extern int GAME_FLAG;
extern pthread_mutex_t mutex_lock;
int tidx;
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

    tree[idx].hitbox[0][0] = 2;
    tree[idx].hitbox[0][1] = 2;

    tree[idx].hitbox[1][0] = 1;
    tree[idx].hitbox[1][1] = 3;

    tree[idx].hitbox[2][0] = 0;
    tree[idx].hitbox[2][1] = 4;

    tree[idx].hitbox[3][0] = 2;
    tree[idx].hitbox[3][1] = 2;

    tree[idx].hitbox[4][0] = 2;
    tree[idx].hitbox[4][1] = 2;
}
int random_make_tree(int level)
{
    //seed를 현재 시간으로 --> 실행 마다 seed 달라짐
    
    // pthread_mutex_lock(&mutex_lock);
    srand((unsigned int)time(NULL));
    int random_num_a = rand() % 9;
    int random_num = random_num_a+1;
    // gotoxy(15, 60);
    // printf("radom = %d\n", random_num);
    // pthread_mutex_unlock(&mutex_lock);
    if (random_num <= 3){
        generate_tree(tidx);
        return 1;
    }
    return 0;
}
void *start_tree(void *param)
{
    int idx = *((int *)(param));
    while (tree[idx].w + 4 > TREE_MIN_COLS){
        print_tree(tree[idx].h, tree[idx].w);
        if (GAME_FLAG == 0)
            return param;
        usleep(70000);
        delete_tree(tree[idx].h, tree[idx].w);
        tree[idx].w--;
    }
    return param;
}
void *game_tree(void* param)
{
    int thread_idx[MAX_TREE_CNT];
    for(int i=0;i<MAX_TREE_CNT;i++)
        thread_idx[i] = i;

    pthread_t pthread_cnt[MAX_TREE_CNT];
    
    while(1){
        if (GAME_FLAG == 0)
            break;
        if (tidx >= MAX_TREE_CNT)
            break;
        if (random_make_tree(tidx)){
            generate_tree(tidx);
            pthread_create(&pthread_cnt[tidx], NULL, start_tree, &thread_idx[tidx]);
            tidx++;
        }
        usleep(1000000);
    }
    return param;
}