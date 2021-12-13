/*
** EPITECH PROJECT, 2021
** infin_add file
** File description:
** only contain function related to the addition of infinite numbers
*/

#include <stdlib.h>
#include "bistromatic.h"

char *print_last_idk(int ret, char *final, int i)
{
    char *r_final;
    int b = 0;

    r_final = malloc(sizeof(char) * (my_strlen(final) + 3));
    r_final = final;
    if (ret == 1) {
        while (b < i) {
            r_final[b] = final[b];
            b++;
        }
        r_final[b] = '1';
        r_final[b + 1] = '\0';
    }
    return (r_final);
}

char do_p(char *nbr, int i)
{
    return (nbr[my_strlen(nbr) - i - 1]);
}

char get_final(char *nbr1, char *nbr2, int ret, int i)
{
    if (my_strlen(nbr1) > my_strlen(nbr2)) {
        return (get_v(nbr1[my_strlen(nbr1) - i - 1], ret + 48) + 48);
    } else {
        return (get_v(nbr2[my_strlen(nbr2) - i - 1], ret + 48) + 48);
    }
}

char get_ret(char *nbr1, char *nbr2, int ret, int i)
{
    if (my_strlen(nbr1) > my_strlen(nbr2)) {
        return (get_r(nbr1[my_strlen(nbr1) - i - 1], ret + 48));
    } else {
        return (get_r(ret + 48, nbr2[my_strlen(nbr2) - i - 1]));
    }
}

char *infin_add(char *n1, char *n2)
{
    int i;
    char *final;
    char n1_v;
    char n2_v;
    int ret = 0;

    final = malloc(sizeof(char) * (get_bigger(n1, n2) + 2));
    for (i = 0; i < get_size_of_op(n1, n2); i++) {
        final[i] = get_v(get_v(do_p(n1, i), do_p(n2, i)) + 48, ret + 48) + 48;
        ret = get_r((do_p(n1, i) - 48) + (do_p(n2, i) - 48) + 48, ret + 48);
    }
    for (i; i < get_bigger(n1, n2); i++) {
        final[i] = get_final(n1, n2, ret, i);
        ret = get_ret(n1, n2, ret, i);
    }
    final[i] = '\0';
    return (print_last_idk(ret, final, i));
}
