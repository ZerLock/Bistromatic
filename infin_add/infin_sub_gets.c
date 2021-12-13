/*
** EPITECH PROJECT, 2021
** get file
** File description:
** only contain get functions
*/

#include "bistromatic.h"

int get_smaller(char *n1, char *n2)
{
    if (my_strlen(n1) > my_strlen(n2))
        return (my_strlen(n2));
    else
        return (my_strlen(n1));
}

int get_bigger_c(char *n1, char *n2)
{
    if (my_strlen(n1) > my_strlen(n2))
        return (my_strlen(n1));
    else
        return (my_strlen(n2));
}

char get_value(char n1, char n2)
{
    int somme = (n1 - 48) - (n2 - 48);

    if (somme < 0)
        return (((n1 - 48) + 10) - (n2 - 48));
    return (somme);
}

void my_putstr_w_pt(char *str, int size)
{
    int i = 0;
    int renc_nbr = 0;

    while (i < size) {
        if (str[size - i - 1] != '0' && renc_nbr == 0) {
            my_putchar(str[size - i - 1]);
            renc_nbr = 1;
        } else if (renc_nbr == 1) {
            my_putchar(str[size - i - 1]);
        }
        i++;
    }
}
