/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** parse_file
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "radar.h"

turret_t *update_turret(char *buf)
{
    turret_t *turret = malloc(sizeof(turret_t));
    char **line = my_str_to_word_array(buf);

    if (arr_size(line) != 3)
        return NULL;
    for (int i = 0; line[i]; i++) {
        if (my_str_isalpha(line[i]) == -1)
            return NULL;
    }
    turret->x = my_getnbr(line[0]);
    turret->y = my_getnbr(line[1]);
    turret->radius = my_getnbr(line[2]);
    if (turret->x > WID || turret->x < 0 || turret->y > HEI
    || turret->y < 0 || turret->radius > 50 || turret->radius == 0)
        return NULL;
    return turret;
}

plane_t *update_plane(char *buf)
{
    plane_t *plane = malloc(sizeof(plane_t));
    char **line = my_str_to_word_array(buf);

    if (arr_size(line) != 6)
        return NULL;
    for (int i = 0; line[i]; i++)
        if (my_str_isalpha(line[i]) == -1)
            return NULL;
    plane->xa = my_getnbr(line[0]);
    plane->ya = my_getnbr(line[1]);
    plane->xb = my_getnbr(line[2]);
    plane->yb = my_getnbr(line[3]);
    plane->speed = my_getnbr(line[4]);
    plane->delay = my_getnbr(line[5]);
    plane->vector = get_vector(plane);
    plane->is_arrived = 0;
    if (plane->xa > WID || plane->xb > WID || plane->ya > HEI
    || plane->yb > HEI || plane->speed == 0 || plane->delay > 60)
        return NULL;
    return plane;
}

data_t *update_from_line(data_t *data, char *buf)
{
    static int p = 0;
    static int t = 0;

    if (buf[0] != '\0' && buf[0] != '\n' && buf[0] != 'A' && buf[0] != 'T')
        return NULL;
    buf[my_strlen(buf) - 1] = '\0';
    if (buf[0] == 'A') {
        data->planes[p] = update_plane(buf + 2);
        if (data->planes[p++] == NULL)
            return NULL;
    }   else if (buf[0] == 'T') {
        data->turrets[t] = update_turret(buf + 2);
        if (data->turrets[t++] == NULL)
            return NULL;
    }
    data->planes[p] = NULL;
    data->turrets[t] = NULL;
    return data;
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));
    plane_t **planes;
    turret_t **turrets;

    planes = malloc(sizeof(plane_t) * 128);
    if (planes == NULL)
        return NULL;
    turrets = malloc(sizeof(turret_t) * 128);
    if (turrets == NULL)
        return NULL;
    data->planes = planes;
    data->turrets = turrets;
    return data;
}

data_t *read_file(char *filepath)
{
    data_t *data = init_data();
    char *buf = malloc(128);
    size_t n = 128;
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        my_putstr("Error: Cannot read file.\n");
        return NULL;
    }
    if (my_strncmp(my_revstr(filepath), "lms.", 4) != 0) {
        my_putstr("Error: Wrong extension.\n");
        return NULL;
    }
    while (getline(&buf, &n, file) != -1) {
        data = update_from_line(data, buf);
        if (data == NULL || (PLA[0] == NULL && TUR[0] == NULL))
            return NULL;
    }
    return data == NULL ? NULL : data;
}