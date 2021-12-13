/*
** EPITECH PROJECT, 2021
** My revstr
** File description:
** reverse the order of the string
*/

char *my_revstr(char *str)
{
    int nb_char = 0;
    int str_len = 0;
    char temp;
    while (str[nb_char] != '\0') {
        nb_char++;
    }

    str_len = nb_char;

    for (nb_char = 0; nb_char < str_len / 2; nb_char++) {
        temp = str[nb_char];
        str[nb_char] = str[str_len - nb_char - 1];
        str[str_len - nb_char - 1] = temp;
    }

    return (str);
}
