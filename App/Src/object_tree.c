#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "console_control.h"
#include "object_tree.h"
#include "print_image.h"

int check_tree(int h, int w)
{
    if (h > TREE_MIN_LINES && h < TREE_MAX_LINES && w > TREE_MIN_COLS && w < TREE_MAX_COLS)
        return 1;
    return 0;
}
void move_tree(int h, int w)
{
    if(check_tree(h,w+2)){
        gotoxy(h, w+2);
        printf("#");
        fflush(stdout);
    }
    for(int nw = w+1; nw<w+4; nw++){
        if (check_tree(h+1, nw)){
            gotoxy(h+1, nw);
            printf("#");
            fflush(stdout);
        }
    }
    for (int nw = w; nw < w + 5; nw++){
        if (check_tree(h+2, nw)){
            gotoxy(h+2, nw);
            printf("#");
            fflush(stdout);
        }
    }
    if (check_tree(h+3, w + 2)){
        gotoxy(h+3, w + 2);
        printf("#");
        fflush(stdout);
    }
    if (check_tree(h+4, w + 2)){
        gotoxy(h+4, w + 2);
        printf("#");
        fflush(stdout);
    }
}
void delete_tree(int h, int w)
{
    if (check_tree(h, w + 2))
    {
        gotoxy(h, w + 2);
        printf(" ");
        fflush(stdout);
    }
    for (int nw = w + 1; nw < w + 4; nw++)
    {
        if (check_tree(h + 1, nw))
        {
            gotoxy(h + 1, nw);
            printf(" ");
            fflush(stdout);
        }
    }
    for (int nw = w; nw < w + 5; nw++)
    {
        if (check_tree(h + 2, nw))
        {
            gotoxy(h + 2, nw);
            printf(" ");
            fflush(stdout);
        }
    }
    if (check_tree(h + 3, w + 2))
    {
        gotoxy(h + 3, w + 2);
        printf(" ");
        fflush(stdout);
    }
    if (check_tree(h + 4, w + 2))
    {
        gotoxy(h + 4, w + 2);
        printf(" ");
        fflush(stdout);
    }
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
void random_tree(int level)
{
    //seed를 현재 시간으로 --> 실행 마다 seed 달라짐
    srand((unsigned int)time(NULL));
    int random = (rand() % (MAX_TREE_CNT - level));
    if(random <= 1)
        generate_tree(tidx++);
}
void game_tree(void)
{
    int i;
    while(1){
        if (tidx >= MAX_TREE_CNT)
            return;
        random_tree(tidx+1);
        for (i = 0; i < tidx; i++){
            if (tree[i].w + 4 <= TREE_MIN_COLS)
                continue;
            move_tree(tree[i].h, tree[i].w);
            usleep(70000);
            delete_tree(tree[i].h, tree[i].w);
            tree[i].w--;
        }
    }
    
}