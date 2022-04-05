#include <stdlib.h>
#include "start_game.h"
#include "console_control.h"
#include "object_dino.h"
#include "object_tree.h"
#include "print_image.h"

void start_game(void)
{
    system("clear");
    // print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    print_boundary(GAME_MIN_LINES, GAME_MIN_COLS, GAME_MAX_LINES, GAME_MAX_COLS);
    
    while(1){
        // game_dino();
        game_tree();
        for(int i=0;i<1000000000;i++);
    }
}