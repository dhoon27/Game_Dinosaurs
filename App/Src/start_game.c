#include <stdlib.h>
#include <unistd.h>
#include "start_game.h"
#include "print_image.h"
#include "console_control.h"
#include "object.h"
void start_game(void)
{
    system("clear");
    // print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    print_boundary(GAME_MIN_LINES, GAME_MIN_COLS, GAME_MAX_LINES, GAME_MAX_COLS);
    
    while(1){
        jump_dino();
    }

    while(1);
    sleep(3);
}