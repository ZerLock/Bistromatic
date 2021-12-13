/*
** EPITECH PROJECT, 2021
** conversion in base 10
** File description:
** base 10 conversion
*/

#include <stdlib.h>
#include "bistromatic.h"

void my_int_to_string(int nb, char *nb_f, int i)
{
    int nbr = 0;

    if (nb < 0) {
        i++;
        nbr = -nb;
    } else {
        nbr = nb;
    }
    nb_f[i] = nbr % 10 + 48;
    if (nbr >= 10)
        my_int_to_string(nbr / 10, nb_f, i + 1);
}
