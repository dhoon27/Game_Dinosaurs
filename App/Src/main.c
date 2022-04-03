#include <stdlib.h>
#include <stdio.h>
#include "game_select_phase.h"
#include "print_image.h"

int main(void)
{
    system("clear");
    printf("\e[?25l");
    game_select_phase();
    system("clear");
    return 0;
}