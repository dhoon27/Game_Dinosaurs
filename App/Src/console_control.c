#include "console_control.h"
#include <stdio.h>

void gotoxy(int lines, int cols) 
{
     printf("\033[%d;%df", cols, lines);
     fflush(stdout);
}