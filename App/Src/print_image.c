#include <stdio.h>
#include "print_image.h"
#include "console_control.h"

void print_boundary(void)
{
    gotoxy(MIN_LINES, MIN_COLS);
    for(int i=0;i<MAX_COLS - MIN_COLS;i++)
        printf("*");
    for(int i=0;i<MAX_LINES - MIN_LINES;i++){
        gotoxy(MIN_LINES + i, MIN_COLS);
        printf("*");
    }
    for(int i=0;i<MAX_LINES - MIN_LINES;i++){
        gotoxy(MIN_LINES + i, MAX_COLS);
        printf("*");
    }
    gotoxy(MAX_LINES, MIN_COLS);
    for(int i=0;i<MAX_COLS - MIN_COLS + 1;i++)
        printf("*");
    fflush(stdout);
}
void print_dinosaur(void)
{
    int h = MIN_LINES + 3;
    int w = (MIN_COLS + MAX_COLS)/2 - 5;
    gotoxy(h, w);
    printf("        $$$$$$$ ");
    gotoxy(h+1, w);
    printf("       $$ $$$$$$");
    gotoxy(h+2, w);
    printf("       $$$$$$$$$");
    gotoxy(h+3, w);
    printf("$      $$$      ");
    gotoxy(h+4, w);
    printf("$$     $$$$$$$  ");
    gotoxy(h+5, w);
    printf("$$$   $$$$$     ");
    gotoxy(h+6, w);
    printf(" $$  $$$$$$$$$$ ");
    gotoxy(h+7, w);
    printf(" $$$$$$$$$$$    ");
    gotoxy(h+8, w);
    printf("  $$$$$$$$$$    ");
    gotoxy(h+9, w);
    printf("    $$$$$$$$    ");
    gotoxy(h+10, w);
    printf("     $$$$$$     ");
    fflush(stdout);
}
void print_dinosaur_rev(void)
{
    int h = MIN_LINES + 3;
    int w = (MIN_COLS + MAX_COLS)/2 - 5;
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
void print_menu(void)
{
    int h = (MIN_LINES + MAX_LINES)/2 + 4;
    int w = (MIN_COLS + MAX_COLS)/2;
    gotoxy(h, w+1);
    printf("RUN");
    gotoxy(h+2, w);
    printf("QUIT");
}