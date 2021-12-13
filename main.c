/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "bistromatic.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    int size_base = my_strlen(b);

    if (size_base < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

void verify_arg(char *expr, char *base, char *op)
{
    if (identical_char(base) || identical_char(op)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (check_operator_in_base(op, base)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (has_unknown_digit(expr, base, op)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (!verify_parenthesis(expr, op)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (!is_valid_expression(expr, op)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr = NULL;
    char *test = NULL;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    verify_arg(expr, av[1], av[2]);
    expr = convert_string(expr, av[2], av[1]);
    test = eval_expr(expr, size);
    convert_base_n(test, av[1], av[2]);
    return (EXIT_SUCCESS);
}
