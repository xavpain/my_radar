/*
** EPITECH PROJECT, 2019
** hea
** File description:
** der
*/

#include <stdlib.h>
#include "./include/my.h"

int is_alnum(char c)
{
    if (c == ' ' || c == '\t' || c == '\0' || c >= 127)
        return (0);
    return (1);
}

int word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0)
            word++;
        i++;
    }
    return (word);
}

char **my_str_to_word_array(char *str)
{
    int j = 0;
    int i = 0;
    char **wordtab = malloc((word_count(str) + 1) * sizeof(char *));
    int len = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]))
            len++;
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0) {
            wordtab[j] = malloc(len + 1);
            my_strncpy(wordtab[j], &str[i - len + 1], len);
            wordtab[j][len] = '\0';
            len = 0;
            j++;
        }
        i++;
    }
    wordtab[j] = NULL;
    return (wordtab);
}
