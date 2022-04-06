#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "start_game.h"
#include "console_control.h"
#include "object_dino.h"
#include "object_tree.h"
#include "print_image.h"

int GAME_FLAG = 1;
extern pthread_mutex_t mutex_lock;
extern int tidx;
void *checking_fail(void *param)
{
    int idx;
    int sidx;
    int res = *((int*)param);
    while(1){
        for (idx = 0; idx < tidx; idx++){
            pthread_mutex_lock(&mutex_lock);
            // gotoxy(2, 70);
            // printf("dino = %d, tree == %d!!", dino.h, tree[idx].w);
            if (tree[idx].w + 4 < TREE_MIN_COLS){
                pthread_mutex_unlock(&mutex_lock);
                continue;
            }
            if (DINO_MAX_W < tree[idx].w){
                pthread_mutex_unlock(&mutex_lock);
                continue;
            }
            if (tree[idx].w + 4 < DINO_MIN_W){
                pthread_mutex_unlock(&mutex_lock);
                continue;
            }
            if (tree[idx].h > dino.h + 10){
                pthread_mutex_unlock(&mutex_lock);
                continue;
            }
            if (tree[idx].h + 4 < dino.h){
                pthread_mutex_unlock(&mutex_lock);
                continue;
            }
            if (tree[idx].h >= dino.h){
                sidx = tree[idx].h - dino.h;
                for (int tid = 0; sidx < 11; sidx++, tid++){
                    if (tree[idx].hitbox[tid][1] + tree[idx].w >= dino.hitbox[sidx][0] && dino.hitbox[sidx][1] >= tree[idx].hitbox[tid][0] + tree[idx].w){
                        gotoxy(1, 50);
                        printf("dino_w_0 = %d, tree_w_0 = %d!!", dino.hitbox[sidx][0], tree[idx].hitbox[tid][0] + tree[idx].w);
                        gotoxy(2, 50);
                        printf("dino_w_1 = %d, tree_w_1 = %d!!", dino.hitbox[sidx][1], tree[idx].hitbox[tid][1] + tree[idx].w);
                        GAME_FLAG = 0;
                        res = 0xDEADBEEF;
                        pthread_mutex_unlock(&mutex_lock);
                        return (void*)(res);
                    }
                }
            }
            else{
                gotoxy(13, 80);
                printf("HIT 3!!");
                sidx = dino.h - tree[idx].h;
                for (int did = 0; sidx < 5; sidx++, did++){
                    if (tree[idx].hitbox[sidx][1] >= dino.hitbox[did][0] && dino.hitbox[did][1] >= tree[idx].hitbox[sidx][0]){
                        gotoxy(14, 80);
                        printf("HIT 4!!");
                        GAME_FLAG = 0;
                        res = 0xDEADBEEF;
                        pthread_mutex_unlock(&mutex_lock);
                        return (void *)(res);
                    }
                }
            }
            pthread_mutex_unlock(&mutex_lock);
        }
    }
    return (void *)(res);
}

void start_game(void)
{
    system("clear");
    // print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    print_boundary(GAME_MIN_LINES, GAME_MIN_COLS, GAME_MAX_LINES, GAME_MAX_COLS);

    pthread_t pthread_cnt[4];
    if(pthread_create(&pthread_cnt[0], NULL, game_dino, 0) != 0)
        return;

    if(pthread_create(&pthread_cnt[1], NULL, game_tree, 0) != 0)
        return;
    int argu = 0, res=0;
    int p_end = pthread_create(&pthread_cnt[2], NULL, checking_fail, (void*)&argu);
    if(p_end != 0)
        return;

    int res_0, res_1;
    pthread_join(pthread_cnt[2], (void *)&res);
    pthread_join(pthread_cnt[0], (void *)&res_0);
    pthread_join(pthread_cnt[1], (void *)&res_1);
    pthread_mutex_lock(&mutex_lock);
    gotoxy(27, 60);
    printf("THREAD END!!");
    gotoxy(28, 60);
    printf("res = 0x%x\n", (int)res);
    pthread_mutex_unlock(&mutex_lock);
    sleep(2);
    if ((int)res == 0xDEADBEEF){
        GAME_FLAG = 0;
        print_fail();
        return;
    }
    // print_success();
    // if(flag != 0){
        
    //     return;
    // }

    while(1);
}