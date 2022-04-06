#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "print_image.h"
#include "console_control.h"
#include "object_tree.h"

pthread_mutex_t mutex_lock;
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
    pthread_mutex_lock(&mutex_lock);
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
    pthread_mutex_unlock(&mutex_lock);
}
void print_dinosaur_rev(int h, int w)
{
    pthread_mutex_lock(&mutex_lock);
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
    pthread_mutex_unlock(&mutex_lock);
}
void delete_dinosaur(int h, int w)
{
    pthread_mutex_lock(&mutex_lock);
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
    pthread_mutex_unlock(&mutex_lock);
}
void print_tree(int h, int w)
{
    pthread_mutex_lock(&mutex_lock);

    if (check_tree(h, w + 2))
    {
        gotoxy(h, w + 2);
        printf("#");
        fflush(stdout);
    }
    for (int nw = w + 1; nw < w + 4; nw++)
    {
        if (check_tree(h + 1, nw))
        {
            gotoxy(h + 1, nw);
            printf("#");
            fflush(stdout);
        }
    }
    for (int nw = w; nw < w + 5; nw++)
    {
        if (check_tree(h + 2, nw))
        {
            gotoxy(h + 2, nw);
            printf("#");
            fflush(stdout);
        }
    }
    if (check_tree(h + 3, w + 2))
    {
        gotoxy(h + 3, w + 2);
        printf("#");
        fflush(stdout);
    }
    if (check_tree(h + 4, w + 2))
    {
        gotoxy(h + 4, w + 2);
        printf("#");
        fflush(stdout);
    }
    pthread_mutex_unlock(&mutex_lock);
}
void delete_tree(int h, int w)
{
    pthread_mutex_lock(&mutex_lock);

    if (check_tree(h, w + 2))
    {
        gotoxy(h, w + 2);
        printf(" ");
        fflush(stdout);
    }
    for (int nw = w + 1; nw < w + 4; nw++)
    {
        if (check_tree(h + 1, nw))
        {
            gotoxy(h + 1, nw);
            printf(" ");
            fflush(stdout);
        }
    }
    for (int nw = w; nw < w + 5; nw++)
    {
        if (check_tree(h + 2, nw))
        {
            gotoxy(h + 2, nw);
            printf(" ");
            fflush(stdout);
        }
    }
    if (check_tree(h + 3, w + 2))
    {
        gotoxy(h + 3, w + 2);
        printf(" ");
        fflush(stdout);
    }
    if (check_tree(h + 4, w + 2))
    {
        gotoxy(h + 4, w + 2);
        printf(" ");
        fflush(stdout);
    }
    pthread_mutex_unlock(&mutex_lock);
}
void print_fail(void)
{
    system("clear");
    print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    gotoxy(10, 20);
    printf("FAIL!");
}
void print_success(void)
{
    system("clear");
    print_boundary(MIN_LINES, MIN_COLS, MAX_LINES, MAX_COLS);
    gotoxy(10, 20);
    printf("SUCCESS!");
}