#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "object_dino.h"
#include "print_image.h"
#include "linux_kbhit.h"
#include "console_control.h"

extern int GAME_FLAG;

void init_dino(void)
{
    dino.h = DINO_MIN_H;
    dino.w = DINO_MIN_W;
    dino.hitbox[0][0] = DINO_MIN_W + 8;
    dino.hitbox[0][1] = DINO_MIN_W + 14;

    dino.hitbox[1][0] = DINO_MIN_W + 7;
    dino.hitbox[1][1] = DINO_MIN_W + 15;

    dino.hitbox[2][0] = DINO_MIN_W + 7;
    dino.hitbox[2][1] = DINO_MIN_W + 15;

    dino.hitbox[3][0] = DINO_MIN_W;
    dino.hitbox[3][1] = DINO_MIN_W + 9;

    dino.hitbox[4][0] = DINO_MIN_W;
    dino.hitbox[4][1] = DINO_MIN_W + 13;

    dino.hitbox[5][0] = DINO_MIN_W;
    dino.hitbox[5][1] = DINO_MIN_W + 10;

    dino.hitbox[6][0] = DINO_MIN_W + 1;
    dino.hitbox[6][1] = DINO_MIN_W + 14;

    dino.hitbox[7][0] = DINO_MIN_W + 1;
    dino.hitbox[7][1] = DINO_MIN_W + 11;

    dino.hitbox[8][0] = DINO_MIN_W + 2;
    dino.hitbox[8][1] = DINO_MIN_W + 11;

    dino.hitbox[9][0] = DINO_MIN_W + 4;
    dino.hitbox[9][1] = DINO_MIN_W + 11;

    dino.hitbox[10][0] = DINO_MIN_W + 5;
    dino.hitbox[10][1] = DINO_MIN_W + 10;
}
void jump_dino(void)
{
    
    int h = 0;
    int flag=1;
    int compensation = 15000;
    while (flag != 0 || h != 0)
    {
        
        print_dinosaur(DINO_MIN_H + h, DINO_MIN_W);
        usleep(100000 + -1 * h * compensation);
        delete_dinosaur(DINO_MIN_H + h, DINO_MIN_W);
       
        if(h == -5)
            flag = 0;

        if(flag){
            dino.h--;
            h--;
        }
        else{
            dino.h++;
            h++;
        }
    }
    dino.h++;
}
void *game_dino(void* param)
{
    init_keyboard();
    while(1){
        if(GAME_FLAG == 0)
            break;
        print_dinosaur(DINO_MIN_H, DINO_MIN_W);
        fflush(stdin);
        if (_kbhit()){
            int ch = _getch();
            if (ch == 0x20){
                
                jump_dino();
                
                while (_kbhit()){
                    _getch();
                }
            }
        }
    }
    fflush(stdout);
    close_keyboard();
    return param;
}