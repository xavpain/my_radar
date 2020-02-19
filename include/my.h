/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** header
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *my_strdup(char const *src);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_itoa(int nb);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int check_if_same(char *str, char const *to_find, int count);
int my_show_word_array (char *const *tab);
int sign(char const *str);
char *addition(char *first_term, char *second_term);
char *soustraction(char *first_term, char *second_term);
char *multiplication(char *first_term, char *second_term);
char *division(char *first_term, char *second_term);
char *modulo(char *first_term, char *second_term);
char **my_str_to_word_array(char const *str);
int separator(char c);
char *add_sub(char *first_term, char *second_term, char operand);
char *priority(char *first_term, char *second_term, char operand);
int size_int(int nb);
int neg_check(int nb);
int absolute_value(int nb);
char *my_getchar(int nb);
int eval_expr(char const *str);
int my_is_num(char *str);
int sign(char const *str);
int count_sign(char *str);
char *clean_str(char *str);
char *longest_string(char **av);
char *smallest_string(char **av);
int rest(int sum);
char *infinadd(char *s1, char *s2);
void my_putstr_error(char const *str);
int my_is_num(char *str);
int check_arg(char **av);
int sign(char const *str);
int count_sign(char *str);
char *clean_str_sub(char *str);
char *longest_string_sub(char **av);
char *smallest_string_sub(char **av);
int rest(int sum);
char *subshort(char *shrt, char *lng);
char *same_size(char *s1, char *s2, char *res, int alloc_size);
char *infin_sub(char *str1, char *str2);
char *multiple_operation(char **number, char *operand);
char **put_result_in_tab(char **number, int i, char *result);
char *replace_ops(char *expr, char *ops);
char *eachloop(int opsloop, char *expr, char *ops);
