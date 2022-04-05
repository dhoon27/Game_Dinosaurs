#include <stdio.h>
#include <unistd.h>
#include "game_select_phase.h"
#include "print_image.h"
#include "console_control.h"
#include "linux_kbhit.h"
#include "start_game.h"

void game_select_phase(void)
{
    init_keyboard();

    print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    print_menu();
    int h = (MIN_LINES + MAX_LINES)/2 + 4;
    int w = (MIN_COLS + MAX_COLS)/2 - 2;
    int nh = h, nw = w;
    gotoxy(nh, nw);
    printf("*");
    fflush(stdout);
    while(1){
        fflush(stdin);
        if(_kbhit()){
            int ch = _getch();
            if(ch == (int)'w'){
                if(nh != h){
                    delete_xy(nh,nw);
                    nh -= 2;
                }
            }
            else if(ch == (int)'s'){ //down
                if(nh == h){
                    delete_xy(nh,nw);
                    nh +=2;
                }
            }
            else if(ch == 10){
                if(nh == h+2){
                    sleep(3);
                    return;
                }
                else{
                    start_game();
                    print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
                    print_menu();
                }
            }
        }
        gotoxy(nh, nw);
        printf("*");
        fflush(stdout);

        print_dinosaur(MIN_LINES + 3, (MIN_COLS + MAX_COLS)/2 - 5);
        usleep(800000);
        print_dinosaur_rev(MIN_LINES + 3, (MIN_COLS + MAX_COLS)/2 - 5);
        usleep(800000);
    }
    close_keyboard();
}