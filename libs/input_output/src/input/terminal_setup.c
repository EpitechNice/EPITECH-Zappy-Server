/*
** EPITECH PROJECT, 2024
** Server
** File description:
** terminal_setup
*/

#include "input_output.h"

static struct termios _bckp;

void init_input(void)
{
    struct termios new;

    tcgetattr(STDIN_FILENO, &_bckp);
    tcgetattr(STDIN_FILENO, &new);
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    printf("\033[?25l");
    fflush(stdout);
}

void reset_input(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &_bckp);
    printf("\033[?25h");
    fflush(stdout);
}
