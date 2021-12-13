/*
** EPITECH PROJECT, 2021
** My putstr
** File description:
** len(ç in py
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int count = 0;

    while (str[count] != 0) {
        my_putchar(str[count]);
        count++;
    }

    return (count);
}
