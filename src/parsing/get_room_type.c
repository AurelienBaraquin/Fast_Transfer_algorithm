/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** get_room_type
*/

#include "parsing.h"
#include "tools.h"

int get_room_type(char *str)
{
    int i = 0;
    int nb_space = 0;
    int nb_tiret = 0;

    while (str[i] != '\0') {
        nb_space = (str[i] == ' ') ? nb_space + 1 : nb_space;
        nb_tiret = (str[i] == '-') ? nb_tiret + 1 : nb_tiret;
        i++;
    }
    if (nb_space > 2 || nb_tiret > 1 || (nb_space > 0 && nb_tiret > 0))
        return (-1);
    if (nb_space == 2)
        return (1);
    if (nb_tiret == 1)
        return (2);
    return (0);
}

int get_upper_room(input_t **first_input)
{
    int upper = 0;
    input_t *tmp = *first_input;

    while (tmp != NULL) {
        if (get_room_type(tmp->str) == 1)
            upper++;
        tmp = tmp->next;
    }
    return (upper);
}
