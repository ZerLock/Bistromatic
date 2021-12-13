/*
** EPITECH PROJECT, 2021
** bistromatic.h
** File description:
** bistro header
*/

#ifndef BISTROMATIC_H_
    #define BISTROMATIC_H_

    #include <unistd.h>
    #include <stdlib.h>

    #define OP_OPEN_PARENT_IDX  0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX         2
    #define OP_SUB_IDX          3
    #define OP_NEG_IDX          3
    #define OP_MULT_IDX         4
    #define OP_DIV_IDX          5
    #define OP_MOD_IDX          6

    #define EXIT_USAGE    84
    #define EXIT_BASE     84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC   84
    #define EXIT_READ     84
    #define EXIT_OPS      84

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG        "error"

typedef struct args_div {
    char *str;
    char *nbr1;
    char *nbr2;
    int sign1;
    int sign2;
    char *act;
    char *rest;
} args_div_t;

typedef struct numbers {
    char c;
    struct numbers *next;
} numbers_t;

typedef struct clean {
    char *str;
    char *valo;
    char *str2;
} clean_t;

typedef struct parpaing {
    char *str;
    char *nbr1;
    char *nbr2;
    int id;
    int end;
} parpaing_t;

typedef struct args {
    char *str;
    int id;
    int end;
    int somme;
    int tmp;
} args_t;

int get_v(char nbr1_val, char nbr2_val);
int get_r(char nbr1_val, char nbr2_val);
char *clean_my_final_str(char *str);
void my_putstr_wt_pt(char *str, int size, int rec);
char *eval_expr(char const *str, unsigned int size);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_getnbr2(char *str);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strlen(char const *str);
int get_sign(char *str);
char *clean_str_div(char *str);
char *clean_less(char *str);
char *get_val_restaint(char c, char *restaint);
char get_result_div(char *actual, char *nbr2, char result);
char *get_actual(char *actual, char *nbr2);
int get_size_of_op(char *nbr1, char *nbr2);
int get_bigger(char *nbr1, char *nbr2);
int get_smaller(char *n1, char *n2);
int get_bigger_c(char *n1, char *n2);
char *add_neg(char *str);
char get_value(char n1, char n2);
void my_putstr_w_pt(char *str, int size);
int my_strcmp(char const *s1, char const *s2);
int my_str_isnbr(char *nbr);
int get_sign_of_nbr(char *nbr);
int error_check(char *ag1, char *ag2);
char *clean_s(char *str);
int my_strlene(char const *str);
char *my_revstr2(char *str);
char *infin_add(char *n1, char *n2);
char *infin_subs(char *n1, char *n2);
char *infin_div(char *nbr1, char *nbr2);
char *multiplication(char *left, char *right);
char *my_revstr(char *str);
char *addition(char *ag1, char *ag2);
char *get_clean_string(int size);
void clean_string(char *str);
void my_int_to_string(int nb, char *nb_f, int i);
int convert_base_n(char *str, char *base, char *op);
int check_operator_in_base(char *op, char *base);
int identical_char(char const *str);
int identical_char_d(char const *str, int i);
int verify_parenthesis(char const *expression, char const *ops);
int is_good_digit(char a, char const *digits);
int is_good_op(char a, char const *ops);
int has_unknown_digit(char const *expr, char const *digits, char const *ops);
int is_ops(char c, char const *op);
int is_ops_without_l_p(char c, char const *ops);
int is_valid_expression(char const *expr, char const *ops);
int check_par_and_ops(char const *expr, char const *ops, int i);
char div_by_sub(char *tampax2, char *tampax, char *restaint);
char *my_strcpy(char *dest, char const *str);
char *do_op(char *f_d, char s_d, char *t_d);
int get_id_idk(char *str, int id);
int check_op_par(char c);
int get_cl_par(char *str, int end, int id);
char get_op(int id, int end, char *str);
char *clean_str(char *str, int id, int end, char *val);
char *get_result(int id, int end, char *str);
char *get_val(int id, int end, char *str);
char *get_val2add(int id, int end, char *str);
char *eval_expr2(args_t *args);
void add_par(char const *str, char *str2);
int check_op_par(char c);
int check_isnbr(char *str, int id, int end);
int get_cl_par(char *str, int id, int end);
char is_op_d(char yeps);
char is_op(char yeps);
char get_op(int id, int end, char *str);
int get_size_of_int(int nb);
void my_int_to_string(int nb, char *nb_f, int i);
char *add_neg(char *str);
char clean_str_t(int i, int id, int end, clean_t *c_ac);
char *clean_str(char *str, int id, int end, char *val);
int check_op_all(char *str, int id, int end);
int while_is_nbr(char *str, char *nbr1, int id, int end);
int while_isnt_op_and_nbr(char *str, char op, int id);
char *get_nbr_in(char *str, int id, int end);
int get_id_int(char *str, int id, int end);
char *get_parpaing(parpaing_t *val_ac);
int check_prevop(char *str, int id, int temp2);
char *modulo(char *a, char *q);
int get_sign_mod(char *str);
char *division(char *nbr_u, char *nbr_d);
char *get_f_str(args_div_t *args);
char *get_str_for(args_div_t *args);
void get_second_if(args_div_t *args, int i);
char div_by_sub(char *tampax2, char *tampax, char *restaint);
char *get_actual(char *actual, char *nbr2);
char get_result_div(char *actual, char *nbr2, char result);
char *get_val_restaint(char c, char *restaint);
char *clean_less(char *str);
char *clean_str_div(char *str);
int get_sign(char *str);
int give_index_in_str(char c, char *base);
void add_number_in_list(numbers_t **list, char *to_add);
void add_operators(char c, char *operators, numbers_t **list);
int my_put_in_list(numbers_t **list, char c);
int is_char_in_str(char op, char *base);
char *convert_string(char *expr, char *operators, char *base);
int size_struct(numbers_t *list);
int get_m(char const *str);
char *modify_str(char const *str);

#endif /* BISTROMATIC_H_ */
