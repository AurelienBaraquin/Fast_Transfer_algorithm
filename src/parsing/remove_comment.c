/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** remove_comment
*/

#include "parsing.h"
#include "tools.h"

char *remove_comment(char *str)
{
    int i = 0;
    if (my_strlen(str) > 1 && str[0] == '#' && str[1] == '#')
        i = 2;
    while (str[i] != '\0') {
        if (str[i] == '#')
            str[i] = '\0';
        i++;
    }
    while (str[my_strlen(str) - 1] == ' ' || str[my_strlen(str) - 1] == '\t')
        str[my_strlen(str) - 1] = '\0';
    return (str);
}
