/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** verify_input
*/

#include "parsing.h"

int verify_input(char *str)
{
    str = remove_comment(str);
    if (str[0] == '\0')
        return 0;
    if (str[0] == '#')
        return 0;
    if (get_room_type(str) == -1)
        return 84;
    return 0;
}
