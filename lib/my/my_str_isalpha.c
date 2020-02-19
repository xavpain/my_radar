/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_str_isalpha.c
*/

#include "include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] && str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return 0;
}
