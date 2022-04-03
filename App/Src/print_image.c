#include <stdio.h>
#include "print_image.h"
#include "console_control.h"

void print_boundary(void)
{
    gotoxy(MIN_LINES, MIN_COLS);
    for(int i=0;i<MAX_COLS - MIN_COLS;i++)
        printf("*");
    gotoxy(MIN_LINES, MIN_COLS);
    for(int i=0;i<MAX_LINES - MIN_LINES;i++)
        printf("*\n");
    gotoxy(MIN_LINES, MAX_COLS);
    for(int i=0;i<MAX_LINES - MIN_LINES;i++)
        printf("*\n");
    gotoxy(MAX_LINES, MIN_COLS);
    for(int i=0;i<MAX_COLS - MIN_COLS;i++)
        printf("*");
}
void print_dinosaur(void)
{
    printf("        $$$$$$$ \n");
    printf("       $$ $$$$$$\n");
    printf("       $$$$$$$$$\n");
    printf("$      $$$      \n");
    printf("$$     $$$$$$$  \n");
    printf("$$$   $$$$$     \n");
    printf(" $$  $$$$$$$$$$ \n");
    printf(" $$$$$$$$$$$    \n");
    printf("  $$$$$$$$$$    \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
}
void print_dinosaur_rev(void)
{
    printf(" $$$$$$$        \n");
    printf("$$$$$$ $$       \n");
    printf("$$$$$$$$$       \n");
    printf("      $$$      $\n");
    printf("  $$$$$$$     $$\n");
    printf("     $$$$$   $$$\n");
    printf(" $$$$$$$$$$  $$ \n");
    printf("    $$$$$$$$$$$ \n");
    printf("    $$$$$$$$$$  \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
}
void print_menu(void)
{
    printf("RUN\n\n");
    printf("QUIT\n");
}