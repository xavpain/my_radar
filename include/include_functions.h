/*
** EPITECH PROJECT, 2020
** include functions
** File description:
** include_functions
*/

#ifndef INCLUDE_FUNCTIONS_H_
#define INCLUDE_FUNCTIONS_H_

//macros

#define WI window->
#define WID 1920
#define HEI 1080
#define PLA data->planes
#define TUR data->turrets


//includes for arr_funtions.c

int arr_size(char **arr);
void free_arr(char **arr);
char **arr_cpy(char **src);

//includes for parsing.c

turret_t *update_turret(char *buf);
plane_t *update_plane(char *buf);
data_t *update_from_line(data_t *data, char *buf);
data_t *init_data(void);
data_t *read_file(char *filepath);

//includes for game_init.c

void init_game(data_t *data);

//includes for events.c

void check_event(window_t *window);

//includes for display_clock.c

void print_clock(window_t *window);
sfText *create_timer(void);
void manage_time(plane_t **planes, int is_sec);

//includes for sprite_setup.c

void set_sprites(data_t *data, window_t *window);
sfVector2f get_vector(plane_t *plane);

//includes for collisions.c

void display_sprites(window_t *window, data_t *data);
int is_finished(plane_t **planes);
void check_collisions(data_t *data);
void move_sprites(data_t *data);
int is_overlapping(sfVector2f cur, turret_t *turret);
void is_under_turret(data_t *data);

#endif /* !INCLUDE_FUNCTIONS_H_ */
