/*
** EPITECH PROJECT, 2021
** verify_parenthesis
** File description:
** syntax error : verify parenthesis
*/

#include "bistromatic.h"

int verify_parenthesis(char const *expression, char const *ops)
{
    int i;
    int depth = 0;
    int opened_parenthesis = 0;
    int closed_parenthesis = 0;

    for (i = 0; expression[i]; i++) {
        if (expression[i] == ops[0]) {
            depth++;
            opened_parenthesis++;
        } else if (expression[i] == ops[1]) {
            depth--;
            closed_parenthesis++;
        }
        if (depth < 0)
            return (0);
    }
    if (opened_parenthesis == closed_parenthesis && depth == 0)
        return (1);
    return (0);
}
