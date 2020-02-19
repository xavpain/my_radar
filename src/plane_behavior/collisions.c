/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** collisions
*/

#include "radar.h"
#include "math.h"

void move_sprites(data_t *data)
{
    for (int i = 0; PLA[i]; i++)
        if (PLA[i]->delay == 0 && PLA[i]->is_arrived == 0) {
            sfSprite_move(PLA[i]->sprite, PLA[i]->vector);
            sfRectangleShape_move(PLA[i]->hitbox, PLA[i]->vector);
        }
}

int is_finished(plane_t **planes)
{
    sfVector2f cur;

    for (int i = 0; planes[i]; i++) {
        cur = sfSprite_getPosition(planes[i]->sprite);
        if (cur.x >= planes[i]->xb - 5 && cur.x <= planes[i]->xb + 5
        && cur.y >= planes[i]->yb - 5 && cur.y <= planes[i]->yb + 5
        && planes[i]->delay == 0 && planes[i]->is_arrived == 0)
            planes[i]->is_arrived = 1;
    }
    for (int i = 0; planes[i]; i++)
        if (planes[i]->is_arrived != 1)
            return 0;
    return -1;
}

void check_collisions(data_t *data)
{
    sfVector2f cur;
    sfVector2f cmp;

    for (int i = 0; PLA[i]; i++) {
        cur = sfSprite_getPosition(PLA[i]->sprite);
        for (int j = 0; PLA[j]; j++) {
            cmp = sfSprite_getPosition(PLA[j]->sprite);
            if (j != i && PLA[i]->is_arrived == 0
            && PLA[j]->is_arrived == 0 && PLA[i]->under_turret == 0
            && cur.x >= cmp.x - 20 && cur.x <= cmp.x + 20
            && cur.y >= cmp.y - 20 && cur.y <= cmp.y + 20) {
                PLA[i]->is_arrived = 1;
                PLA[j]->is_arrived = 1;
            }
        }
    }
}

int is_overlapping(sfVector2f cur, turret_t *turret)
{
    float x = fabs((double)turret->x - cur.x) - 10;
    float y = fabs((double)turret->y - cur.y) - 10;
    float rad = sfCircleShape_getRadius(turret->hitbox);

    if (x > 0) {
        if (y < 0)
            return (x < rad ? 1 : 0);
        else
            return (x * x + y * y < rad * rad ? 1 : 0);
    }
    return (y < rad ? 1 : 0);
}

void is_under_turret(data_t *data)
{
    sfVector2f cur;
    for (int i = 0; PLA[i]; i++) {
        cur = sfSprite_getPosition(PLA[i]->sprite);
        PLA[i]->under_turret = 0;
        for (int y = 0; TUR[y]; y++) {
            if (PLA[i]->is_arrived == 0 && is_overlapping(cur, TUR[y]) == 1)
            PLA[i]->under_turret = 1;
        }
    }
}