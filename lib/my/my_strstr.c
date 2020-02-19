/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strstr.c
*/

#include <stddef.h>
#include "include/my.h"

int check_if_same(char *str, char const *to_find, int count)
{
    int count_to_find = 0;
    while (to_find[count_to_find] != '\0') {
        if (str[count] != to_find[count_to_find]) {
            return (0);
        }
        count++;
        count_to_find++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int count = 0;

    while (str[count] != '\0') {
        if (check_if_same(str, to_find, count) == 1) {
            return (str+count);
        }
        count++;
    }
    return (NULL);
}
