/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** only contain get to get
*/

#include "bistromatic.h"

int get_v(char nbr1_val, char nbr2_val)
{
    int somme = (nbr1_val - 48) + (nbr2_val - 48);

    if (somme >= 10)
        return (somme - 10);
    return (somme);
}

int get_r(char nbr1_val, char nbr2_val)
{
    int somme = (nbr1_val - 48) + (nbr2_val - 48);

    if (somme >= 10)
        return (1);
    return (0);
}

void my_putstr_wt_pt(char *str, int size, int rec)
{
    int i = 0;
    int renc_nbr = 0;

    while (i < size) {
        if (str[size - i - 1] != '0' && renc_nbr == 0) {
            my_putchar(str[size - i - 1]);
            renc_nbr = 1;
        } else if (renc_nbr == 1 || rec == 1) {
            my_putchar(str[size - i - 1]);
        }
        i++;
    }
}

int get_bigger(char *nbr1, char *nbr2)
{
    if (my_strlen(nbr1) > my_strlen(nbr2))
        return (my_strlen(nbr1));
    else
        return (my_strlen(nbr2));
}

int get_size_of_op(char *nbr1, char *nbr2)
{
    if (my_strlen(nbr1) > my_strlen(nbr2))
        return (my_strlen(nbr2));
    else
        return (my_strlen(nbr1));
}
