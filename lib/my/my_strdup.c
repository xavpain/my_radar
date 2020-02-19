/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strdup
*/

#include "include/my.h"

char *my_strdup(char const *src)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (src[i] != '\0') {
        result[i] = src[i];
        i++;
    }
    result[i] = '\0';
    return result;
}
