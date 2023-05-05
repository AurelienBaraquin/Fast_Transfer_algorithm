/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** free_path.c
*/

#include "path.h"

void free_path(path_t *path)
{
    step_t *current = path->steps;
    step_t *temp = current;

    while (current != NULL) {
        temp = current;
        current = current->prev;
        free(temp);
    }
    free(path);
}
