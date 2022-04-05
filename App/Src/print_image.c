#include <stdio.h>
#include "print_image.h"
#include "console_control.h"

void print_boundary(int min_l, int min_c, int max_l, int max_c)
{
    gotoxy(min_l, min_c);
    for(int i=0;i<max_c - min_c;i++)
        printf("*");
    for(int i=0;i<max_l - min_l;i++){
        gotoxy(min_l + i, min_c);
        printf("*");
    }
    for(int i=0;i<max_l - min_l;i++){
        gotoxy(min_l + i, max_c);
        printf("*");
    }
    gotoxy(max_l, min_c);
    for(int i=0;i<max_c - min_c + 1;i++)
        printf("*");
    fflush(stdout);
}
void print_menu(void)
{
    int h = (MIN_LINES + MAX_LINES)/2 + 4;
    int w = (MIN_COLS + MAX_COLS)/2;
    gotoxy(h, w);
    printf("RUN");
    gotoxy(h+2, w);
    printf("QUIT");
    fflush(stdout);
}
void delete_xy(int lines, int cols)
{
    gotoxy(lines, cols);
    printf(" ");
    fflush(stdout);
}
void print_dinosaur(int h, int w)
{
    gotoxy(h, w+8);
    printf("$$$$$$$");
    gotoxy(h+1, w+7);
    printf("$$ $$$$$$");
    gotoxy(h+2, w+7);
    printf("$$$$$$$$$");
    gotoxy(h+3, w);
    printf("$      $$$");
    gotoxy(h+4, w);
    printf("$$     $$$$$$$");
    gotoxy(h+5, w);
    printf("$$$   $$$$$");
    gotoxy(h+6, w+1);
    printf("$$  $$$$$$$$$$");
    gotoxy(h+7, w+1);
    printf("$$$$$$$$$$$");
    gotoxy(h+8, w+2);
    printf("$$$$$$$$$$");
    gotoxy(h+9, w+4);
    printf("$$$$$$$$");
    gotoxy(h+10, w+5);
    printf("$$$$$$");
    fflush(stdout);
}
void print_dinosaur_rev(int h, int w)
{
    gotoxy(h, w);
    printf(" $$$$$$$        ");
    gotoxy(h+1, w);
    printf("$$$$$$ $$       ");
    gotoxy(h+2, w);
    printf("$$$$$$$$$       ");
    gotoxy(h+3, w);
    printf("      $$$      $");
    gotoxy(h+4, w);
    printf("  $$$$$$$     $$");
    gotoxy(h+5, w);
    printf("     $$$$$   $$$");
    gotoxy(h+6, w);
    printf(" $$$$$$$$$$  $$ ");
    gotoxy(h+7, w);
    printf("    $$$$$$$$$$$ ");
    gotoxy(h+8, w);
    printf("    $$$$$$$$$$  ");
    gotoxy(h+9, w);
    printf("    $$$$$$$$    ");
    gotoxy(h+10, w);
    printf("     $$$$$$     ");
    fflush(stdout);
}
void delete_dinosaur(int h, int w)
{
    gotoxy(h, w);
    printf("                ");
    gotoxy(h+1, w);
    printf("                ");
    gotoxy(h+2, w);
    printf("                ");
    gotoxy(h+3, w);
    printf("                ");
    gotoxy(h+4, w);
    printf("                ");
    gotoxy(h+5, w);
    printf("                ");
    gotoxy(h+6, w);
    printf("                ");
    gotoxy(h+7, w);
    printf("                ");
    gotoxy(h+8, w);
    printf("                ");
    gotoxy(h+9, w);
    printf("                ");
    gotoxy(h+10, w);
    printf("                ");
    fflush(stdout);
}
void print_tree(int h, int w)
{
    gotoxy(h, w+2);
    printf("#");
    gotoxy(h + 1, w+1);
    printf("###");
    gotoxy(h + 2, w);
    printf("#####");
    gotoxy(h + 3, w+2);
    printf("#");
    gotoxy(h + 4, w+2);
    printf("#");
    fflush(stdout);
}
void print_tree_1(int h, int w)
{
    gotoxy(h, w);
    printf("#");
}
void print_tree_2(int h, int w)
{
    gotoxy(h, w);
    printf("##");
}
void print_tree_3(int h, int w)
{
    gotoxy(h, w);
    printf("###");
}
void print_tree_4(int h, int w)
{
    gotoxy(h, w);
    printf("####");
}
void print_tree_5(int h, int w)
{
    gotoxy(h, w);
    printf("#####");
}