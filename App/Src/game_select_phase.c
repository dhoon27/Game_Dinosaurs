#include <stdio.h>
#include <stdlib.h>
#include "game_select_phase.h"
#include "print_image.h"
#include "console_control.h"
#include "linux_kbhit.h"

void game_select_phase(void)
{
    init_keyboard();

    print_boundary();
    print_menu();
    int h = (MIN_LINES + MAX_LINES)/2 + 4;
    int w = (MIN_COLS + MAX_COLS)/2 - 2;
    int nh = h, nw = w;
    gotoxy(nh, nw);
    printf("*");
    while(1){
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
                    break;
                }
                else{
                    system("clear");
                }
            }
        }
        gotoxy(nh, nw);
        printf("*");
        fflush(stdout);

        print_dinosaur();
        for(int i=0; i<400000000;i++);
        print_dinosaur_rev();
        for(int i=0; i<400000000;i++);
    }
    close_keyboard();
    // fflush(stdout);
    // fflush(stdin);

}