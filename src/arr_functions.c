/*
** EPITECH PROJECT, 2020
** general
** File description:
** array functions
*/

#include "radar.h"

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

int arr_size(char **arr)
{
    int i = -1;

    while (arr[++i]);
    return i;
}

char **arr_cpy(char **src)
{
    char **cpy;
    int i = 0;

    while (src[i])
        i++;
    cpy = malloc(sizeof(char *) * (i + 1));
    if (cpy == NULL)
        return NULL;
    cpy[i] = NULL;
    for (int j = 0; src[j]; j++)
        cpy[j] = my_strdup(src[j]);
    return cpy;
}