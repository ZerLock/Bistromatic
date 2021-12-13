/*
** EPITECH PROJECT, 2021
** personal my_putchar
** File description:
** i cant put this in the github file
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
