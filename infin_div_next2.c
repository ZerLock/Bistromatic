/*
** EPITECH PROJECT, 2021
** infin div second source file
** File description:
** infin div next source
*/

#include "bistromatic.h"
#include <stdlib.h>

char div_by_sub(char *tampax2, char *tampax, char *restaint)
{
    char result = '0';
    char *actual = malloc(sizeof(char) * (my_strlen(tampax) + 2));
    char *nbr2 = malloc(sizeof(char) * (my_strlen(tampax2) + 2));

    actual = tampax;
    nbr2 = tampax2;
    result = get_result_div(actual, nbr2, result);
    actual = get_actual(actual, nbr2);
    if (my_strcmp(tampax2, actual) == 0) {
        restaint[0] = '0';
        restaint[1] = '\0';
        return (result);
    }
    result--;
    my_strcpy(restaint, addition(actual, tampax2));
    return (result);
}
