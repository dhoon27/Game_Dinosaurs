#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "start_game.h"
#include "console_control.h"
#include "object_dino.h"
#include "object_tree.h"
#include "print_image.h"

int GAME_FLAG = 1;
int checking_fail(void)
{
    int idx;
    for(idx =0; idx < tidx; idx++){
        if(DINO_MAX_W < tree[idx].w)
            continue;
        if(tree[idx].w + 4 < DINO_MIN_W)
            continue;
        if(tree[idx].h > dino.h + 10)
            continue;
        if (tree[idx].h+4 < dino.h)
            continue;
        int sidx;
        if(tree[idx].h >= dino.h){
            sidx = tree[idx].h - dino.h;
            for(int tid = 0;sidx<11;sidx++,tid++){
                if (tree[idx].hitbox[tid][1] >= dino.hitbox[sidx][0] && dino.hitbox[sidx][1] >= tree[idx].hitbox[tid][0])
                    return 1;
            }
        }
        else{
            sidx = dino.h - tree[idx].h;
            for(int did=0;sidx<5;sidx++, did++){
                if (tree[idx].hitbox[sidx][1] >= dino.hitbox[did][0] && dino.hitbox[did][1] >= tree[idx].hitbox[sidx][0])
                    return 1;
            }
        }
    }
    return 0;
}
void start_game(void)
{
    system("clear");
    // print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    print_boundary(GAME_MIN_LINES, GAME_MIN_COLS, GAME_MAX_LINES, GAME_MAX_COLS);

    pthread_t pthread_cnt[3];
    if(pthread_create(&pthread_cnt[0], NULL, game_dino, 0) != 0){
        return;
    }
    if(pthread_create(&pthread_cnt[1], NULL, game_tree, 0) != 0){
        return;
    }

    while(1){
        if (checking_fail()){
            GAME_FLAG = 0;
            print_fail();
            return;
        }
    }
    print_success();
}