/*
** EPITECH PROJECT, 2021
** my_get_number
** File description:
** my
*/

int my_getnbr(char const *str)
{
    int it;
    int sign;
    long int c;

    c = 0;
    sign = 1;
    it = 0;
    while (str[it] == '-' || str[it] == '+') {
        if (str[it] == '-')
            sign *= -1;
        it++;
    }
    while (str[it] >= 48 && str[it] <= 57) {
        c = c * 10 + (str[it] - 48);
        it++;
        if (c > 2147483647 || c < -2147483648)
            return (0);
    }
    return (c * sign);
}
