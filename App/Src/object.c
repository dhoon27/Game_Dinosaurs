#include <stdlib.h>
#include <unistd.h>
#include "object.h"
#include "print_image.h"
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

        if(flag)
            h--;
        else
            h++;
    }
}
