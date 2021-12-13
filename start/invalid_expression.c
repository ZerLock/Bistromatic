/*
** EPITECH PROJECT, 2021
** invalid expression
** File description:
** syntax error : invalid expression
*/

#include "bistromatic.h"

int is_ops(char c, char const *op)
{
    if (c == op[2] || c == op[3] || c == op[4] || c == op[5] || c == op[6])
        return (1);
    return (0);
}

int is_ops_without_l_p(char c, char const *ops)
{
    if (c == ops[4] || c == ops[5] || c == ops[6])
        return (1);
    return (0);
}

int check_par_and_ops(char const *expr, char const *ops, int i)
{
    if (i > 0) {
        if ((expr[i] == ops[0] && is_ops(expr[i - 1], ops) == 0) &&
        (expr[i] == ops[0] && expr[i - 1] != ops[0]))
            return (0);
        if (is_ops(expr[i], ops) == 1 &&
        is_ops_without_l_p(expr[i + 1], ops) == 1)
            return (0);
    }
    return (1);
}

int is_valid_expression(char const *expr, char const *ops)
{
    int len_expr;
    int i;

    len_expr = my_strlen(expr);
    if (is_ops_without_l_p(expr[0], ops) == 1)
        return (0);
    if (is_ops(expr[len_expr - 1], ops) == 1)
        return (0);
    for (i = 0; expr[i]; i++) {
        if (check_par_and_ops(expr, ops, i) == 0)
            return (0);
    }
    return (1);
}
