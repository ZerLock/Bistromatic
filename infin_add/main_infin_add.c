/*
** EPITECH PROJECT, 2021
** main file of infin_add project
** File description:
** main file containning main functions
*/

#include "bistromatic.h"

char *activate_elsif(char *ag1, char *ag2)
{
    char *final;

    final = malloc(sizeof(char) * (my_strlen(ag1) + my_strlen(ag2)));
    if (my_strcmp(clean_s(ag1), clean_s(ag2)) < 0) {
        if (get_sign_of_nbr(ag1) < 0) {
            return (my_revstr2(infin_subs(clean_s(ag2), clean_s(ag1))));
        } else {
            final = my_revstr2(infin_subs(clean_s(ag2), clean_s(ag1)));
            return (add_neg(final));
        }
    } else if (my_strcmp(clean_s(ag1), clean_s(ag2)) == 0) {
        return ("0");
    } else {
        if (get_sign_of_nbr(ag2) < 0) {
            return (my_revstr2(infin_subs(clean_s(ag1), clean_s(ag2))));
        } else {
            final = my_revstr2(infin_subs(clean_s(ag1), clean_s(ag2)));
            return (add_neg(final));
        }
    }
}

char *activate_first_if(char *ag1, char *ag2)
{
    char *final;

    final = malloc(sizeof(char) * (my_strlen(ag1) + my_strlen(ag2)));
    if (my_strlen(clean_s(ag1)) < my_strlen(clean_s(ag2))) {
        if (get_sign_of_nbr(ag1) < 0) {
            return (my_revstr2(infin_subs(clean_s(ag2), clean_s(ag1))));
        } else {
            final = my_revstr2(infin_subs(clean_s(ag2), clean_s(ag1)));
            return (add_neg(final));
        }
    } else if (my_strlen(clean_s(ag1)) == my_strlen(clean_s(ag2))) {
        return (activate_elsif(ag1, ag2));
    } else {
        if (get_sign_of_nbr(ag2) < 0) {
            return (my_revstr2(infin_subs(clean_s(ag1), clean_s(ag2))));
        } else {
            final = my_revstr2(infin_subs(clean_s(ag1), clean_s(ag2)));
            return (add_neg(final));
        }
    }
}

int verify_no(char *n1)
{
    int i = 0;
    int inc = 0;
    int val = 0;

    while (n1[i]) {
        if (n1[i] == '0')
            inc++;
        if (n1[i] != '-')
            val++;
        i++;
    }
    if (inc == val)
        return (1);
    return (0);
}

int both_zero(char *n1, char *n2)
{
    if (verify_no(n1) == 1 && verify_no(n2) == 1)
        return (1);
    return (0);
}

char *addition(char *ag1, char *ag2)
{
    char *final;

    final = malloc(sizeof(char) * (my_strlen(ag1) + my_strlen(ag2) + 8));
    if (both_zero(ag1, ag2) == 1) {
        return (get_clean_string(1));
    }
    if (get_sign_of_nbr(ag1) < 0 || get_sign_of_nbr(ag2) < 0) {
        if (get_sign_of_nbr(ag1) < 0 && get_sign_of_nbr(ag2) < 0) {
            final = my_revstr2(infin_add(clean_s(ag1), clean_s(ag2)));
            final = add_neg(final);
            return (final);
        }
        final = activate_first_if(ag1, ag2);
        return (final);
    } else {
        return (my_revstr2(infin_add(clean_s(ag1), clean_s(ag2))));
    }
    return (final);
}
