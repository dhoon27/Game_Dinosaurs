#include <stdio.h>
#include "game_select_phase.h"
#include "print_image.h"
#include "console_control.h"

void game_select_phase(void)
{
    print_boundary();
    print_menu();
    int h = (MIN_LINES + MAX_LINES)/2 + 4;
    int w = (MIN_COLS + MAX_COLS)/2 - 2;
    while(1){
        gotoxy(h,w);
        printf("*");
        print_dinosaur();
        for(int i=0; i<400000000;i++);
        print_dinosaur_rev();
        for(int i=0; i<400000000;i++);
    }
}