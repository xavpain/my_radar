/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcat.c
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int end = my_strlen(dest);

    while (src[i] != '\0') {
        dest[i + end] = src[i];
        i++;
    }
    dest[i + end] = '\0';
    return dest;
}