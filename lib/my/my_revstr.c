/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_revstr.c
*/

#include <stddef.h>
#include "include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int i = 0;
    char tmp;

    while (len > i) {
        tmp = str[len];
        str[len] = str[i];
        str[i] = tmp;
        i++;
        len--;
    }
    return (str);
}
