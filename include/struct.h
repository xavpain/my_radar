/*
** EPITECH PROJECT, 2020
** include structs
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    int width;
    int height;
    int bitsPerPixel;
    sfEvent event;
    sfClock *clock;
    sfText *timer;
    sfTexture *map;
    sfTexture *plane_texture;
    sfTexture *turret_texture;
    sfSprite *turret;
    sfSprite *plane;
    sfSprite *background;
    int l_key;
    int s_key;
    int is_sec;
} window_t;

typedef struct plane_s
{
    int xa;
    int ya;
    int xb;
    int yb;
    int speed;
    int delay;
    int is_arrived;
    int under_turret;
    sfVector2f vector;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
}plane_t;

typedef struct turret_s
{
    int x;
    int y;
    int radius;
    sfSprite *sprite;
    sfCircleShape *hitbox;
}turret_t;

typedef struct data_s
{
    turret_t **turrets;
    plane_t **planes;
}data_t;

#endif /* !STRUCT_H_ */
