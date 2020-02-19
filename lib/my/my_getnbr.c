/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_getnbr.c
*/

#include "include/my.h"

int sign(char const *str)
{
    int sign = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    return sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;
    int check_sign = sign(str);
    int tmp;
    int error_value = 0;

    while ((str[i] >= '0' && str[i] <= '9') ||
    (str[i] == '-' || str[i] == '+')) {
        tmp = result;
        if (result > 0 && result < 10)
            result = result * check_sign;
        if (str[i] >= '0' && str[i] <= '9')
            result = (result * 10) + ((str[i] - '0') * check_sign);
        if ((tmp < 0 && tmp < result) || (tmp > 0 && tmp > result)) {
            return error_value;
        }
        i++;
    }
    return result;
}